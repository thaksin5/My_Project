#ifndef BEEF
#define BEEF

#include "sandwich.h"
#include <set>

class BeefSandwich:public Sandwich{
    public:
        static std::set<int> _beef_record;
        BeefSandwich()=default;
        BeefSandwich(int price, int id):Sandwich(price, id){
            if(price<0){
                throw std::invalid_argument("invalid price");
            }
            _record.insert(id);
            _beef_record.insert(id);
        };
        static bool record_has_specific_id(int id){
            bool exist = _beef_record.find(id) != _beef_record.end();
            return exist;
        }
        static int get_size_of_record_container(){
            return _beef_record.size();
        }
        ~BeefSandwich(){
            _record.erase(_id);
            _beef_record.erase(_id);
        }
};

std::set<int> BeefSandwich::_beef_record = {};

#endif