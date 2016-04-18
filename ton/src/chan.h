#ifndef TON_CHAN_H_
#define TON_CHAN_H_

#include "common.h"
#include "worker.h"
#include "async.h"
#include <vector>

namespace ton {

class Chan {
  public:
    size_t len;

    Chan();
    ~Chan();
    void send(const Worker&, const msg_t&);
    void broadcast(const msg_t&);
    void subscribe(const Worker&);
    void clear();
  private:
    void _scan(void);
    std::vector<msg_t*> _msgs;
    std::vector<Worker> _subscribes;
}; //Chan 

} //ton

#endif //TON_CHAN_H_
