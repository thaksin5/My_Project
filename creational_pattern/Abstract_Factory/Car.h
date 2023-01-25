#ifndef CAR
#define CAR

#include <iostream>
#include <string>

class Tire{
    protected:
        std::string _name="";
        int _pressure=-1;
    public:
        Tire()=default;
        Tire(std::string name, int pressure):_name(name), _pressure(pressure){}
        std::string getName(){ return _name;}
        int getPressure(){ return _pressure;}
        ~Tire(){}
};

class Body{
    protected:
        std::string _name="";
        int _strength = -1;
    public:
        Body()=default;
        Body(std::string name, int strength):_name(name), _strength(strength){}
        std::string getName(){ return _name;}
        int getStrength(){ return _strength;}
        ~Body(){}
};

// ---------------------------------------------------------------------

// Tire
class SimpleTire:public Tire{
    public:
        SimpleTire():Tire("SimpleTire", 75){}
};
class LuxuryTire:public Tire{
    public:
        LuxuryTire():Tire("LuxuryTire", 100){}
};

// Body
class SimpleBody:public Body{
    public:
        SimpleBody():Body("SimpleBody", 75){}
        ~SimpleBody(){}
};

class LuxuryBody:public Body{
    public:
        LuxuryBody():Body("LuxuryBody", 100){}
        ~LuxuryBody(){}
};


class Car{
    protected:
        std::string _name = "";
        Tire _tire;
        Body _body;
    public:
        Car()=default;
        Car(std::string name):_name(name){}
        void setTire(Tire tire){ _tire = tire;}
        void setBody(Body body){ _body = body;}
        void printDetail(){
            std::cout<<"Car:"<<_name<<std::endl;
            std::cout<<"Tire:"<<_tire.getName()<<" Pressure:"<<_tire.getPressure()<<std::endl;
            std::cout<<"Body:"<<_body.getName()<<" Strength:"<<_body.getStrength()<<std::endl;
        }
        ~Car(){}
};

#endif