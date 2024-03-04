#ifndef SOCKCLASS_H
#define SOCKCLASS_H
class Inet_Addr;
//socket类
class Sock{
  private:
  int sockfd;
  public:
  Sock();
  Sock(const int);
  ~Sock();
  //socket绑定一个地址信息
  void bind(const Inet_Addr*);
  //开始监听是否有请求
  void listen(const int);
  //获取客户端的地址信息
  int accept(Inet_Addr*);
  //设置socket为非阻塞IO
  void setnonblocking();
  //获取socket文件描述符
  int getFd();

};

#endif
