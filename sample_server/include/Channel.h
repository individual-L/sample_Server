#ifndef CHANNELCLASS_H
#define CHANNELCLASS_H
#include<sys/epoll.h>
class Epolls;
class Channel{
  private:
    //epoll树
    Epolls *epls;
    //sockfd
    int fd;
    //监听事件
    uint32_t event;
    //触发事件
    uint32_t revent;
    //是否在epoll树中
    bool intree;
  public:
    Channel(int _fd,Epolls *);
    ~Channel();
    void setEvent(uint32_t _event);
    void setRevent(uint32_t _revent);
    void setIntree(bool _intree);
    uint32_t getEvent();
    uint16_t getRevent();
    bool getIntree();
    int getFd();
    
    void enableReading();

};
#endif
