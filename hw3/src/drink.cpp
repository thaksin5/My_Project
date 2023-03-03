#include "drink.h"

Drink::Drink(std::string name, double sLevel){
    if((name!="") && (!(name.length()>4))){
        throw std::string("bad name");
    }
    if((sLevel!=-1) && !(sLevel>=0 && sLevel<=1)){
        throw std::string("bad sweet level");
    }
    _name = name; _sLevel = sLevel;

}
Drink::~Drink(){
    _topping.erase(_topping.begin(), _topping.end());
}
std::string Drink::getName(){
    if(_name == ""){ throw std::string("invalid name");}
    return _name;
}   
double Drink::getSweetnessLevel(){
    if(_sLevel == -1){ throw std::string("invalid name");}
    return _sLevel;
}   
void Drink::addTopping(std::string topping){
    _topping.push_back(topping);
    _topping_pos += 1;
}   
int Drink::getToppingCount(){
    return _topping_pos;
}                       
std::string Drink::getToppingByIndex(int index){
    if(index >= _topping_pos){ throw std::string("out of range");}
    return _topping[index];
}
