#include <iostream>
#include <string>
#include <memory>
using namespace std;

/*
    unique pointer is a pointer that have own pointer, which mean cannot
share to another
*/
class Car{
    private:
        string _name;
    public:
        Car(string name):_name(name){}
        void check_null(){
            if(this == nullptr){
                cout<<"True"<<endl;
            }else{ cout<<"False"<<endl;}
        }
        void display(){
            cout<<"Name : "<<_name<<endl;
        }
};

int main(){
    unique_ptr<Car> c1(new Car("Porche"));
    unique_ptr<Car> c2 = make_unique<Car>("Toyota");
    
    // c1 = c2; fail, because cannot copy ownership each other

    unique_ptr<Car> c3 = move(c2); // pass, we can move ownership from c2 to c3
    c3->display(); // c3 have c2 ownership, but c2 is null pointer because it already moved to c3
    c2->check_null(); // c2 is null pointer

    return 0;
}