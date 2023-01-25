#ifndef TOY
#define TOY

#include <iostream>
#include <string>

class Toy{
    protected:
        std::string _name="";
        double _price=0;
    public:
        Toy()=default;
        Toy(std::string name, double price):_name(name), _price(price){}
        virtual void prepareParts()=0;
        virtual void combineParts() = 0;
        virtual void assembleParts() = 0;
        virtual void applyLabel() = 0;
        virtual void showProduct() = 0;
};

class Car:public Toy{
    public:
        Car():Toy("Car", 10){} 
        void prepareParts(){ std::cout<<"Prepare Car Parts"<<std::endl;}
        void combineParts(){ std::cout<<"Combine Car Parts"<<std::endl;}
        void assembleParts(){ std::cout<<"Assemble Car Parts"<<std::endl;}
        void applyLabel(){ std::cout<<"Applying Car Parts"<<std::endl;}
        void showProduct(){ std::cout<<"Name : "<<_name<<"\n"<<"Price : "<<_price<<std::endl;}
        ~Car(){}
};

class Bike:public Toy{
    public:
        Bike():Toy("Bike", 20){} 
        void prepareParts(){ std::cout<<"Prepare Bike Parts"<<std::endl;}
        void combineParts(){ std::cout<<"Combine Bike Parts"<<std::endl;}
        void assembleParts(){ std::cout<<"Assemble Bike Parts"<<std::endl;}
        void applyLabel(){ std::cout<<"Applying Bike Parts"<<std::endl;}
        void showProduct(){ std::cout<<"Name : "<<_name<<"\n"<<"Price : "<<_price<<std::endl;}
};

class Plane:public Toy{
    public:
        Plane():Toy("Plane", 30){} 
        void prepareParts(){ std::cout<<"Prepare Plane Parts"<<std::endl;}
        void combineParts(){ std::cout<<"Combine Plane Parts"<<std::endl;}
        void assembleParts(){ std::cout<<"Assemble Plane Parts"<<std::endl;}
        void applyLabel(){ std::cout<<"Applying Plane Parts"<<std::endl;}
        void showProduct(){ std::cout<<"Name : "<<_name<<"\n"<<"Price : "<<_price<<std::endl;}
};


#endif