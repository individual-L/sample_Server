#include<sys/socket.h>
#include<arpa/inet.h>
#include<string.h>
#include<stdio.h>
#include"Sock.h"
#include<unistd.h>
#include<cerrno>
#include"Inet_Addr.h"
#include"util.h"
#include<iostream>
#include"Buffer.h"
#define MAXBUF 1024


int main(){
//创建并初始化地址结构体
Inet_Addr* ser_addr = new Inet_Addr("127.0.0.1",9091);
//创建sokect
Sock* sockfd = new Sock();
//与服务端进行连接
sockfd->connect(ser_addr);
sockfd->setnonblocking();
Buffer* readBuffer =new Buffer();
Buffer* writeBuffer =new Buffer();

while(true){
  writeBuffer->getLine();
  ssize_t write_bytes = write(sockfd->getFd(),writeBuffer->c_str(),writeBuffer->size());
  if(write_bytes == -1){
    printf("socket already disconnected, can't write any more!\n");
    break;
  }
  //创建并初始化缓冲区
  int read_bytes = 0;
  char buf[MAXBUF];
  while(true){
    memset(&buf,0,sizeof(buf));
    //接受服务端发过来的数据，并返回数据大小
    ssize_t buf_len = read(sockfd->getFd(),buf,MAXBUF);
    if(buf_len > 0){
      readBuffer->append(buf,buf_len);
      read_bytes += buf_len;
    //read返回0，表示EOF，通常是服务器端断开连接了
    }else if(buf_len == 0){
      printf("server socket disconnected!\n");
      exit(EXIT_SUCCESS);
    }else if(read_bytes >= writeBuffer->size()){
      printf("message from server:%s\n",readBuffer->c_str());
      read_bytes -= readBuffer->size();
      readBuffer->clear();
      break;
    }
  }
}
delete sockfd;
delete ser_addr;
return 1;
}
