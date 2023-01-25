#ifndef OBSERVER
#define OBSERVER

#include <iostream>
#include "Forecast.h"

// observer
class Observer{
    private:
        WeatherForecast *_forecast;
    protected:
        WeatherForecast *getForcast(){ return _forecast;}
    public:
        Observer(WeatherForecast *forcast):_forecast(forcast){
            _forecast->attach(this);
        }
        virtual void update()=0;
        ~Observer(){}
};
void WeatherForecast::notify(){
    for(int i=0; i<_obsLst.size(); i++){
        _obsLst[i]->update();
    }
}

// concrete observer
class Phone:public Observer{
    public:
        Phone(WeatherForecast *w):Observer(w){}
        void update()override{
            int temp = getForcast()->getTemperature();
            std::cout<<"Temperature : "<<temp<<" (display in phone)"<<std::endl;
        }
        ~Phone(){}
};
class Computer:public Observer{
    public:
        Computer(WeatherForecast *w):Observer(w){}
        void update() override{
            int temp = getForcast()->getTemperature();
            std::cout<<"Temperature : "<<temp<<" (display in Computer)"<<std::endl;
        }
        ~Computer(){}
};

#endif