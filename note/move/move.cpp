#include <iostream>
#include <string>

class Fruit{
    private:
        std::string _fruit_name = "";
        int _fruit_length = 0;
        int *_fruit_arr = nullptr;
    public:
        Fruit() = default;
        Fruit(std::string fruit_name){
            _fruit_name = fruit_name;
            _fruit_length = fruit_name.size();
            _fruit_arr = new int[_fruit_length];
        }
        // copy assignment
        Fruit &operator=(const Fruit &other){
            std::cout<<"copy assignment"<<std::endl;
            if(this != &other){
                delete[] _fruit_arr;
                _fruit_name = other._fruit_name;
                _fruit_length = other._fruit_length;
                _fruit_arr = new int[_fruit_length];
                for(int i=0; i<other._fruit_length; i++){
                    _fruit_arr[i] = other._fruit_arr[i];
                }
            }

            return *this;
        }
        // move assignment
        Fruit &operator=(Fruit &&other){
            std::cout<<"move assignment"<<std::endl;
            if(this != &other){
                delete[] _fruit_arr;
                _fruit_name = std::move(other._fruit_name);
                _fruit_length = std::move(other._fruit_length);
                _fruit_arr = std::move(other._fruit_arr);

                other._fruit_name = "";
                other._fruit_length = 0;
                other._fruit_arr = nullptr;
            }
            return *this;
        }
        void display(){
            std::cout<<_fruit_name<<std::endl;
        }
        ~Fruit(){
            delete[] _fruit_arr;
        }
};

int main(){
    Fruit apple("apple");
    Fruit banana;
    Fruit durian;
    
    apple.display();
    
    banana = apple;
    banana.display();

    durian = std::move(apple);
    durian.display();

    return 0;
}