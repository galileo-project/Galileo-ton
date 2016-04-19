#ifndef TON_CHAN_H_
#define TON_CHAN_H_

#include "common.h"
#include <vector>

namespace ton {
  
class Worker;
class Async;
class Runner;

class Chan {
  public:
    size_t len;

    Chan(Runner*);
    ~Chan();
    void send(const Worker&, const msg_t&);
    void broadcast(const msg_t&);
    void subscribe(const Worker&);
    void clear();
  private:
    std::vector<msg_t*> _msgs;
    std::vector<Worker> _subscribes;
    Async               *_async;
}; //Chan 

} //ton

#endif //TON_CHAN_H_
