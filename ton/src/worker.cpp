#include "worker.h"
#include "common.h"
#include "utils.h"

namespace ton {
    
Worker::Worker(Task &task) {
    status = created;
    _task  = task;
    _chan   = NULL;
}

Worker::~Worker() {
    safe_free(&_task);
}

void Worker::receive(const msg_t& msg) {
    
}

void Worker::work() {
    
}
    
} //ton