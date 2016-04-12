#ifndef TON_CHAN_H_
#define TON_CHAN_H_

#include "common.h"
#include "worker.h"
#include <vector>

namespace ton {

class Chan {
  public:
    size_t len;

    Chan();
    ~Chan();
    void send(const Worker&, const Msg&);
    void broadcast(const Msg&);
    void subscribe(const Worker&);
    void clear();
  private:
    std::vector<Worker> subscribes;
}; //Chan 

} //ton

#endif //TON_CHAN_H_
