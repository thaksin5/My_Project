#ifndef FACTORY
#define FACTORY

#include "Car.h"

class CarFactory{
    protected:
        virtual Tire buildTire()=0;
        virtual Body buildBody()=0;
    public:
        virtual Car *buildWholeCar()=0;
};

class SimpleCarFactory:public CarFactory{
    Tire buildTire(){
        Tire new_tire = SimpleTire();
        return new_tire;
    }
    Body buildBody(){
        Body new_body = SimpleBody();
        return new_body;
    }
    Car *buildWholeCar(){
        Car *car = new Car("SimpleCar");
        car->setTire(buildTire());
        car->setBody(buildBody());
        
        return car;
    }
};

class LuxuryCarFactory:public CarFactory{
    Tire buildTire(){
        Tire new_tire = LuxuryTire();
        return new_tire;
    }
    Body buildBody(){
        Body new_body = LuxuryBody();
        return new_body;
    }
    Car *buildWholeCar(){
        Car *car = new Car("LuxuryCar");
        car->setTire(buildTire());
        car->setBody(buildBody());
        
        return car;
    }
};

#endif