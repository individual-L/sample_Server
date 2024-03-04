#ifndef EPOLLCLASS
#define EPOLLCLASS
#include"Epolls.h"
#include"util.h"
#include<unistd.h>
#include<string.h>
#include<vector>
#define MAXEVE 1000
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
std::vector<epoll_event> Epolls::polls(int timeout){
  std::vector<epoll_event> epls;
  int nfd = epoll_wait(efd,events,MAXEVE,timeout);
  errif(nfd == -1,"epoll_wait create error!");
  for(int i = 0;i<nfd ;++i){
    epls.push_back(events[i]);
  }
  return epls;
}

#endif

