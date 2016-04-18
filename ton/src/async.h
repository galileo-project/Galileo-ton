#ifndef TON_ASYNC_H_
#define TON_ASYNC_H_

#include <pthread>

namespace ton {
    
typedef void *async_f(void*);
    
class Async {
  public:
    Async();
    ~Async();
    int run(async_f*, void*);
  private:
    std::vector<pthread_t> _pids;
    pthread_mutex_t _lock;
};
    
}

#endif //TON_ASYNC_H_
