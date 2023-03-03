#ifndef DRINK
#define DRINK
#include <string>
#include <vector>

class Drink{
    private:
        std::string _name;
        double _sLevel;
        std::vector<std::string> _topping;
        int _topping_pos = 0;
    public:
        Drink(std::string name="", double sLevel=-1);
        ~Drink();
        std::string getName();
        double getSweetnessLevel();
        void addTopping(std::string topping);
        int getToppingCount();
        std::string getToppingByIndex(int index);
};

#endif