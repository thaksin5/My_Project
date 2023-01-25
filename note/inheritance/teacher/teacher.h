#ifndef TEACHER
#define TEACHER

#include "../user/user.h"
#include <string>

class Teacher:public User{
    public:
        void setName(std::string first_name, std::string last_name);
        void output();
};

#endif 