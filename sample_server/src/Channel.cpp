#include"Eventloop.h"
#include"Channel.h"


// int fd;
//     Eventloop *elp;
// uint32_t event;
// uint32_t revent;
// bool intree;

Channel::Channel(int _fd,Eventloop * _elp):elp(_elp),fd(_fd),event(0),revent(0),intree(false){

}
Channel::~Channel(){

}
void Channel::setEvent(uint32_t _event){
  event = _event;
}
void Channel::setRevent(uint32_t _revent){
  revent = _revent;
}
void Channel::setIntree(bool _intree){
  intree = _intree;
}
uint32_t Channel::getEvent(){
  return event;
}
uint16_t Channel::getRevent(){
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
void Channel::setCallBackFun(std::function<void()> fun){
  callback = fun;
}
void Channel::handleEvent(){
  callback();
}
