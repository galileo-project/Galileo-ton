#include "worker.h"
#include "async.h"
#include "chan.h"

namespace ton {

Chan::Chan(Runner *runner) {
    len = 0;
    _async = runner->async();
}

Chan::~Chan() {
    clear();
}

void Chan::clear() {
    _subscribes.clear();
    _msg.clear();
}

void Chan::send(const Worker& worker, const msg_t& msg) {
    _async.run(worker.receive, msg);
}
   
void Chan::broadcast(const msg_t& msg) {
    if(!subscribes.empty()) {
        const auto end = subscribes.cend();
        for(auto worker = subscribes.cbegin(); worker != end; ++worker) {
            _async.run(worker.receive, msg);
        }
    }
}   

} //ton