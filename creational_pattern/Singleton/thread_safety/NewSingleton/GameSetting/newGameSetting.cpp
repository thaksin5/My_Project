#include <iostream>
#include <thread>
#include <vector>

class GameSetting{
    private:
        static GameSetting &_setting;
        int _brightness;
        int _width;
        int _height;
        GameSetting(): _width(786), _height(1300), _brightness(75){
            std::cout<<"create setting"<<std::endl;
        }
        ~GameSetting(){}
    public:
        static GameSetting &getInstance(){
            static GameSetting _setting;
            return _setting;
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


int main(){ 
    std::vector<std::thread> threads;
    for(int i=0; i<10; i++){
        threads.emplace_back(std::thread([](){
            GameSetting::getInstance();
        }));
    }

    for(auto& t : threads){
        if(t.joinable()){
            t.join();
        }
    }

    GameSetting &gamesetting = GameSetting::getInstance();
    std::cout<<gamesetting.getHeight()<<std::endl;
    return 0;
}