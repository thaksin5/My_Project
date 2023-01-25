#include <iostream>
#include <thread>
#include <vector>
#include <mutex>

class Singleton{
    private:
        static Singleton *_instance;
        static std::mutex _mtx;
        Singleton(){ std::cout<<"Created"<<std::endl;}
        ~Singleton(){ std::cout<<"Destroyed"<<std::endl;}
    public:
        static Singleton *createInstance(){
            std::lock_guard<std::mutex> lock(_mtx); // add mutex lock for avoid create one more time
            if(_instance == nullptr){
                _instance = new Singleton();
            }
            return _instance;
        }

        static void destroyInstance(){
            std::lock_guard<std::mutex> lock(_mtx);
            if(_instance != nullptr){
                delete _instance;
                _instance = nullptr;
            }
        }
};
Singleton *Singleton::_instance = nullptr;
std::mutex Singleton::_mtx;
// when we work with many thread, it can cause build more 1 instance
// so we need mutex lock
int main(){
    // create threads 
    std::vector<std::thread> threads;
    for(int i=0; i<10; i++){
        threads.emplace_back(std::thread([](){
            Singleton::createInstance(); 
            Singleton::destroyInstance();
        }));
    }

    for(auto& t : threads){
        if(t.joinable()){
            t.join();
        }
    }

    return 0;
}

// Problem is bad performance