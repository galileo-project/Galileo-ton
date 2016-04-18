#ifndef TON_WORKER_H_
#define TON_WORKER_H_

#include "common.h"
#include "task.h"
#include "chan.h"

namespace ton {

class Worker {
  public:
    status_t status;

    Worker(Task&);
    ~Worker();
    void receive(const msg_t&);
    void work();
  private:
    Chan& _chan;
    Task& _task;
    msg_t& _msg;
}; //Worker

} //ton


#endif //TON_WORKER_H_

 
