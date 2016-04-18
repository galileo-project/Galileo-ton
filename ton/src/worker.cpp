#include "worker.h"
#include "common.h"
#include "utils.h"

namespace ton {
    
Worker::Worker() {
    status = created;
    msg    = NULL;
    _task  = NULL;
    Chan   = NULL;
}

Worker::~Worker() {
    safe_free(msg);
    safe_free(_task);
}

void Worker::receive(const Msg& msg) {
    
}

void Worker::worker() {
    
}
    
} //ton