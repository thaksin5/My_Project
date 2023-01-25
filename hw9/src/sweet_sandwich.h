#ifndef SWEET
#define SWEET

#include "../src/sandwich.h"

class SweetSandwich:public Sandwich{
    public:
        static std::set<int> _sweet_record;
        SweetSandwich()=default;
        SweetSandwich(int price, int id):Sandwich(price, id){
            if(price<0){
                throw std::invalid_argument("invalid price");
            }
            _record.insert(id);
            _sweet_record.insert(id);
        };
        static bool record_has_specific_id(int id){
            bool exist = _sweet_record.find(id) != _sweet_record.end();
            return exist;
        }
        static int get_size_of_record_container(){
            return _sweet_record.size();
        }
        ~SweetSandwich(){
            _record.erase(_id);
            _sweet_record.erase(_id);
        }
};

std::set<int> SweetSandwich::_sweet_record = {};

#endif