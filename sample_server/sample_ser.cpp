#include<arpa/inet.h>
#include<sys/socket.h>
#include<string.h>
#include<stdio.h>
#include<unistd.h>
#define MAXCON 5
#define MAXBUF 1024

bool errif(bool cond,char* messg);

int main(){
//创建并初始化服务端和客户端的地址信息结构体  
struct sockaddr_in serv_addr,clt_addr;
socklen_t clt_addr_len = sizeof(clt_addr);
memset(&serv_addr,0,sizeof(serv_addr));
memset(&clt_addr,0,sizeof(clt_addr));
serv_addr.sin_family = AF_INET;
serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
serv_addr.sin_port = htons(8888);
//创建服务端socket
int sockfd = socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
//检测异常是否发生
errif(sockfd == -1,"socket create error!");
//将修改服务端sokect的地址信息，并检测异常
errif(bind(sockfd , (sockaddr*)&serv_addr , sizeof(serv_addr)) == -1,"bind error!");
//监听是否有连接请求
errif(listen(sockfd,SOMAXCONN) == -1,"listen error!");
//接受客户端的地址结构体
int clt_sockfd = accept(sockfd,(sockaddr*)&clt_addr,&clt_addr_len);
errif(clt_sockfd == -1,"accept create error!");

while (true) {
  char buf[1024];     //定义缓冲区
  bzero(&buf, sizeof(buf));       //清空缓冲区
  //从客户端socket读到缓冲区，返回已读数据大小
  ssize_t read_bytes = read(clnt_sockfd, buf, sizeof(buf)); 
  if(read_bytes > 0){
      printf("message from client fd %d: %s\n", clnt_sockfd, buf);  
      write(clnt_sockfd, buf, sizeof(buf));           //将相同的数据写回到客户端
  } else if(read_bytes == 0){             //read返回0，表示EOF
      printf("client fd %d disconnected\n", clnt_sockfd);
      close(clnt_sockfd);
      break;
  } else if(read_bytes == -1){        //read返回-1，表示发生错误，按照上文方法进行错误处理
      close(clnt_sockfd);
      errif(true, "socket read error");
  }
}
}

bool errif(bool cond,char* messg){
  if(cond){
    perror("%s",messg);
    exit(EXIT_FAILURE);
  }
}
