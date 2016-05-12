# Galileo ton Roadmap

## ROADMAP

```
==========================================================
                   Application
----------------------------------------------------------
File System|App Channel|Life Cycle Manager|
==========================================================
           |                   Kernel
  Library  |----------------------------------------------
           |Memory|Storage|Database|Network|
==========================================================
                    Driver
----------------------------------------------------------
vMemory|vDisk|
----------------------------------------------------------
                 Union Channel
==========================================================
                    Linux
```

### Framework code
    
```c

class Task {
    public:
        virtual void run() = 0;
    private:
        void *(*func)(void*);
        void *data;
}

typedef enum type_e {
    _task_tp,
    _signal_tp,
    _null_tp,
    _result_tp
} type_t;

```
    
### User code

```c
class CustomTask: public Task {}        //custom task inherit from Task

Runner runner = new Runner();
CustomTask task = new CustomTask();
runner.add_task(task);

Msg common_msg;                         //common msg like signal
runner.chan.brodcast(common_msg)

Msg worker_msg;                         //worker info inside msg 
runner.chan.send(worker_msg)

Msg *msg = runner.chan.pop(_result_tp)  //get task result

delete runner;
   
```
    
### Note

1. Runner implement with thread pool