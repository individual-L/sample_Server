#ifndef ACCEPT_H
#define ACCEPT_H
#include<functional>
class Sock;
class Inet_Addr;
class Eventloop;
class Channel;
class Accept{
  private:
  Sock * sockfd;
  Inet_Addr* addr;
  Eventloop* elp;
  Channel * cha;
  std::function<void(Sock*)> newConnectCallBack;
  public:
  Accept(Eventloop *);
  ~Accept();
  void acceptConnect();
  void setNewConnectCallBack(std::function<void(Sock*)>);
};

#endif
