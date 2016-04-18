#ifndef TON_RUNNER_H_
#define TON_RUNNER_H_

#include "common.h"
#include <vector>
#include <pthread.h>

namespace ton {
  
class Worker;
class Async;

class Runner {
  public:
    status_t status;
    size_t   workers;

    Runner();
    void run();
    void dispatch(const Worker&);
    Async *async();
  private:
    std::vector<Worker> _workers;
    Async               *_async;
}; //Runner

} //ton

#endif // TON_RUNNER_H_
