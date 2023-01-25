#pragma once

#include "builder.h"

class Director{
    public:
        House *buildHouse(HouseBuilder *builder){
            builder->buildHouseType();
            builder->buildWindow();
            builder->buildDoor();
            builder->buildRoom();
            builder->buildGarage();
            builder->buildGarden();
            builder->buildPool();
            builder->buildStatue();
            return builder->getHouse();
        }
};