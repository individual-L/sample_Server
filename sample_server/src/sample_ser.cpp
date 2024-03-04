#include<stdio.h>
#include<unistd.h>
#include<errno.h>
#include"Inet_Addr.h"
#include"Sock.h"
#include<string.h>
#include"Epolls.h"
#include<vector>
#define MAXCON 5
#define MAXBUF 1024
#define MAXEVE 100

void handleReadEvent(int fd);

int main(){
  //初始化服务端和客户端的地址信息类  
  Inet_Addr* ser_addr = new Inet_Addr("127.0.0.1",9091);
  //创建服务端socket
  Sock *sockfd = new Sock();
  //将修改服务端sokect的地址信息
  sockfd->bind(ser_addr);
  //这个IO为服务器端sock fd
  sockfd->setnonblocking();
  //监听是否有连接请求
  sockfd->listen(10);
  //创建epoll结构体数组
  Epolls *vcr_ep = new Epolls();
  //将服务器sock fd添加到epoll数组中
  vcr_ep->addEpoll(sockfd->getFd(),EPOLLIN | EPOLLET);
  while (true) {
    //监听事件响应
    std::vector<epoll_event> nfds = vcr_ep->polls();
    for(int i = 0;i < nfds.size();++i){
      //检测发生事件的是否是服务器端sock
      if(nfds[i].data.fd == sockfd->getFd()){
        //新客户端连接
        Inet_Addr* clt_addr = new Inet_Addr();
        Sock* clt_sockfd = new Sock(sockfd->accept(clt_addr));
        clt_sockfd->setnonblocking();

        printf("new client fd:%d,IP:%s,Port:%d\n",clt_sockfd->getFd(),inet_ntoa(clt_addr->soaddr.sin_addr),ntohs(clt_addr->soaddr.sin_port));

        vcr_ep->addEpoll(clt_sockfd->getFd(),EPOLLIN | EPOLLET);
      //可读事件
      }else if(nfds[i].events & EPOLLIN){
	handleReadEvent(nfds[i].data.fd);
      }else{
        printf("something else happended!");
      }
    }
  }
  close(sockfd->getFd());
  return 0;
}

void handleReadEvent(int fd){
    char buf[MAXBUF];     //定义缓冲区
    while(true){//由于是非阻塞IO，每次循环读取MAXBUF大小的数据，知道全部读完
      memset(&buf, 0,sizeof(buf));       //清空缓冲区
      ssize_t read_bytes = read(fd, buf, sizeof(buf));
      if(read_bytes > 0){
          printf("message from client fd %d: %s\n", fd, buf);  
          //将相同的数据写回到客户端
          write(fd, buf, sizeof(buf));
        } else if(read_bytes == -1 && errno == EINTR ){//可能由于信号中断，继续读取
          printf("read continue...");
          continue;
        } else if(read_bytes == -1 && (errno == EAGAIN || errno == EWOULDBLOCK) ){        //非阻塞IO，表示缓冲区的数据读取完毕
            printf("finish reading, error:%d",errno);
            break;
        }else if(read_bytes == 0){//表示EOF，客户端断开
          printf("EOF,client sock %d disconnected",fd);
          close(fd);//关闭socket会自动从epoll树上删除
          break;
        }
    }
}

