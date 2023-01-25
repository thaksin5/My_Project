#include <iostream>
#include "ToyFactory.h"

int main(){

    int type;
    while(true){
        std::cout<<"Enter type or '0' for exit";
        std::cin>>type;
        if(!type)
            break;
        
        Toy *toy_obj = ToyFactory::createToy(type);
        if(toy_obj){
            toy_obj->showProduct();
            delete toy_obj;
        }
    }
    std::cout<<"Exit"<<std::endl;

    return 0;
}