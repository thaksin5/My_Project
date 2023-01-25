#include <iostream>
#include <memory>

class ThaiSocket{
    public:
        virtual void thaiCharge(int type)=0;
};

class USASocket{
    public:
        void USACharge(){
            std::cout<<"USA plug is charging"<<std::endl;
        }
};

class JapanSocket{
    public:
        void JapanCharge(){
            std::cout<<"Japan plug is charging"<<std::endl;
        }
};

class EuropeSocket{
    public:
        void EUCharge(){
            std::cout<<"EU plug is charging"<<std::endl;
        }
};

class InternationalSocket:public ThaiSocket, public USASocket, public JapanSocket, public EuropeSocket{
    public:
        void thaiCharge(int type){
            switch(type){
                case 0:
                    std::cout<<"Exit"<<std::endl;
                    break;
                case 1:
                    USACharge();
                    break;
                case 2:
                    JapanCharge();
                    break;
                case 3:
                    EUCharge();
                    break;
                default:
                    std::cout<<"Please enter following number (1.USA 2.Japan 3.Europe)"<<std::endl;
                    break;
            }
        }
};

int main(){
    std::unique_ptr<ThaiSocket> socket = std::make_unique<InternationalSocket>();
    // socket->thaiCharge(1);
    // socket->thaiCharge(2);
    // socket->thaiCharge(3);
    int type;
    while(true){
        std::cin>>type;
        socket->thaiCharge(type);
        if(type == 0){ break;}
    }       

    return 0;
}