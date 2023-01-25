#pragma once

#include "house.h"

class HouseBuilder{
    protected:
        House *_house;
    public:
        House* getHouse(){ 
            return _house;
        }
        virtual void buildHouseType()=0;
        virtual void buildWindow()=0;
        virtual void buildDoor()=0;
        virtual void buildRoom()=0;
        virtual void buildGarage()=0;
        virtual void buildGarden()=0;
        virtual void buildPool()=0;
        virtual void buildStatue()=0;
};

class HouseWithGarage:public HouseBuilder{
    public:
        void buildHouseType()override{ _house = new House("House with garage");}
        void buildWindow()override{ _house->setWindow(4);}
        void buildDoor()override{ _house->setDoor(2);}
        void buildRoom()override{ _house->setRoom(4);}
        void buildGarage()override{ _house->setGarage(true);}
        void buildGarden()override{ _house->setGarden(false);}
        void buildPool()override{ _house->setPool(false);}
        void buildStatue()override{ _house->setStatue(false);}
};

class HouseWithGarden:public HouseBuilder{
    public:
        void buildHouseType()override{ _house = new House("House with garden");}
        void buildWindow()override{ _house->setWindow(4);}
        void buildDoor()override{ _house->setDoor(2);}
        void buildRoom()override{ _house->setRoom(3);}
        void buildGarage()override{ _house->setGarage(false);}
        void buildGarden()override{ _house->setGarden(true);}
        void buildPool()override{ _house->setPool(false);}
        void buildStatue()override{ _house->setStatue(true);}
};

class HouseWithPool: public HouseBuilder{
    public:
        void buildHouseType()override{ _house = new House("House with pool");}
        void buildWindow()override{ _house->setWindow(2);}
        void buildDoor()override{ _house->setDoor(2);}
        void buildRoom()override{ _house->setRoom(1);}
        void buildGarage()override{ _house->setGarage(false);}
        void buildGarden()override{ _house->setGarden(false);}
        void buildPool()override{ _house->setPool(true);}
        void buildStatue()override{ _house->setStatue(false);}
};