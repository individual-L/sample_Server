#ifndef SERVER_H
#define SERVER_H

class Eventloop;
class Sock;
class Server{
  private:
    Eventloop* elp; 
  public:
    Server(Eventloop *);
    ~Server();
    void newConnect(Sock *);
    void handleReadEvent(int );
};

#endif
