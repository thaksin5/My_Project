#ifndef TEQUILA
#define TEQUILA

#include "alcohol.h"
#include <string>

class Tequila:public Alcohol{
    public:
        Tequila() = default;
        Tequila(const std::string &name, const int &price, const double &content){
            if((name.length()==0) || (price<0) || !(content>=0 && content<=1)){ throw std::invalid_argument("invalid");}
            _name = name;
            _price = price;
            _content = content;
        }
        void dilute(){
            if(_content < 0){throw std::invalid_argument("invalid content");}
            else{
                _content = _content * 0.95;
            }
        }
        Tequila operator+(const Tequila &other){
            Tequila newTequila;
            newTequila._name = this->_name;
            newTequila._price = this->_price + other._price;
            newTequila._content = (this->_content + other._content) / 2;

            return  newTequila;
        }
        bool operator==(const Tequila &other){
            return ((_name == other._name) && (_price == other._price) && (_content == other._content));
        }   
        Tequila &operator=(const Tequila &other)=default;
        ~Tequila(){
            
        }
};

#endif