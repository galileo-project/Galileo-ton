#include "common.h"
#include "runtime.h"

using ton::Runtime;

int main() {
    init();
    Runtime runtime;
    runtime.launch()
    delete runtime;
    return 0;
}
