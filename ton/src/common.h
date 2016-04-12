#ifndef TON_COMMON_H_
#define TON_COMMON_H_

#include <string>

namespace ton {

typedef enum status_e {
    created,
    stopped,
    running,
    dead,
    started
} Status;

typedef enum signal_e {
    start,
    stop,
    kill
} Signal;

typedef enum type_e {
    log
} Type;

typedef struct msg_s {
   Signal signal; 
   Type type;
} Msg;

} //ton 

#endif //TON_COMMON_H_

