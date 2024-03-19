#include"Sock.h"
#include"Inet_Addr.h"
#include"Accept.h"
#include"Channel.h"
#include<functional>
#include<cstdio>

//tcp连接类
Accept::Accept(Eventloop * _elp):elp(_elp){
  sockfd = new Sock();
  Inet_Addr *addr = new Inet_Addr("127.0.0.1",9091);
  sockfd->bind(addr);
  sockfd->listen();
  cha =new Channel(sockfd->getFd(),elp);
  cha->setReadCallBackFun(std::bind(&Accept::acceptConnect,this));
  cha->enableReading();
  delete addr;
}
Accept::~Accept(){
  delete cha;
  delete sockfd;
}
void Accept::setNewConnectCallBack(std::function<void(Sock*)> cb){
  newConnectCallBack = cb;
}
void Accept::acceptConnect(){
  Inet_Addr *clt_addr = new Inet_Addr();
  Sock* clt_sock = new Sock(sockfd->accept(clt_addr));
  clt_sock->setnonblocking();
  printf("new client fd:%d,IP:%s,Port:%d\n",clt_sock->getFd(),inet_ntoa(clt_addr->soaddr.sin_addr),ntohs(clt_addr->soaddr.sin_port));
  Channel * cha = new Channel(clt_sock->getFd(),elp);
  newConnectCallBack(clt_sock);
  delete clt_addr;
}
