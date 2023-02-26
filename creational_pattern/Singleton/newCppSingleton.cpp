#include <iostream>
using namespace std;

// new version is avoid memory leak and thread safe(c++11)
class GameSetting{
    private:
        int _width;
        int _height;
        GameSetting():_width(1920), _height(1080){}
        ~GameSetting(){};
    public:
        static GameSetting& getInstance(){
            static GameSetting instance;
            return instance;
        }
        void setWidth(int width){ _width = width;}
        void setHeight(int height){ _height = height;}
        void displayResolution(){
            char str[80] = {};
            sprintf(str,"Resolution : %d x %d", _width, _height);
            cout<<str<<endl;
        }
};

int main(){
    GameSetting &setting1 = GameSetting::getInstance();
    setting1.displayResolution();
    GameSetting &setting2 = GameSetting::getInstance();
    setting2.setWidth(800);
    setting2.setHeight(700);
    setting2.displayResolution();
    
    return 0;
}