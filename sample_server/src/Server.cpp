#include"Server.h"
#include"Sock.h"
#include"Channel.h"
#include<functional>
#include"Accept.h"
#include"Connect.h"
#include<unistd.h>
#define MAXCON 100

Server::Server(Eventloop * _elp):elp(_elp),act(nullptr){
  act = new Accept(elp);
  act->setNewConnectCallBack(std::bind(&Server::newConnect,this,std::placeholders::_1));

}
Server::~Server(){
  delete act;
}
void Server::newConnect(Sock * sock){
  if(sock->getFd() != -1){
    Connect *cet = new Connect(elp,sock);
    std::function<void(int)> cb = std::bind(&Server::deleteConnect,this,std::placeholders::_1);
    cet->setDeleteConnectCallBack(cb);
    connects[sock->getFd()] = cet;
  }

}
void Server::deleteConnect(int sock){
  if(sock != -1){
    auto it = connects.find(sock);
    if(it != connects.end()){
      Connect *cet = connects[sock];
      connects.erase(sock);
      delete cet;
    }
  }
}
