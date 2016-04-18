#include "async.h"

namespace ton {
    
Async::Async() {
    pthread_mutex_init(&_lock, NULL);  
}

Async::~Async() {
    pthread_exit(0);
}
    
int Async::run(async_f *func, void *data) {
    pthread_t pid;
    if(pthread_create(&pid, NULL, func, data)) {
        return -1;
    }
    _pids.push(&pid);
}
    
} //ton