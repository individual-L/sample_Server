#ifndef EPOLLCLASS
#define EPOLLCLASS
#include"Epolls.h"
#include"util.h"
#include"Channel.h"
#include<unistd.h>
#include<string.h>
#include<vector>
#include<sys/epoll.h>
#define MAXEVE 1000

// int efd;
// struct epoll_event* events;


Epolls::Epolls(){
  efd = epoll_create1(0);
  errif(efd == -1,"epoll create1 error!");
  events = new epoll_event[MAXEVE];
  memset(events,0,sizeof(*events)*MAXEVE);
}
Epolls::~Epolls(){
  if(efd != -1){
    close(efd);
    efd = -1;
  }
  delete [] events;
}
void Epolls::addEpoll(const int _fd,const uint32_t op ){
  struct epoll_event ev;
  memset(&ev,0,sizeof(ev));
  ev.events = op;
  ev.data.fd = _fd;
  errif(epoll_ctl(efd,EPOLL_CTL_ADD,_fd,&ev) == -1,"epoll_add create error!");
}
std::vector<Channel*> Epolls::polls(int timeout){
  std::vector<Channel*> chas;
  memset(&chas,0,sizeof(chas)*chas.size());
  int nfd = epoll_wait(efd,events,MAXEVE,timeout);
  errif(nfd == -1,"epoll_wait create error!");
  for(int i = 0;i<nfd ;++i){
    Channel* cha = (Channel*)events[i].data.ptr;
    cha->setRevent(events[i].events);
    chas.push_back(cha);
  }
  return chas;
}
void Epolls::updateChannels(Channel* cha){
  //在epoll树中
  // int fd = cha.getFd();
  struct epoll_event ev;
  memset(&ev,0,sizeof(ev));
  ev.data.ptr = cha;
  ev.events = cha->getEvent();
  if(cha->getIntree()){
    errif(epoll_ctl(efd,EPOLL_CTL_MOD,cha->getFd(),&ev) == -1,"epoll mod create error!\n");
  //不在epoll树中
  }else{
    errif(epoll_ctl(efd,EPOLL_CTL_ADD,cha->getFd(),&ev) == -1,"epoll add create error!\n");
    cha->setIntree();
  }
}

#endif
