#ifndef TON_ASYNC_H_
#define TON_ASYNC_H_

namespace ton {
    
typedef void *(*async_f)(void*);

typedef struct async_s {
    size_t timeout;
} async_t;

async_t *async_create();
void async_init(async_t*);
void async_wait(async_t*);
void async_add(async_t*, void*);
void async_exit(async_t*);
void async_run(async_f);

} //ton

#endif //TON_ASYNC_H_