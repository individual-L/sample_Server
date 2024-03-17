#ifndef CONNECT_H
#define CONNECT_H
#include<functional>
class Channel;
class Eventloop;
class Sock;
class Buffer;
class Connect{
  private:
    Eventloop* elp;
    Channel * cha;
    Sock * sock;
    Buffer* readBuffer;
    std::function<void(int)> deleteConnectCallBack;
  public:
  Connect(Eventloop *_elp,Sock *_sock);
  ~Connect();

  void echo(int _fd);
  void setDeleteConnectCallBack(std::function<void(int)>);
  void deleteCon();

};

#endif
