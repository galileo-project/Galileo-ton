#include "runtime.h"
#include "runner.h"

namespace ton {
    
Runtime::Runtime() {
    status = created;
}

Runtime::~Runtime() {
    
}

void Runtime::launch() {
    status = started;
    Runner runner;
    
}
    
} //ton