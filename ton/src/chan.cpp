#include "chan.h"

namespace ton {

Chan::Chan() {
    len = 0;
}

Chan::~Chan() {
    clear();
}

void Chan::clear() {
    subscribes.clear();
}

void Chan::send(const Worker& worker, const msg_t& msg) {
    worker.receive(msg);
    _scan();
}
   
void Chan::broadcast(const msg_t& msg) {
    if(!subscribes.empty()) {
        const auto& end = subscribes.cend();
        for(auto worker = subscribes.cbegin(); worker != end; ++worker) {
            worker.receive(msg);
        }
    }
    _scan();
}   

void Chan::_scan(void) {
    
}
   
} //ton