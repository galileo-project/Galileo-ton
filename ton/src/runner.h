#ifndef TON_RUNNER_H_
#define TON_RUNNER_H_

#include "common.h"
#include "worker.h"

namespace ton {

class Runner {
  public:
    Status status;

    Runner();
    ~Runner();
    Status get_status();
    size_t get_workers();
    void run();
    void dispatch(Worker*);
  private:
    size_t _workers;

}; //Runner

} //ton

#endif // TON_RUNNER_H_
