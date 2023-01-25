#include <iostream>
#include <string>
#include <thread>
#include <vector>
#include <mutex>

class GameSetting{
    private:
        static GameSetting *_instance;
        static std::mutex _mtx;
        int _brightness;
        int _width;
        int _height;    
        GameSetting():_brightness(60), _width(1920), _height(1080){
            std::cout<<"Created setting"<<std::endl;
        }
    public:
        static GameSetting *getInstance(){
            std::lock_guard<std::mutex> lock(_mtx);
            if(_instance == nullptr){
                _instance = new GameSetting();
            }
            return _instance;
        }
        void setWidth(int width){ _width = width;}
        void setHeight(int height){ _height = height;}
        void setBrightness(int braghtness){ _brightness = _brightness;}
        int getWidth(){ return _width;}
        int getHeight(){ return _height;}
        int getBrightness(){ return _brightness;}
        void displaySetting(){
            std::cout<<"Brightness : "<<_brightness<<std::endl;
            std::cout<<"Height : "<<_height<<std::endl;
            std::cout<<"Width : "<<_width<<std::endl;
        }
};
GameSetting *GameSetting::_instance = nullptr;
std::mutex GameSetting::_mtx;


int main(){
    int brightness;
    std::vector<std::thread> threads;
    for(int i=0; i<10; i++){
        threads.emplace_back(std::thread([](){
            GameSetting::getInstance();
        }));
    }

    for(auto& t:threads){
        if(t.joinable()){
            t.join();
        }
    }

    GameSetting *setting = GameSetting::getInstance();
    setting->displaySetting();

    delete setting;
    
    return 0;
}