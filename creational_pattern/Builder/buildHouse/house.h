#pragma once

#include <iostream>
#include <string>

class House{
    private:
        std::string _houseType;
        int _window;
        int _door;
        int _room;
        bool _garage;
        bool _garden;
        bool _pool;
        bool _statue;
    public:
        House(std::string houseType):_houseType(houseType){}
        void setWindow(int window){ _window = window;}
        void setDoor(int door){ _door = door;}
        void setRoom(int room){ _room = room;}
        void setGarage(bool garage){ _garage = garage;}
        void setGarden(bool garden){ _garden = garden;}
        void setPool(bool pool){ _pool = pool;}
        void setStatue(bool statue){ _statue = statue;}

        int getWindow(){ return _window;}
        int getDoor(){ return _door;}
        int getRoom(){ return _room;}
        bool getGarage(){ return _garage;}
        bool getGarden(){ return _garden;}
        bool getPool(){ return _pool;}
        bool getStatue(){ return _statue;}

        void display(){
            std::cout<<"House Type:"<<_houseType<<std::endl
                    <<"Window:"<<_window<<std::endl
                    <<"Door:"<<_door<<std::endl
                    <<"Room:"<<_room<<std::endl
                    <<"Garage:"<<_garage<<std::endl
                    <<"Garden:"<<_garden<<std::endl
                    <<"Pool:"<<_pool<<std::endl
                    <<"Statue:"<<_statue<<std::endl;
            std::cout<<"--------------------------------"<<std::endl;
        }
};