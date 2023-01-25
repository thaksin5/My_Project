#pragma once

#include <iostream>
#include <string>
#include <memory>

class Car{
    protected:
        std::string _model;
        std::string _color;
    public:
        Car()=default;
        Car(std::string model, std::string color):_model(model), _color(color){}
        void setColor(std::string color){
            _color = color;
        }
        void display(){
            std::cout<<"Model : "<<_model<<std::endl;
            std::cout<<"Color : "<<_color<<std::endl;
        }
        virtual std::unique_ptr<Car> clone()=0;
        ~Car(){}
};

class SimpleCar:public Car{
    private:
        int _maxSpeed;
    public:
        SimpleCar(std::string model, std::string color, int maxSpeed):Car(model, color), _maxSpeed(maxSpeed){}
        std::unique_ptr<Car> clone() override {
            return std::make_unique<SimpleCar>(*this);
        }
};

class RaceCar:public Car{
    private:
        int _maxSpeed;
    public:
        RaceCar(std::string model, std::string color, int maxSpeed):Car(model, color), _maxSpeed(maxSpeed){}
        std::unique_ptr<Car> clone() override {
            return std::make_unique<RaceCar>(*this);
        }
};
