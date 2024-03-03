#ifndef EPOLLCLASS_H
#define EPOLLCLASS_H
#include<sys/epoll.h>
class Epolls{
  private:
    int efd;
    struct epoll_event* events;
  public:
    Epolls();
    ~Epolls();
    //添加event到event树中
    void addEpoll(const int,const uint16_t op);
    //返回触发事件的sockfd数组
    std::vector<epoll_event> polls(int timeout == -1);
};



#endif
