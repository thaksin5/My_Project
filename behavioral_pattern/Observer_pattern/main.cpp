#include <iostream>
#include <vector>
#include <algorithm> // std::remove

class Observer; // because Observer depends on Car so the preprocessor will process observer first

// subject 
class Car{
    private:
        int _position;
        std::vector<Observer*> _obs; // 
    public:
        Car()=default;
        int getPosition(){
            return _position;
        }
        void setPosition(int position){
            _position = position;
            notify();
        }
        void Attach(Observer *obj){
            _obs.push_back(obj);
        }
        void Detach(Observer *obj){
            _obs.erase(std::remove(_obs.begin(), _obs.end(), obj), _obs.end());
        }
        void notify();
        ~Car(){}
};

// observer (abstract class)
class Observer{
    private:
        Car *_car;
    protected:
        Car *getCar(){ return _car;}
    public:
        Observer(Car *car):_car(car){ 
            _car->Attach(this);
        }
        virtual void update()=0;
};
void Car::notify(){
    for(int i=0; i<_obs.size(); i++){
        _obs[i]->update();
    }
}

// concrete observer
class LeftObserver:public Observer{
    public:
        LeftObserver(Car *car):Observer(car){}
        void update() override {
            int pos = getCar()->getPosition();
            if(pos<0){
                std::cout<<"left side"<<std::endl;
            }
        }
};
class RightObserver:public Observer{
    public:
        RightObserver(Car *car):Observer(car){}
        void update() override {
            int pos = getCar()->getPosition();
            if(pos>0){
                std::cout<<"right side"<<std::endl;
            }
        }
};
class MiddleObserver:public Observer{
    public:
        MiddleObserver(Car *car):Observer(car){}
        void update() override {
            int pos = getCar()->getPosition();
            if(pos==0){
                std::cout<<"middle side"<<std::endl;
            }
        }
};


int main(){
    Car *car = new Car();
    LeftObserver leftObs(car);
    RightObserver rightObs(car);
    MiddleObserver midObs(car);

    char pressButton;
    bool running = true;

    while(running){
        std::cout<<"hit left(l)/right(r) button to drive a car (press break(b) to break the car)"<<std::endl;
        std::cin>>pressButton;
        switch(pressButton){
        case 'l':{
            car->setPosition(-1);
            break;
        }
        case 'r':{
            car->setPosition(1);
            break;
        }
        case 'm':{
            car->setPosition(0);
            break;
        }
        case 'b':{
            running = false;
            break;
        }
        default:
            std::cout<<"Press again"<<std::endl;
        }
    }
    std::cout<<"Break the car"<<std::endl;

    delete car;
    return 0;
}