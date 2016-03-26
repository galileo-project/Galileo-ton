#ifndef TON_TASK_H_
#define TON_TASK_H_

namespace ton {

class Task {
  public:
    virtual void run() = 0;
}; //Task

} //ton

#endif //TON_TASK_H_
