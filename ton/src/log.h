#ifndef TON_LOG_H_
#define TON_LOG_H_

#include "common.h"

namespace ton {

class Log {
  public:
    void info(std::string);
    void debug(std::string);
    void warn(std::string);
    void error(std::string);
    void fatal(std::string);
  private:
    std::string log_file; 

}; //Log

} //ton

#endif //TON_LOG_H_
