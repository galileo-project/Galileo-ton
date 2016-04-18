#include "worker.h"
#include "common.h"
#include "utils.h"

namespace ton {
    
Worker::Worker(Task &task) {
    status = created;
    msg    = NULL;
    _task  = task;
    Chan   = NULL;
}

Worker::~Worker() {
    safe_free(_msg);
    safe_free(_task);
}

void Worker::receive(const msg_t& msg) {
    
}

void Worker::worker() {
    
}
    
} //ton