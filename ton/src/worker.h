#ifndef TON_WORKER_H_
#define TON_WORKER_H_

#include "common.h"

namespace ton {

class Worker {
  public:
    Worker();
    ~Worker();
  private:
    Status status;
}; //Worker

} //ton


#endif //TON_WORKER_H_

 
