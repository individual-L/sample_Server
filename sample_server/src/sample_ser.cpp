#include"Server.h"
#include"Eventloop.h"



int main(){
  //初始化事件数组和事件循环
  Eventloop *elp = new Eventloop();
  //初始化服务器socket，并绑定到channel上，设置需要监听的事件类型和事件处理函数，最后更新事件数组
  Server *serv = new Server(elp);
  //开始监听事件数组
  elp->loop();
  
  return 0;
}
