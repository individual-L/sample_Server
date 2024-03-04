#ifndef INETADDR_H
#define INETADDR_H
#include<arpa/inet.h>
//地址信息类
class Inet_Addr
{
public:
  struct sockaddr_in soaddr;
  socklen_t addr_len;
  Inet_Addr();
  Inet_Addr(const char* ,const uint16_t );
  ~Inet_Addr();
};


#endif
