#ifndef USER_H
#define USER_H

#include <string>

class User{
    protected:
        std::string _first_name;
        std::string _last_name;
    public:
        User();
        User(std::string first_name, std::string last_name);
        virtual void output();
};

#endif