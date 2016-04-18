#include "worker.h"
#include "common.h"
#include "utils.h"
#include "chan.h"

namespace ton {
    
Worker::Worker(Task &task) {
    status = created;
    _task  = &task;
    _chan  = new Chan();
}

Worker::~Worker() {
    safe_free(_task);
}

void *Worker::receive(const msg_t& msg) {
    return NULL;
}

void Worker::work() {
    
}
    
} //ton