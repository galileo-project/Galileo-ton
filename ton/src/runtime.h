#ifndef TON_RUNTIME_H_
#define TON_RUNTIME_H_

#include "common.h"

namespace ton {

class Runtime() {
  public:
    Status status;

    Runtime();
    ~Runtime();
    void launch();
}; //Runtime

} //ton

#endif //TON_RUNTIME_H_
