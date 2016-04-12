#ifndef TON_RUNNER_H_
#define TON_RUNNER_H_

#include "common.h"
#include "worker.h"
#include <vector>

namespace ton {

class Runner {
  public:
    Status status;
    size_t workers;

    Runner();
    void run();
    void dispatch(const Worker&);
  private:
    std::vector<Worker> _workers;
}; //Runner

} //ton

#endif // TON_RUNNER_H_
