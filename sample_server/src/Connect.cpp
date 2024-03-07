#include"Connect.h"
#include"Channel.h"
#include"Sock.h"
#include<functional>
#include<string.h>
#include<unistd.h>
#include<cstdio>
#include<cerrno>

#define MAXBUF 1024


Connect::Connect(Eventloop *_elp,Sock *_sock):elp(_elp),sock(_sock),cha(nullptr){
  cha = new Channel(sock->getFd(),elp);
  std::function<void()> cb = std::bind(&Connect::echo,this,sock->getFd());
  cha->setCallBackFun(cb);
  cha->enableReading();
}
Connect::~Connect(){
  delete sock;
}

void Connect::echo(int fd){
  char buf[MAXBUF];     //定义缓冲区
  while(true){//由于是非阻塞IO，每次循环读取MAXBUF大小的数据，知道全部读完
    memset(&buf, 0,sizeof(buf));       //清空缓冲区
    ssize_t read_bytes = read(fd, buf, sizeof(buf));
    if(read_bytes > 0){
        printf("message from client fd %d: %s\n", fd, buf);  
        //将相同的数据写回到客户端
        write(fd, buf, sizeof(buf));
      } else if(read_bytes == -1 && errno == EINTR ){//可能由于信号中断，继续读取
        printf("read continue...\n");
        continue;
      } else if(read_bytes == -1 && (errno == EAGAIN || errno == EWOULDBLOCK) ){        //非阻塞IO，表示缓冲区的数据读取完毕
          printf("finish reading, error:%d\n",errno);
          break;
      }else if(read_bytes == 0){//表示EOF，客户端断开
        printf("EOF,client sock %d disconnected\n",fd);
        close(fd);//关闭socket会自动从epoll树上删除
        break;
      }
  }
}
void Connect::setDeleteConnectCallBack(std::function<void(Sock*)> cb){
  deleteConnectCallBack = cb;
}
void Connect::deleteCon(){
  deleteConnectCallBack(sock);
}
