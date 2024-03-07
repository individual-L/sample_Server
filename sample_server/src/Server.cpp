#include"Server.h"
#include"Sock.h"
#include"Channel.h"
#include<functional>
#include"Accept.h"
#include"Connect.h"
#define MAXCON 100

Server::Server(Eventloop * _elp):elp(_elp),act(nullptr){
  act = new Accept(elp);
  act->setNewConnectCallBack(std::bind(&Server::newConnect,this,std::placeholders::_1));

}
Server::~Server(){
  delete act;
}
void Server::newConnect(Sock * sock){
  Connect *cet = new Connect(elp,sock);
  std::function<void(Sock*)> cb = std::bind(&Server::deleteConnect,this,std::placeholders::_1);
  cet->setDeleteConnectCallBack(cb);
  connects[sock->getFd()] = cet;
}
void Server::deleteConnect(Sock *sock){
  Connect *cet = connects[sock->getFd()];
  connects.erase(sock->getFd());
  delete cet;
}
