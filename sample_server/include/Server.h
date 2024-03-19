#ifndef SERVER_H
#define SERVER_H
#include<map>
#include<vector>
class Accept;
class Eventloop;
class Sock;
class Connect;
class ThreadPool;
class Server{
  private:
    Eventloop* mainReactor; //主要负责接受连接，给subreactor分发连接
    Accept * act;//连接接收器
    std::map<int,Connect*> connects;//Tcp连接储存器
    std::vector<Eventloop*> sub_reactor;//负责时间循环
    ThreadPool * thpool; //线程池
  public:
    Server(Eventloop *);
    ~Server();
    void newConnect(Sock *);
    void handleReadEvent(int );
    void deleteConnect(int);
};

#endif
