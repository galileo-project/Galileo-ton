#include <cstdlib>
#include "async.h"

namespace ton {
    
async_ret_t * async_ret_new(pthread_t pid) {
    async_ret_t *ret = (async_ret_t*)malloc(sizeof(async_ret_t));
    if(ret == NULL)
        return NULL;
        
    ret->pid = pid;
    return ret;
}

void async_ret_run(async_ret_t *ret) {
    ret->async_status = async_run;
}
    
void async_ret_done(async_ret_t *ret) {
    ret->async_status = async_done;
}

int async_ret_eq(const async_ret_t &lhs, const async_ret_t &rhs) {
    if(rhs.pid == lhs.pid && rhs.async_status == lhs.async_status)
        return 1;
    else
        return 0;
}

//wrapper
wrapper_data_t *wrapper_data_new(async_f *func, void *data) {
    wrapper_data_t *wrapper_data = (wrapper_data_t*)malloc(sizeof(wrapper_data_t));
    if(wrapper_data == NULL)
        return NULL;
    
    wrapper_data->func = func;
    wrapper_data->data = data;
    return wrapper_data;
}

//function of Async class
Async::Async() {
    pthread_mutex_init(&_lock, NULL);  
}

Async::~Async() {
    pthread_exit(0);
}
    
int Async::run(async_f *func, void *data) {
    wrapper_data_t *wrapper_data = wrapper_data_new(func, data); 
    pthread_t pid;
    
    if(pthread_create(&pid, NULL, &_wrapper, wrapper_data)) {
        return -1;
    }
    async_ret_t *ret = async_ret_new(pid);
    async_ret_run(ret);
    _rets.push_back(ret);
    return 0;
}
 
void Async::_async_done() {
    const async_ret_t cend = this->_rets.cend();
    for(async_ret_t ret = this->_rets.cbegin(); async_ret_eq(ret, cend); ++ret) {
        if(ret.async_status == async_done) {
            void **data;
            pthread_join(ret.pid, data);
            result.push_back(data);
        }
    }
}
    
friend void *_wrapper(void*) {
    wrapper_data_t *_data = (wrapper_data_t*)(data);
    void *ret = (_data->func)(_data->data);
    _async_done();
    return ret;
}
    
} //ton