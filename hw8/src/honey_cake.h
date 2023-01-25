#ifndef HONEY
#define HONEY

#include <string>
#include "cake.h"

class HoneyCake:public Cake{
    public:
        static int _count;
        HoneyCake(){_count+=1;}
        HoneyCake(int price, int sweet){
            _price = price;
            _sweet = sweet;
            _count+=1;
        };
        std::string to_string(){    
            char x1[80] = {};
            sprintf(x1, "| HoneyCake            |         %d |         %d |", _price, _sweet);
            return x1;
        }
        static int get_count(){
            return _count;
        }
        ~HoneyCake(){
            _count -= 1;
        }
};  

int HoneyCake::_count;

#endif