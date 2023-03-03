#ifndef FACTORY
#define FACTORY

#include <vector>

template <typename T>
class SandwichFactory{
    private:
        int _price = -1;
        int _id = -1;
    public:
        SandwichFactory(int price, int id):_price(price), _id(id){}
        static T* create_sandwich(int price, int id){
            T *new_obj = new T(price, id);
            return new_obj;
        }
        static std::vector<T*> create_sandwich_array(int price, int count, std::vector<int> id_list){
            if(count < 0 || price < 0){
                throw std::invalid_argument("invalid");
            }
            std::vector<T*> _obj_list;
            for(int i=0; i<count; i++){
                T *obj = create_sandwich(price, id_list[i]);
                _obj_list.push_back(obj);
            }
            return _obj_list;
        }
        ~SandwichFactory(){}
};

#endif