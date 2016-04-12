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

void Chan::send(const Worker& worker, const Msg& msg) {
    worker.receive(msg);
}
   
void Chan::broadcast(const Msg& msg) {
    if(!subscribes.empty()) {
        const auto& end = subscribes.cend();
        for(auto worker = subscribes.cbegin(); worker != end; ++worker) {
            worker.receive(msg);
        }
    }
}   
   
} //ton