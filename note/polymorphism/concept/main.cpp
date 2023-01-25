#include <iostream>
using namespace std;

class base{
    public:
        void print(){
            cout<<"print base class"<<endl;
        }
        virtual void show(){ // allow to do polymorphism
            cout<<"show base case"<<endl;
        }
};


class derieve:public base{
    public:
        void print(){
            cout<<"print derieve class"<<endl;
        }
        void show(){
            cout<<"show derieve class"<<endl;
        }
};

int main(){
    base *b;
    derieve d;
    b = &d;

    b->print();
    b->show();    

    return 0;
}
