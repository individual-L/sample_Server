#include"ThreadPool.h"
#include<iostream>
ThreadPool::ThreadPool(int size):stop(false){
  //设置线程数量
  for(int i = 0;i<size;++i){
    //为每个线程设置函数
    threadPool.emplace_back(std::thread([this](){
      while(true){
        std::function<void()> task;
        //在作用域上对mutex加锁,离开作用域后锁会自动解锁，不需要调用unlock
        {
          std::unique_lock<std::mutex> lock(task_mtx);
          cv.wait(lock,[this](){
            return stop || !tasks.empty();
          });
          //任务队列为空并且线程池停止,则退出线程
          if(stop && tasks.empty()){
            return;
          }
          //从任务队列中获取一个任务
          task = tasks.front();
          tasks.pop();
        }
        task();
      }
    }));

  }
}
ThreadPool::~ThreadPool(){
  {
    std::unique_lock<std::mutex> lock(task_mtx);
    stop = true;
  }
  cv.notify_all();
  for(std::thread &th : threadPool){
    if(th.joinable()){
      th.join();
    }
  }

}
void ThreadPool::addTask(std::function<void()> func){
  //在这个作用域对std::mutex进行加锁，离开作用域会自动解锁
  {
    std::unique_lock<std::mutex> lock(task_mtx);
    if(stop){
      throw std::runtime_error("ThreadPool already stop,can't add task any more");
    }
    //通知一次条件变量
    tasks.emplace(func);
  }
  std::cout<<"one notice......"<<std::endl;
  cv.notify_one();
}
