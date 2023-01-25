#include <iostream>


// without virtual
class Instrument{
    public:
        void makeSound(){
            std::cout<<"instrument sound"<<std::endl;
        }
};
class Saxophone:public Instrument{
    public:
       
        void makeSound(){
            std::cout<<"saxxophone sound"<<std::endl;
        }
};

// virtual
class Person{
    public:
        virtual void display(){
            std::cout<<"display person"<<std::endl;
        }
};
class Teacher:public Person{
    public:
        void display(){
            std::cout<<"display teacher"<<std::endl;
        }
};

int main(){
    Instrument *s = new Saxophone(); // Creates an object in dynamic memory. 
    s->makeSound(); // o/p : "instrument sound", it execute in Instrument

    Person *p = new Teacher();
    p->display();
}
