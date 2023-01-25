#include <iostream>
using namespace std;

class Base{
    public:
        Base() {
            std::cout<<"Base constructor"<<std::endl;
        }
        ~Base(){
            std::cout<<"Base Destructor"<<std::endl;
        }
};
class Derived: public Base{
    public:
        Derived (){
            std::cout<<"Derived constructor"<<std::endl;
        }
        ~Derived(){
            std::cout<<"Derived Destructor"<<std::endl;
        }
};
// ----------------------------------------------------------------------
class Instrument{
    public:
        Instrument(){
            std::cout<<"Instrument constructor"<<std::endl;
        }
        virtual ~Instrument(){
            std::cout<<"Instrument Destructor"<<std::endl;
        }
};
class Violin:public Instrument{
    public:
        Violin(){
            std::cout<<"Violin constructor"<<std::endl;
        }
        ~Violin(){
            std::cout<<"Violin Destructor"<<std::endl;
        }
};


int main(){
    std::cout<<"without destructor\n";
    /* without virtual destructor*/
    Base *base = new Base();
    delete base;
    std::cout<<"--------------------------\n";
    Derived *derived = new Derived();
    delete derived;
    std::cout<<"--------------------------\n";
    // it didn't destruct the derived constructor, can cause memory leak
    Base *poly = new Derived();
    delete poly; 
    std::cout<<"*****************************\n";

    // to solve this problem we use virtual destructor, it make class behave properly
    Instrument *i1 = new Violin();
    delete i1;

    return 0;
}