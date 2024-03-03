#ifndef INETADDR
#define INETADDR
#include"Inet_Addr.h"
#include<string.h>
Inet_Addr::Inet_Addr():addr_len(sizeof(soaddr)){
  memset(&soaddr,0,sizeof(soaddr));
}
Inet_Addr::Inet_Addr(const char* ip,const uint16_t port):sock_len(sizeof(soaddr)){
  memset(&soaddr,0,sizeof(soaddr));
  soaddr.sin_family = AF_INET;
  soaddr.sin_addr.s_addr = inet_addr(ip);
  soaddr.sin_port = htons(port);
  sock_len = sizeof(soaddr);
}
Inet_Addr::~Inet_Addr(){
  
}


#endif
