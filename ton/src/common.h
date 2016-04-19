#ifndef TON_COMMON_H_
#define TON_COMMON_H_

#include <string>

namespace ton {

typedef enum status_e {
    _created_st,
    _stopped_st,
    _running_st,
    _dead_st,
    _started_st,
    _null_st
} status_t;

typedef enum signal_e {
    _start_sg,
    _stop_sg,
    _kill_sg,
    _null_sg
} signal_t;

typedef enum type_e {
    _task_tp,
    _signal_tp,
    _null_tp,
    _result_tp
} type_t;

typedef struct msg_s {
   signal_t signal; 
   type_t type;
   void *data;
} msg_t;

} //ton 

#endif //TON_COMMON_H_

