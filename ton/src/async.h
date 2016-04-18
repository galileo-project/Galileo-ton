#ifndef TON_ASYNC_H_
#define TON_ASYNC_H_

#include <pthread>

namespace ton {
    
//async function
typedef void *async_f(void*);

//async status
typedef enum async_e {
    async_done,
    async_run
}async_status_t;

//async return info
typedef struct async_s {
    pthread_t       pid;
    async_status_t  async_status;
}async_ret_t;
    
async_ret_t * async_ret_new(pthread_t);
void async_ret_run(async_ret_t*);
void async_ret_done(async_ret_t*);

//async wrapper data
typedef struct wrapper_data_s {
    async_f *func;
    void    *data;
} wrapper_data_t;

wrapper_data_t *wrapper_data_new(async_f*, void*);
    
//Async class
class Async {
  public:
    std::vector<void*> result;
    Async();
    ~Async();
    int run(async_f*, void*);
  private:
    void *_wrapper(wrapper_data*);
    void _async_done();
    std::vector<async_ret_t> _rets;
    pthread_mutex_t _lock;
}; //Async
    
} // ton

#endif //TON_ASYNC_H_
