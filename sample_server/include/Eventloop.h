#ifndef EVENTLOOP_H
#define EVENTLOOP_H

class Epolls;
class Channel;
//事件循环类
class Eventloop{
  private:
    bool quit;
    Epolls *ep;
  public:
    Eventloop();
    ~Eventloop();
    void loop();
    void updateChannels(Channel *);
    

};

#endif
