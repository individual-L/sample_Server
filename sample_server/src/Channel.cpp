#include"Eventloop.h"
#include"Channel.h"
#include<unistd.h>


// int fd;
//     Eventloop *elp;
// uint32_t event;
// uint32_t revent;
// bool intree;

Channel::Channel(int _fd,Eventloop * _elp):elp(_elp),useThreadpool(true),fd(_fd),event(0),revent(0),intree(false){

}
Channel::~Channel(){
  if(fd != -1){
    close(fd);
    fd = -1;
  }
}
void Channel::setEvent(uint32_t _event){
  event = _event;
}
void Channel::setRevent(uint32_t _revent){
  revent = _revent;
}
uint32_t Channel::getEvent(){
  return event;
}
uint32_t Channel::getRevent(){
  return revent;
}
bool Channel::getIntree(){
  return intree;
}
void Channel::setIntree(){
  intree = true;
}
int Channel::getFd(){
  return fd;
}
void Channel::enableReading(){
  event = EPOLLIN | EPOLLET;
  elp->updateChannels(this);
}
void Channel::setET(){
  event |= EPOLLET;
  elp->updateChannels(this);
}
void Channel::setReadCallBackFun(std::function<void()> fun){
  readCallback = fun;
}
void Channel::setWriteCallBackFun(std::function<void()> fun){
  writeCallback = fun;
}
void Channel::handleEvent(){
  if(revent &(EPOLLIN | EPOLLPRI)){
    if(useThreadpool){
      elp->addTask(readCallback);
    }else{
      readCallback();
    }
  }else if(revent & EPOLLOUT){
    if(useThreadpool){
      elp->addTask(writeCallback);
    }else{
      writeCallback();
    }
  }

}
void Channel::setUseThreadPool(bool bl){
  useThreadpool = bl;
}
