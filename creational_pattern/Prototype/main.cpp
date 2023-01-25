#include <iostream>
#include <string>
#include <vector>
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

class RaceCar:public Car{
    private:
        int _maxSpeed;
    public:
        RaceCar(std::string model, std::string color, int maxSpeed):Car(model, color), _maxSpeed(maxSpeed){}
        std::unique_ptr<Car> clone() override {
            return std::make_unique<RaceCar>(*this);
        }
};

int main(){
    // unique_ptr -> smart pointer automatically deallocate when out of scope
    std::vector<std::unique_ptr<Car>> cars;
    std::unique_ptr<Car> prototype = std::make_unique<RaceCar>("Porche", "", 300); // obj

    auto redCar = prototype->clone();
    redCar->setColor("Red");
    cars.emplace_back(std::move(redCar));

    auto blueCar = prototype->clone();
    blueCar->setColor("Blue");
    cars.emplace_back(std::move(blueCar));

    for(int i=0; i<cars.size(); i++){
        cars[i]->display();
        std::cout<<"---------------------------"<<std::endl;
    }

    return 0;
}
