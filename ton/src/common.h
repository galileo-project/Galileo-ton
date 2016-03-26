#ifndef TON_COMMON_H_
#define TON_COMMON_H_
 
namespace ton {

typedef enum status_e {
    stopped,
    running,
    dead
} Status;

typedef enum signal_e {
    start,
    stop,
    kill
} Signal;

typedef struct msg_s {
   Signal signal; 
} Msg;

} //ton 

#endif //TON_COMMON_H_

