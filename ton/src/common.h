#ifndef TON_COMMON_H_
#define TON_COMMON_H_

#include <string>

namespace ton {

typedef enum status_e {
    created,
    stopped,
    running,
    dead,
    started,
    nullStatus
} status_t;

typedef enum signal_e {
    start,
    stop,
    kill,
    nullSignal
} signal_t;

typedef enum type_e {
    task,
    signal,
    nullType
} type_t;

typedef struct msg_s {
   signal_t signal; 
   type_t type;
   void *data;
} msg_t;

} //ton 

#endif //TON_COMMON_H_

