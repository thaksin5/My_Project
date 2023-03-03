#ifndef ALCOHOL
#define ALCOHOL

#include <string>
#include <stdexcept>

class Alcohol{
    protected:
        std::string _name = "";
        int _price = 0;
        double _content = -1;
    public:
        Alcohol()=default;
        virtual void dilute()=0;
        std::string get_name() const{
            if(_name == ""){ throw std::invalid_argument("invalid name");}
            return _name;   
        }                   
        int get_price() const{
            if(_price == 0){ throw std::invalid_argument("invalid price");}
            return _price;  
        }                   
        double get_alcohol_content() const{
            if(_content == -1){  throw std::invalid_argument("invalid content");}
            return _content;
        }
        virtual ~Alcohol(){}
};

#endif