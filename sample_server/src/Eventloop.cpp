#include"Eventloop.h"
#include"Channel.h"
#include"Epolls.h"

  Eventloop::Eventloop():ep(nullptr),quit(false){
    ep = new Epolls();
    // tp = new ThreadPool();
  }
  Eventloop::~Eventloop(){
    delete ep;
  }
  void Eventloop::loop(){
    while (!quit) {
      std::vector<Channel*> chas = ep->polls();
      for(auto it = chas.begin();it != chas.end();++it){
        (*it)->handleEvent();
      }
    }
  }
  void Eventloop::updateChannels(Channel *cha){
    ep->updateChannels(cha);
  }
  // void Eventloop::addTask(std::function<void()> func){
  //   tp->addTask(func);
  // }
