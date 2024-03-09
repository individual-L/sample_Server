#ifndef BUFFER_H
#define BUFFER_H
#include<string>
class Buffer{
  private:
  std::string buf;
  public:
  Buffer();
  ~Buffer();
  void append(const char* ,ssize_t );
  void clear();
  ssize_t size();
  const char* c_str();
  void getLine();
};


#endif
