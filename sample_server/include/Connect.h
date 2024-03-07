#ifndef CONNECT_H
#define CONNECT_H
#include<functional>
class Channel;
class Eventloop;
class Sock;
class Connect{
  private:
    Eventloop* elp;
    Channel * cha;
    Sock * sock;
    std::function<void(Sock*)> deleteConnectCallBack;
  public:
  Connect(Eventloop *_elp,Sock *_sock);
  ~Connect();

  void echo(int _fd);
  void setDeleteConnectCallBack(std::function<void(Sock*)>);
  void deleteCon();

};

#endif
