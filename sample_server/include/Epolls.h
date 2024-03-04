#ifndef EPOLLCLASS_H
#define EPOLLCLASS_H
#include<sys/epoll.h>
#include<vector>
class Channel;
class Epolls{
  private:
    int efd;
    struct epoll_event* events;
  public:
    Epolls();
    ~Epolls();
    //添加event到event树中
    void addEpoll(const int,const uint32_t op);
    //更新channel数组
    void updateChannels(Channel*);
    //返回触发事件的channel数组
    std::vector<Channel*> polls(int timeout = -1);
};



#endif
