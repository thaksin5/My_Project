#ifndef SOUR
#define SOUR 

#include "alcohol.h"
#include <string>
#include <stdexcept>


class Sour : public Alcohol{
    public:
        Sour() = default;
        Sour(const std::string &name, const int &price, const double &content){
            if((name.length()==0) || (price<0) || !(content>=0 && content<=1)){ throw std::invalid_argument("invalid");}
            _name = name;
            _price = price;
            _content = content;
        }
        void dilute(){
            if(_content < 0){throw std::invalid_argument("invalid content");}
            else{
                _content = _content * 0.70;
            }
        }
        Sour operator+(const Sour &other){
            Sour newSour;
            newSour._name = this->_name;
            newSour._price = this->_price + other._price;
            newSour._content = (this->_content + other._content) / 2;

            return newSour;
        }
        bool operator==(const Sour &other){
            return ((_name == other._name) && (_price == other._price) && (_content == other._content));
        }
        Sour &operator=(const Sour &other)=default;
        ~Sour(){
            
        }
};

#endif