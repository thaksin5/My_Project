#ifndef FORECAST
#define FORECAST

#include <iostream>
#include <vector>
#include <algorithm>
#include "Observer.h"

class Observer;

// subject
class WeatherForecast{
    private:
        int _temp;
        std::vector<Observer*> _obsLst;
    public:
        WeatherForecast()=default;
        int getTemperature(){
            return _temp;
        }
        void setTemperature(int temp){
            _temp = temp;
        }
        void attach(Observer* obs){
            _obsLst.push_back(obs);
            notify();
        }                   
        void detach(Observer* obs){
            _obsLst.erase(std::remove(_obsLst.begin(), _obsLst.end(), obs), _obsLst.end());
        }
        void notify(); 
        ~WeatherForecast(){}
};

#endif