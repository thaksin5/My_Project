#include <iostream>
#include <thread>
#include <vector>

// we use reference(&) instead of pointer 
/*
    because pointer can be assigned nullptr,
    whereas a reference must be bound to an existing object
    that make thread safe
*/

class Singleton{
    private:
        Singleton(){
            std::cout<<"Created"<<std::endl;
        }
        ~Singleton(){
            std::cout<<"Destroyed"<<std::endl;
        }
    public:
        static Singleton& createInstance(){
            static Singleton instance; // no new obj creation, no store in the heap
            return instance;
        }
};

// no need to mutex lock because there's no object creation

int main(){
    std::vector<std::thread> threads;
    for(int i=0; i<10; i++){
        threads.emplace_back(std::thread([](){
            Singleton::createInstance(); 
        }));
        // threads.emplace_back(std::thread(Singleton::createInstance()));
    }

    for(auto& t : threads){
        if(t.joinable()){
            t.join();
        }
    }

}`