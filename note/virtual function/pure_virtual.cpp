#include <iostream>

class Instrument{
    public:
        virtual void makeSound() = 0; // pure virtual function 
        // without an implementation, but it force to all derive class use virtual 
};
class Saxophone:public Instrument{
    public:
        void makeSound(){
            std::cout<<"saxophone sound"<<std::endl;
        }
};
class Piano:public Instrument{
 public:
    void makeSound(){
        std::cout<<"piano sound"<<std::endl;
    }
};

int main(){
    Instrument *sax = new Saxophone();
    sax->makeSound();

    Instrument *pia = new Piano();
    pia->makeSound();

    std::cout<<"----------------------"<<std::endl;
    std::cout<<"Polymorphism"<<std::endl;
    Instrument *arr_i[2] = {sax, pia};
    for(int i=0; i<2; i++){
        arr_i[i]->makeSound();
    }

    return 0;
}