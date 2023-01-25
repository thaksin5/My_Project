#ifndef ORDER
#define ORDER

#include "alcohol.h"
#include <vector>

class Order{
    protected:
        std::vector<Alcohol*> alcohol_list;
    public:
        Order()=default;
        void append_alcohol(Alcohol* alcohol){
            alcohol_list.push_back(alcohol);
        }
        int get_alcohol_count(){
            return alcohol_list.size();
        }

        int get_total_price(){
            int total = 0;
            for(int i=0; i<alcohol_list.size(); i++){
                total += alcohol_list[i]->get_price();
            }
            return total;
        }
        ~Order(){
            alcohol_list.clear();
        }
};

#endif