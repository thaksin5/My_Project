#include <iostream>

/* 
friend class, friend function => allow to access private and protected member 
    of other class that declare as friend.
*/

class Node{
    private:
        int key;
        Node *next;
        friend class LinkedList;
};

// friend class
class LinkedList{

};

// ---------------------------------------------------------

// friend function
class Largest{
    private:
        int a,b;
    public:
        void set_data(){
            std::cout<<"Enter a : ";
            std::cin>>a;
            std::cout<<"Enter b : ";
            std::cin>>b;               
        }
        void display(){
            std::cout<<a<<std::endl;
            std::cout<<b<<std::endl;
        }
        friend void find_max(Largest l){
            if(l.a > l.b){
                std::cout<<"max value is a"<<std::endl;
            }
            else if(l.a < l.b){
                std::cout<<"max value is b"<<std::endl;
            }
            else{
                std::cout<<"both are equal"<<std::endl;
            }
        }
};

int main(){
    Largest l;

    l.set_data();
    find_max(l);
    return 0;
}