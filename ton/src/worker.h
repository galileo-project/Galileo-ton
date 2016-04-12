#ifndef TON_WORKER_H_
#define TON_WORKER_H_

#include "common.h"
#include "task.h"

namespace ton {

class Worker {
  public:
    Status status;

    Worker(Task *task);
    ~Worker();
    void receive(const Msg&);
    void work();
  private:
    Chan *chan;
    Task *_task
    Msg *msg;
}; //Worker

} //ton


#endif //TON_WORKER_H_

 
