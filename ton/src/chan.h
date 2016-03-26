#ifndef TON_CHAN_H_
#define TON_CHAN_H_

#include "common.h"
#include "worker.h"

namespace ton {

class Chan {
  public:
    Chan();
    ~Chan();
    void send(Worker*, Msg);
    void broadcast(Msg);
  private:
    size_t len;

}; //Chan 

} //ton

#endif //TON_CHAN_H_
