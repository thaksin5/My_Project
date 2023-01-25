#include <iostream>
#include "teacher.h"
#include <string>

void Teacher::setName(std::string first_name, std::string last_name){
    _first_name = first_name;
    _last_name = last_name;
}

void Teacher::output(){
    std::cout<<_first_name<<std::endl;
    std::cout<<_last_name<<std::endl;
}