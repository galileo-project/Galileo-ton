#include <stdlib>
#include "utils.h"

namespace ton {
    
void safe_free(void *p) {
    if(p != NULL)
        free(p);
}
    
} //ton