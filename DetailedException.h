#ifndef DETAILED_EXCEPTION_H_
#define DETAILED_EXCEPTION_H_
#include <string>
#include <exception>

class DetailedException: virtual public std::exception {
    protected:
    std::string error_message;
    
    public:
    explicit DetailedException(const std::string& msg):
        error_message(msg) {}

    virtual ~DetailedException() throw() {}
    virtual const char* what() const throw() {
       return error_message.c_str();
    }
};

#endif
