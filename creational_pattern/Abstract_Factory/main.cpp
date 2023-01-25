#include "Car_Factory.h"

// #define SIMPLE_CAR 1
#define LUXURY_CAR 1

int main(){
    #ifdef SIMPLE_CAR
        CarFactory *factory = new SimpleCarFactory();
    #elif LUXURY_CAR
        CarFactory *factory = new LuxuryCarFactory;
    #endif
    
    Car *car = factory->buildWholeCar();
    car->printDetail();
    delete car;
    delete factory;
    return 0;
}
