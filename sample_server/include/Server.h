#ifndef SERVER_H
#define SERVER_H
#include<map>
class Accept;
class Eventloop;
class Sock;
class Connect;
class Server{
  private:
    Eventloop* elp; 
    Accept * act;
    std::map<int,Connect*> connects;
  public:
    Server(Eventloop *);
    ~Server();
    void newConnect(Sock *);
    void handleReadEvent(int );
    void deleteConnect(int);
};

#endif
