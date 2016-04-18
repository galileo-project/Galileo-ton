#ifndef TON_WORKER_H_
#define TON_WORKER_H_

#include "common.h"
#include "task.h"

namespace ton {

class Worker {
  public:
    Status status;

    Worker(Task&);
    ~Worker();
    void receive(Msg&);
    void work();
  private:
    Chan& _chan;
    Task& _task
    Msg& _msg;
}; //Worker

} //ton


#endif //TON_WORKER_H_

 
