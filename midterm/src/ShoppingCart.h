#include "Product.h"

class ShoppingCart{
    private:
        Product *_item_list = nullptr;        
        int _item_list_size = 0;
    public:
        ShoppingCart()=default;
        ShoppingCart(int item_list_size, Product *item_list){
            for(int i=0; i<item_list_size-1; i++){
                for(int j=i+1; j<item_list_size; j++){
                    if(item_list[i] == item_list[j]){
                        throw std::string("duplicate product");
                    }
                }
            }
            _item_list_size = item_list_size;
            _item_list = new Product[_item_list_size];
            for(int i=0; i<item_list_size; i++){
                _item_list[i] = item_list[i];
            }
        }
        int getItemCount() const{
            return _item_list_size;
        }
        Product getItemByIndex(int index){
            if(index >= _item_list_size){
                throw std::string("out of range");
            }
            return _item_list[index];
        }
        void setItemByIndex(int index, Product product){
            if(index >= _item_list_size){
                throw std::string("invalid index");
            }
            for(int i=0; i<_item_list_size; i++){
                if((_item_list[i] == product)){
                    throw std::string("duplicate product");
                }
            }
            _item_list[index] = product;
        }
        void appendItem(Product product){
            for(int i=0; i<_item_list_size; i++){
                if(_item_list[i] == product){
                    throw std::string("duplicate product");
                }
            }
            _item_list_size++;
            Product *new_item_list = new Product[_item_list_size];
            for(int i=0; i<_item_list_size-1; i++){ new_item_list[i] = _item_list[i];}
            delete[] _item_list;
            _item_list = new_item_list;
            _item_list[_item_list_size-1] = product;
        }
        int getTotalCost() const{
            int sum = 0;
            for(int i=0; i<_item_list_size; i++){
                sum += _item_list[i].getPrice();
            }
            return sum;
        }
        ShoppingCart &operator=(const ShoppingCart &other){
            if(this != &other){
                this->_item_list_size = other._item_list_size;
                delete[] _item_list;
                this->_item_list = new Product[_item_list_size];
                for(int i=0; i<_item_list_size; i++){
                    this->_item_list[i] = other._item_list[i];
                }
            }
            return *this;
        }
        int findDup(Product *arr, int size, Product target){
            int dup = 0;
            for(int i=0; i<size; i++){
                if(arr[i] == target){
                    dup = 1;
                    break;
                }
            }
            return dup;
        }
        ShoppingCart operator+(const ShoppingCart &other){
            ShoppingCart newCart;
            for(int i=0; i<_item_list_size; i++){
                newCart.appendItem(_item_list[i]);
            }
            // find dup
            for(int i=0; i<other._item_list_size; i++){
                Product target = other._item_list[i];
                if(findDup(_item_list, _item_list_size, target)==0){
                    newCart.appendItem(target);
                }
            }
            return newCart;
        }
        ShoppingCart operator-(const ShoppingCart &other){
            ShoppingCart newCart;
            // find dup
            for(int i=0; i<_item_list_size; i++){
                Product target = _item_list[i];
                if(findDup(other._item_list, other._item_list_size, target)==0){
                    newCart.appendItem(target);
                }
            }
            return newCart;
        }
        ~ShoppingCart(){
            delete[] _item_list;
        }
};