#ifndef CAKE
#define CAKE

#include <string>

class Cake{
    protected:
        int _price = -1;
        int _sweet = -1;
    public: 
        static int _totalCake;
        Cake(){
            _totalCake+=1; 
        }
        // Cake(int price, int sweet):_price(price),_sweet(sweet){
        //     _totalCake+=1;
        // };
        int get_price(){
            return _price;
        }
        int get_sweet(){
            return _sweet;
        }
        static int get_total(){
            return _totalCake;
        }
        virtual std::string to_string() = 0;
        ~Cake(){
            _totalCake -= 1;
        }
};

int Cake::_totalCake; 

#endif