#include"Server.h"
#include"Sock.h"
#include"Inet_Addr.h"
#include"Channel.h"
#include<string.h>
#include<functional>
#include<stdio.h>
#include<unistd.h>
#include<errno.h>
#define MAXCON 100
#define MAXBUF 1024

Server::Server(Eventloop * _elp):elp(_elp){
  Sock* sock = new Sock();
  Inet_Addr* addr = new Inet_Addr("127.0.0.1",9091);
  sock->bind(addr);
  sock->listen(MAXCON);
  sock->setnonblocking();

  Channel * cha = new Channel(sock->getFd(),elp);
  std::function<void()> cb = std::bind(&Server::newConnect,this,sock);
  cha->setCallBackFun(cb);
  cha->enableReading();
}
Server::~Server(){

}
void Server::handleReadEvent(int fd){
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
void Server::newConnect(Sock * serv_sock){
  Inet_Addr *clt_addr = new Inet_Addr();
  Sock* clt_sock = new Sock(serv_sock->accept(clt_addr));
  clt_sock->setnonblocking();
  printf("new client fd:%d,IP:%s,Port:%d\n",clt_sock->getFd(),inet_ntoa(clt_addr->soaddr.sin_addr),ntohs(clt_addr->soaddr.sin_port));
  Channel * cha = new Channel(clt_sock->getFd(),elp);
  cha->setCallBackFun(std::bind(&Server::handleReadEvent,this,clt_sock->getFd()));
  cha->enableReading();
}
