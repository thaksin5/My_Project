#include <iostream>
#include <string>
#include "CarFactory.h"

int main(){     
    int types;
    int color;
    bool running = true;

    while(running){
        std::cout<<"Enter type of Car(1.Simple car, 2.)Racing car) or press '0' to exit: ";
        std::cin>>types;
        if(types == 0){ break;}

        std::unique_ptr<Car> car = CarFactory::SelectCar(types);
        if(car == nullptr){ continue; }

        std::cout<<"Enter colors of Car (1.Black, 2.White 3.Grey) : ";
        std::cin>>color;
        std::string car_color = CarFactory::SelectColor(color);
        if(car_color == ""){ continue;}
        car->setColor(car_color);

        if(car){
            car->display();
        }
    }
    std::cout<<"Exit"<<std::endl;

    return 0;
}