#ifndef USER
#define USER

#include <string>

class User{
    protected:
        std::string _first_name;
        std::string _last_name;
    public:
        User();
        User(std::string first_name, std::string last_name);
};

#endif