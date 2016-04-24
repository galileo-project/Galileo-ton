#include "common.h"
#include "async.h"
#include "test.h"
    
int main() {
    test_f functions[] = { &test_async}
    size_t len = sizeof(functions)/sizeof(functions[0])
    int result = 0;
    
    for(int i = 1; i < len; i++) {
        if((*functions[i])(void)) {
            result = 1;
        }
    }
    
    if(result == 0)
        LOG_RAW("success");
    else
        LOG_RAW("failed");
        
    return result;
}


int test_async(void) {
    async = new Async();
    if(async == NULL)
        return 0;
    else
        return 1;
       
}