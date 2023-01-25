#include <iostream>
#include <string>

class GameSetting{
    private:
        static GameSetting *_instance;
        int _brightness;
        int _width;
        int _height;
        GameSetting(): _width(786), _height(1300), _brightness(75){}
    public:
        static GameSetting *getInstance(){
            if(_instance == NULL){
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
GameSetting *GameSetting::_instance = NULL;

void someFunction(){
    GameSetting *setting = GameSetting::getInstance();
    setting->displaySetting();
}

int main(){
    GameSetting *setting = GameSetting::getInstance();
    setting->displaySetting(); 

    std::cout<<"->After changed setting"<<std::endl;
    setting->setWidth(1920);
    setting->setHeight(1080);
    someFunction(); // reuse the obj from class 
    return 0;
}