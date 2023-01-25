#ifndef FACTORY
#define FACTORY

#include <iostream>
#include <memory>
#include <string>
#include "Car.h"

class CarFactory{
    public:
        static std::unique_ptr<Car> SelectCar(int type){
            std::unique_ptr<Car> prototype;
            switch (type){
                case 1:{ // simple
                    prototype = std::make_unique<SimpleCar>("Toyota", "", 90);
                    break;
                }
                case 2:{ // racing
                    prototype = std::make_unique<RaceCar>("Porche", "", 120);
                    break;
                }
                default:
                    std::cout<<"**Error** Please select the following type(Toyota/Porche)"<<std::endl;
                    return nullptr;
            }
            return prototype;
        }
        static std::string SelectColor(int color){
            std::string res;
            switch(color){
            case 1:
                res = "Black";
                break;
            case 2:
                res = "White";
                break;
            case 3:
                res = "Grey";
                break;
            default:
                std::cout<<"**Error** Please select the following colors(Black/White/Grey)"<<std::endl;
                return "";
            }
            return res;
        }
};

#endif