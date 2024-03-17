#ifndef THREADPOOL_H
#define THREADPOOL_H
#include<vector>
#include<queue>
#include<thread>
#include<mutex>
#include<functional>
#include<condition_variable>
#include<future>

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
  // void addTask(std::function<void()>);
  template<typename F,typename ... Args>
  auto addTask(F&& f,Args&& ... args)->std::future<typename std::result_of<F(Args...)>::type>;
};
//C++编译器不支持模板的分离编译
template<typename F,typename ... Args>
auto ThreadPool::addTask(F&& f,Args&&... args)->std::future<typename std::result_of<F(Args...)>::type>{
  //函数返回值类型
  using result_type = typename std::result_of<F(Args...)>::type;
  //将函数封装成期物
  //std::shared_ptr< std::packaged_task<result_type()> >
  auto task = std::make_shared< std::packaged_task<result_type()> >(
    //完美转发参数
    std::bind(std::forward<F>(f),std::forward<Args>(args)...)
  );
  std::future<result_type> fur = task->get_future();
  {
    std::unique_lock<std::mutex> lock(task_mtx);
    if(stop){
      throw std::runtime_error("ThreadPool already stop,can't add task any more");
    }
    //通知一次条件变量
    tasks.emplace([task](){(*task)();});
  }
  cv.notify_one();
  return fur;
}

#endif
