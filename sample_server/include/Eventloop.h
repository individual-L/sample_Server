#ifndef EVENTLOOP_H
#define EVENTLOOP_H
#include"ThreadPool.h"
class Epolls;
class Channel;
class ThreadPool;
//事件循环类
class Eventloop{
  private:
    bool quit;
    Epolls *ep;
    ThreadPool* tp;
  public:
    Eventloop();
    ~Eventloop();
    void loop();
    void updateChannels(Channel *);
    void addTask(std::function<void()>);
};

#endif
