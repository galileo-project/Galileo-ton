#include "worker.h"
#include "async.h"
#include "runner.h"

namespace ton {
    
Runner::Runner() {
    workers  = 0;
    status   = created;
    _async   = new Async();
}

void Runner::run() {
    status = running;
}

void Runner::dispatch(const Worker &worker) {
    _workers.push_back(worker);    
}
    
Async *Runner::async() {
    return _async;
}
    
} //ton