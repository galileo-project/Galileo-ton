#ifndef TON_RUNNER_H_
#define TON_RUNNER_H_

#include "common.h"
#include "worker.h"

namespace ton {

class Runner {
  public:
    Runner();
    ~Runner();
    Status get_status();
    size_t get_workers();
    void launch();
    void dispatch(Worker*);
  private:
    Status status;
    size_t workers;

}; //Runner

} //ton

#endif // TON_RUNNER_H_
