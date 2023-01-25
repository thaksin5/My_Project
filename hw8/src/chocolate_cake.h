#ifndef CHOCOLATE
#define CHOCOLATE

#include <string>
#include "cake.h"

class ChocolateCake:public Cake{
    public:
        static int _choco_count;
        ChocolateCake(){_choco_count+=1;}
        ChocolateCake(int price, int sweet){
            _price = price;
            _sweet = sweet;
            _choco_count+=1;
        };
        std::string to_string(){    
             char str[80] = {};
            sprintf(str, "| ChocolateCake        |         %d |         %d |", _price, _sweet);
            return str;
        }
        static int get_count(){
            return _choco_count;
        }
        ~ChocolateCake(){
            _choco_count -= 1;
        }
};  

int ChocolateCake::_choco_count=0;

#endif