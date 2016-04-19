# Galileo ton Roadmap

### framework code

    Worker worker;
    Runner runner = Runner();   //chan in runner; thread pool in runner?
    runner.add(worker);
    
    TestTask task = new TestTask();
    
    Msg msg = new Msg();
    msg.set_task(task);
    chan.send(worker, msg);
    chan.broadcast(msg);
    
    class Task {
        public:
            virtual void run() = 0;
        private:
            void *(*func)(void*);
            void* data;
    }
    
    
### user code

    class CustomTask: public Task {}    //custom task inherit from Task

    Runner runner = new Runner();
    CustomTask task = new CustomTask();
    runner.add_task(task);
    
    Msg common_msg;                     //common msg like signal
    runner.chan.brodcast(common_msg)
    
    Msg worker_msg;                     //worker info inside msg 
    runner.chan.send(worker_msg)
    