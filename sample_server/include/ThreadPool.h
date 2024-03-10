#ifndef THREADPOOL_H
#define THREADPOOL_H
#include<vector>
#include<queue>
#include<thread>
#include<mutex>
#include<functional>
#include<condition_variable>

class ThreadPool{
  private:
    std::vector<std::thread> threadPool;
    std::queue<std::function<void()>> tasks;
    std::mutex task_mtx;
    std::condition_variable cv;
    bool stop;
  public:
  ThreadPool(int = 10);
  ~ThreadPool();
  void addTask(std::function<void()>);
};

#endif
