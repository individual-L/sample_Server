#include<arpa/inet.h>
#include<sys/socket.h>
#include<string.h>
#include<stdio.h>
#define MAXCON 5

int main(){
  
struct sockaddr_in serv_addr,clt_addr;
socklen_t clt_addr_len = sizeof(clt_addr);
memset(&serv_addr,0,sizeof(serv_addr));
memset(&clt_addr,0,sizeof(clt_addr));
serv_addr.sin_family = AF_INET;
serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
serv_addr.sin_port = htons(8888);

int sockfd = socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
bind(sockfd , (sockaddr*)&serv_addr , sizeof(serv_addr));
listen(sockfd,SOMAXCONN);
int clt_sockfd = accept(sockfd,(sockaddr*)&clt_addr,&clt_addr_len);
printf("new client fd %d! IP: %s Port: %d \n",clt_sockfd,inet_ntoa(clt_addr.sin_addr),ntohs(clt_addr.sin_port));

}
