#include <iostream>
#include <memory>

// 
class ThaiSocket{
    public:
        virtual void thaiCharge()=0;
};

// adaptee 
class USASocket{
    public:
        void usaCharge(){
            std::cout<<"USA plug is charging"<<std::endl;
        }
};

// adapter
// we can adapt to many types of charger
class SocketAdapter:public ThaiSocket, public USASocket{
    public:
        void thaiCharge() override {
            std::cout<<"USA plug is charge"<<std::endl;
        }
};

int main(){
    std::unique_ptr<ThaiSocket> socket = std::make_unique<SocketAdapter>();
    socket->thaiCharge();

    return 0;
}