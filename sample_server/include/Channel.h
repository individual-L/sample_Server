#ifndef CHANNELCLASS_H
#define CHANNELCLASS_H
#include<sys/epoll.h>
#include<functional>
class Eventloop;
class Channel{
  private:
    //epoll树
    Eventloop *elp;
    //sockfd
    int fd;
    //监听事件
    uint32_t event;
    //触发事件
    uint32_t revent;
    //是否在epoll树中
    bool intree;
    //设置回调函数
    std::function<void()> callback;
  public:
    Channel(int _fd,Eventloop *);
    ~Channel();
    void setEvent(uint32_t _event);
    void setRevent(uint32_t _revent);
    void setIntree(bool _intree);
    void setIntree();
    uint32_t getEvent();
    uint16_t getRevent();
    bool getIntree();
    int getFd();
    
    void enableReading();
    void setCallBackFun(std::function<void()>);
    void handleEvent();

};
#endif
