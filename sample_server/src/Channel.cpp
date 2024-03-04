#include"Epolls.h"
#include"Channel.h"


// int fd;
//     Epolls *epls;
// uint32_t event;
// uint32_t revent;
// bool intree;

Channel::Channel(int _fd,Epolls * _eps):epls(_eps),fd(_fd),event(0),revent(0),intree(false){

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
int Channel::getFd(){
  return fd;
}
void Channel::enableReading(){
  event = EPOLLIN | EPOLLET;
  epls->updateChannels(this);
}
