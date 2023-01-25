#ifndef PRODUCT
#define PRODUCT

#include <string>

class Product{
    private:
        std::string _name = "";
        int _price=-1;
    public:
        Product()=default;
        Product(std::string name, int price){
            if(name.size()<4 || price<0){ throw std::string("invalid");}
            _name = name;
            _price = price;
        }
        std::string getName() const{
            if(_name==""){ throw std::string("invalid name");}
            return _name;
        }
        int getPrice() const{
            if(_price == -1){ throw std::string("invalid price");}
            return _price;
        }
        Product &operator=(const Product &other)=default;
        bool operator==(const Product &other){
            if(this->_name == other._name){
                return true;
            }else{
                return false;
            }
        };
};

#endif