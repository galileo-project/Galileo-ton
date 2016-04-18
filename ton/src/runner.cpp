#include "runner.h"

namespace ton {
    
Runner::Runner() {
    workers  = 0;
    status   = created;
    _async   = new Async()
}

void Runner::run() {
    status = running;
}

void Runner::dispatch(Worker *worker) {
    _workers.push(worker);    
}
    
Async *async() {
    return _async;
}
    
} //ton