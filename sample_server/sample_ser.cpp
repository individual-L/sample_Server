#include<arpa/inet.h>
#include<sys/socket.h>
#include<string.h>
#include<stdlib.h>
#include<sys/epoll.h>
#include<stdio.h>
#include<unistd.h>
#include<errno.h>
#include<fcntl.h>
#define MAXCON 5
#define MAXBUF 1024
#define MAXEVE 100

void errif(bool cond,const char* messg);
//设置为非阻塞IO
void setnonblocking(int fd);

int main(){
  //创建并初始化服务端和客户端的地址信息结构体  
  struct sockaddr_in serv_addr;
  memset(&serv_addr,0,sizeof(serv_addr));
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
  serv_addr.sin_port = htons(8888);
  //创建服务端socket
  int sockfd = socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
  //检测异常是否发生
  errif(sockfd == -1,"socket create error!");
  //将修改服务端sokect的地址信息，并检测异常
  errif(bind(sockfd , (sockaddr*)&serv_addr , sizeof(serv_addr)) == -1,"bind error!");
  //监听是否有连接请求
  errif(listen(sockfd,SOMAXCONN) == -1,"listen error!");

  int epfd = epoll_create1(0);
  //创建epoll结构体数组
  struct epoll_event events[MAXEVE],ev;
  ev.events = EPOLLIN;
  //这个IO为服务器端sock fd
  ev.data.fd = sockfd;
  //将服务器sock fd添加到epoll数组中
  epoll_ctl(epfd,EPOLL_CTL_ADD,sockfd,&ev);

  while (true) {
    //监听事件响应
    int nfds = epoll_wait(epfd,events,MAXEVE,-1);
    errif(nfds == -1,"epoll waite error!");
    for(int i = 3;i < nfds;++i){
      //检测发生事件的是否是服务器端sock
      if(events[i].data.fd == sockfd){
        //新客服端连接
        struct sockaddr_in clt_addr;
        socklen_t clt_addr_len = sizeof(clt_addr);
        memset(&clt_addr,0,sizeof(clt_addr));

        int clt_sockfd = accept(events[i].data.fd,(sockaddr*)&clt_addr,&clt_addr_len);
        errif(clt_sockfd == -1,"accept create error!");
        printf("new client fd:%d,IP:%s,Port:%d\n",clt_sockfd,inet.ntoa(clt_addr.sin_addr),ntohs(clt_addr.sin_port));

        memset(&ev,0,sizeof(ev));
        ev.data.fd = clt_sockfd;
        ev.events = EPOLLIN |EPOLLET;
        setnonblocking(clt_sockfd);
        epoll_ctl(epfd,EPOLL_CTL_ADD,clt_sockfd,&ev);
      //可读事件
      }else if(events[i].events & EPOLLIN){
        char buf[MAXBUF];     //定义缓冲区
        while(true){//由于是非阻塞IO，每次循环读取MAXBUF大小的数据，知道全部读完
          memset(&buf, 0,sizeof(buf));       //清空缓冲区
          ssize_t read_bytes = read(events[i].data.fd, buf, sizeof(buf));
          if(read_bytes > 0){
              printf("message from client fd %d: %s\n", events[i].data.fd, buf);  
              //将相同的数据写回到客户端
              write(events[i].data.fd, buf, sizeof(buf));
            } else if(read_bytes == -1 && errno == EINTR ){//可能由于信号中断，继续读取
              printf("read continue...");
              continue;
            } else if(read_bytes == -1 && (errno == EAGAIN || errno == EWOULDBLOCK) ){        //非阻塞IO，表示缓冲区的数据读取完毕
                printf("finish reading, error:%d",errno);
                break;
            }else if(read_bytes == 0){//表示EOF，客户端断开
              printf("EOF,client sock %d disconnected",events[i].data.fd);
              close(events[i].data.fd);//关闭socket会自动从epoll树上删除
              break;
            }
        }
      }else{
        printf("something else happended!");
      }
    }
  }
  close(sockfd);
  return 0;
}

void errif(bool cond,const char* messg){
  if(cond){
    perror(messg);
    exit(EXIT_FAILURE);
  }
}
void setnonblocking(int fd){
  fcntl(fd,F_SETFL,fcntl(fd,F_GETFL) | O_NONBLOCK);
}
