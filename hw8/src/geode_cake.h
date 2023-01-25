#ifndef GEODE
#define GEODE

#include <string>
#include "cake.h"

class GeodeCake:public Cake{
    public:
        static int _count;
        GeodeCake(){_count+=1;}
        GeodeCake(int price, int sweet){
            _price = price;
            _sweet = sweet;
            _count+=1;
        };
        std::string to_string(){    
            char x1[80] = {};
            sprintf(x1, "| GeodeCake            |         %d |         %d |", _price, _sweet);
            return x1;
        }
        static int get_count(){
            return _count;
        }
        ~GeodeCake(){
            _count -= 1;
        }
};  

int GeodeCake::_count;

#endif