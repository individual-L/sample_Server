#include<sys/socket.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#define MAXBUF 1024

//错误处理函数
void errif(bool cond,const char* messg);

int main(){
//创建并初始化地址结构体
struct sockaddr_in serv_addr;
memset(&serv_addr,0, sizeof(serv_addr));
serv_addr.sin_family = AF_INET;
serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
serv_addr.sin_port = htons(8888);
//创建sokect
int sockfd = socket(AF_INET, SOCK_STREAM, 0);
//与服务端进行连接
errif(connect(sockfd, (sockaddr*)&serv_addr, sizeof(serv_addr)) == -1,"connect error!");  

while(true){
  //创建并初始化缓冲区
  char buf[MAXBUF];
  memset(&buf,0,sizeof(buf));
  //从键盘输入信息到缓冲区
  scanf("%s",buf);
  if(strcmp(buf,"Q") == 0){
  	break;
  }
  //将缓冲区的信息发送到服务端，并返回数据大小
  ssize_t tmp = write(sockfd,buf,sizeof(buf));
  //检测是否发生异常
  errif(tmp == -1,"write create error!");
  //清空缓冲区，用来接收服务端发送过来的数据
  memset(&buf,0,sizeof(buf));
  //接受服务端发过来的数据，并返回数据大小
  ssize_t buf_len = read(sockfd,buf,MAXBUF);
  if(buf_len > 0){
    printf("message from server:%s\n",buf);
  //read返回0，表示EOF，通常是服务器端断开连接了
  }else if(buf_len == 0){
    printf("server socket disconnected!\n");
    break;
  //read返回-1，表示发生错误
  }else if(buf_len == -1){
    close(sockfd);
    errif(true,"read create error!");
  }
}


}


void errif(bool cond,const char* messg){
  if(cond){
    perror(messg);
    exit(EXIT_FAILURE);
  }
}
