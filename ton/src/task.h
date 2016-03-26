#ifndef TON_TASK_H_
#define TON_TASK_H_

namespace ton {

class Task {
  public:
    Task();
    ~Task();
    void run();
  private:
    void *_task;
}; //Task

} //ton

#endif //TON_TASK_H_
