#include <iostream>
#include "Observer.h"

int main(){
    WeatherForecast *forecast = new WeatherForecast();
    Phone phone(forecast);
    Computer computer(forecast);
    
    forecast->setTemperature(20);
    forecast->setTemperature(25);
    forecast->setTemperature(11);

    delete forecast;

    return 0;
}