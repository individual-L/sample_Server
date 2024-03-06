#include"Sock.h"
#include"Inet_Addr.h"
#include"Accept.h"
#include"Channel.h"
#include<functional>

//tcp连接类
Accept::Accept(Eventloop * _elp):elp(_elp){
  sockfd = new Sock();
  addr = new Inet_Addr("127.0.0.1",9091);
  sockfd->bind(addr);
  sockfd->listen();
  sockfd->setnonblocking();

  cha =new Channel(sockfd->getFd(),elp);
  cha->setCallBackFun(std::bind(&Accept::acceptConnect,this));
  cha->enableReading();
}
Accept::~Accept(){
  delete cha;
  delete sockfd;
  delete addr;
}
void Accept::setNewConnectCallBack(std::function<void(Sock*)> cb){
  newConnectCallBack = cb;
}
void Accept::acceptConnect(){
  newConnectCallBack(sockfd);
}
