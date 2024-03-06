#ifndef SOCKCLASS
#define SOCKCLASS
#include<arpa/inet.h>
#include<sys/socket.h>
#include<fcntl.h>
#include<iostream>
#include<unistd.h>
#include"Sock.h"
#include"Inet_Addr.h"
#include"util.h"
Sock::Sock():sockfd(-1){
  sockfd = socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
  errif(sockfd == -1,"sock create error!");
}
Sock::Sock(const int _fd):sockfd(_fd){
  errif(sockfd == -1,"sock create error!");
}
Sock::~Sock(){
  if(sockfd != -1){
    close(sockfd);
    sockfd = -1;
  }
}
void Sock::bind(const Inet_Addr* iaddr){
  errif(::bind(sockfd,(sockaddr*)&(iaddr->soaddr),iaddr->addr_len) == -1,"bind create error!");
}
void Sock::listen(){
  errif(::listen(sockfd,SOMAXCONN) == -1,"listen create error!");
}
int Sock::accept(Inet_Addr * clt_addr){
  int clt_fd = ::accept(sockfd,(sockaddr*)&(clt_addr->soaddr),&(clt_addr->addr_len));
  errif(clt_fd == -1,"accept create error!");
  return clt_fd;
}
void Sock::setnonblocking(){
  fcntl(sockfd,F_SETFL,fcntl(sockfd,F_GETFL)| O_NONBLOCK);
}

int Sock::getFd(){
  return sockfd;
}




#endif
