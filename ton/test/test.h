#ifndef TON_TEST_H_
#define TON_TEST_H_
#include <string>
#include <iostream>

#define LOG_INFO(msg) do{ \
    std::cout << "INFO:" << msg << std::endl; \
    }while(0)
    
#define LOG_ERR(msg) do{ \
    std::cout << "ERR:" << msg << std::endl; \
    }while(0)
    
#define LOG_SUCCESS(msg) do{ \
    std::cout << "SUCCESS:" << msg << std::endl; \
    }while(0)
    
#define LOG_RAW(msg) do{ \
    std::cout << msg << std::endl; \
    }while(0)
    
typedef int (*test_f)(void);

#endif //TON_TEST_H_