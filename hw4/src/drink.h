#ifndef DRINK
#define DRINK

#include <string>
#include <vector>
#include "topping.h"

class Drink{
    private:
        std::string _name="";
        double _sLevel=-1;
        int _price=-1;
        std::vector<Topping> _topping;
        int _topping_count = 0;
    public:
        Drink() = default;
        Drink(std::string name, double sLevel, int price){
            if(name.size()<4 || sLevel<0 || sLevel>1 || price<0){ throw std::string("invalid");}
            _name = name;
            _sLevel = sLevel;
            _price = price;
        }
        std::string getName() const{
            if(_name == ""){ throw std::string("invalid string");}
            return _name;
        }
        double getSweetnessLevel() const{
            if(_sLevel == -1){ throw std::string("invalid sweet level");}
            return _sLevel;
        }
        int getPrice() const{
            if(_price == -1){ throw std::string("invalid price");}
            return _price;
        }
        Topping getToppingByIndex(int index) const{
            if(index >= _topping_count){ throw std::string("out of range");}
            return _topping[index];
        }
        int getToppingCount() const{
            return _topping_count;
        }
        void addTopping(Topping topping){
            _topping.push_back(topping);
            _topping_count+=1;
            _price += topping.getPrice(); 
            _sLevel += topping.getSweetnessLevel();
        }
        Drink &operator=(const Drink &other) = default;
        ~Drink() = default;
};

#endif