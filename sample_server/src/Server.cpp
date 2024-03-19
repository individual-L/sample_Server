#include"Server.h"
#include"Sock.h"
#include"Channel.h"
#include<functional>
#include"Accept.h"
#include"Connect.h"
#include<unistd.h>
#include"ThreadPool.h"
#include"Eventloop.h"
#define MAXCON 100

Server::Server(Eventloop * _elp):mainReactor(_elp),act(nullptr){
  act = new Accept(mainReactor);//act有且只由mainReactor负责监听
  act->setNewConnectCallBack(std::bind(&Server::newConnect,this,std::placeholders::_1));

  int size = std::thread::hardware_concurrency();//线程个数
  thpool = new ThreadPool(size);//创建线程池
  for(int i = 0; i < size; ++i){
    sub_reactor.emplace_back(new Eventloop());
  }
  //每个线程负责一个事件循环
  for(int i = 0; i < size; ++i){
    std::function<void()> sub_loop = std::bind(&Eventloop::loop,sub_reactor[i]);
    thpool->addTask(sub_loop);
  }

}
Server::~Server(){
  delete act;
}
void Server::newConnect(Sock * sock){
  if(sock->getFd() != -1){
    int radom = sock->getFd()%sub_reactor.size();
    Connect *cet = new Connect(sub_reactor[radom],sock);
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
