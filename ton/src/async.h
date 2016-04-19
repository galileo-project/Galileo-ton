#ifndef TON_ASYNC_H_
#define TON_ASYNC_H_

#include <pthread.h>
#include <vector>

namespace ton {
    
class Async;
static void *_wrapper(void *);
    
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
int  async_ret_eq(const async_ret_t&, const async_ret_t&);

//async wrapper data
typedef struct wrapper_data_s {
    async_f *func;
    void    *data;
    Async   *async;
} wrapper_data_t;

wrapper_data_t *wrapper_data_new(async_f*, void*, Async*);
    
//Async class
class Async {
  public:
    std::vector<void*> result;
    Async();
    ~Async();
    int  run(async_f*, void*);
    friend static void *_wrapper(void*);
  private:
    void                      _async_done();
    std::vector<async_ret_t>  _rets;
    pthread_mutex_t           _lock;
}; //Async
    
} // ton

#endif //TON_ASYNC_H_
