#include <iostream>
#include <string>

#include "director.h"
// #include "builder.h"

int main(){
    Director dir;
    HouseWithGarage garage;
    HouseWithGarden garden;
    HouseWithPool pool;

    House *garage_house = dir.buildHouse(&garage); // can pass by reference because derieved class is instance of base class
    House *garden_house = dir.buildHouse(&garden);
    House *pool_house = dir.buildHouse(&pool);

    garage_house->display();
    garden_house->display();
    pool_house->display();

    delete garage_house;
    delete garden_house;
    delete pool_house;

    return 0;
}