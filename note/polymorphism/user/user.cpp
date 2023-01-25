#include <iostream>
#include "user.h"
#include <string>

User::User(){

}

User::User(std::string first_name, std::string last_name){
    _first_name = first_name;
    _last_name = last_name;
}

void User::output(){
    std::cout<<"display user"<<std::endl;
}