#include "runner.h"

namespace ton {
    
Runner::Runner() {
    workers  = 0;
    status   = created;
}

void Runner::run() {
    status = running;
}

void Runner::dispatch(Worker *worker) {
    _workers.push(worker);    
}

int Runner::_async(async_f *func, void *data) {
    pthread_t pid;
    if(pthread_create(&pid, NULL, func, data)) {
        return -1;
    }
    _pids.push(&pid);
    return 0;
}
    
} //ton