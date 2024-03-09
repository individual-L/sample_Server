#include"Buffer.h"
#include<string>
#include<limits>
#include<iostream>

Buffer::Buffer(){

}
Buffer::~Buffer(){

}
void Buffer::append(const char* _buf,ssize_t len){
  for(int i = 0;i < len;++i){
    if(_buf[i] == '\0'){
      break;
    }
    buf.push_back(_buf[i]);
  }
}
void Buffer::clear(){
  buf.clear();
}
const char* Buffer::c_str(){
  return buf.c_str();
}
ssize_t Buffer::size(){
  return buf.size();
}
void Buffer::getLine(){
  buf.clear();
  // std::cin.ignore(std::numeric_limits<std::streamsize>::max());
  std::getline(std::cin,buf);
}
