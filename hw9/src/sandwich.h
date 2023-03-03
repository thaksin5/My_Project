#ifndef SANDWICH
#define SANDWICH
// or use pragma once

#include <set>

class Sandwich{
    protected:
        int _price = -1;
        int _id = -1;
    public:
        static std::set<int> _record;
        Sandwich()=default;
        Sandwich(int price, int id):_price(price), _id(id){
            if(price < 0){
                throw std::invalid_argument("invalid price");
            }
            _record.insert(_id);
        }
        int get_price(){    
            return _price;
        }
        int get_id(){
            return _id;
        }
        static bool record_has_specific_id(int id){
            bool exist = _record.find(id) != _record.end();
            return exist;
        }
        static int get_size_of_record_container(){
            return _record.size();
        }
        ~Sandwich(){
            _record.erase(_id);
        }
};

std::set<int> Sandwich::_record = {};

#endif
