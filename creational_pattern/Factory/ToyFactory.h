#ifndef FACTORY
#define FACTORY

#include <iostream>
#include "Toy.h"

class ToyFactory{
    public:
        static Toy *createToy(int type){
            Toy *toy; // can return because inside static function
            switch(type){
                case 1 :
                    toy = new Car;
                    break;
                case 2 :
                    toy = new Bike;
                    break;
                case 3 :
                    toy = new Plane;
                    break;
                default:
                    std::cout<<"invalid type, please re-enter type"<<std::endl;
                    return NULL;
            }
            toy->prepareParts();
            toy->combineParts();
            toy->assembleParts();
            toy->applyLabel();
            return toy;
        }
};

#endif