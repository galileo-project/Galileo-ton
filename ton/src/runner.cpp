#include "worker.h"
#include "async.h"
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

void Runner::dispatch(Worker &worker) {
    _workers.push(worker);    
}
    
Async *Runner::async() {
    return _async;
}
    
} //ton