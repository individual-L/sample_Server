#ifndef SERVER_H
#define SERVER_H
class Accept;
class Eventloop;
class Sock;
class Server{
  private:
    Eventloop* elp; 
    Accept * act;
  public:
    Server(Eventloop *);
    ~Server();
    void newConnect(Sock *);
    void handleReadEvent(int );
    void newAccept();
};

#endif
