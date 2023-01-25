#include <iostream>
#include <string>

class Plane{
    private:
        std::string _planeType;
        std::string _body;
        std::string _engine;
    public:
        Plane(std::string planeType): _planeType(planeType){}
        void setEngine(std::string engine){ _engine = engine;}
        void setBody(std::string body){ _body = body;}
        std::string getEngine(){ return _engine;}
        std::string getBody(){ return _body;}
        void display(){
            std::cout<<"Plane Type : "<<_planeType<<std::endl
                <<"Body Type : "<<_body<<std::endl
                <<"Engine Type : "<<_engine<<std::endl;
        }
};

class PlaneBuilder{
    protected:
        Plane *_plane;
    public:
        Plane* getPlane(){ return _plane;}
        virtual void buildPlaneType()=0;
        virtual void buildBody()=0;
        virtual void buildEngine()=0;
};

class PropellerBuilder: public PlaneBuilder{
    public:
        void buildPlaneType(){ _plane = new Plane("Propeller Plane");}
        void buildEngine(){ _plane->setEngine("Propeller Engine");}
        void buildBody(){ _plane->setBody("Propeller Body");}
};      

class JetBuilder: public PlaneBuilder{
    public:
        void buildPlaneType(){ _plane = new Plane("Jet Plane");}
        void buildEngine(){ _plane->setEngine("Jet Engine");}
        void buildBody(){ _plane->setBody("Jet Body");}
};

class Director{
    public:
        Plane *createPlane(PlaneBuilder *builder){
            builder->buildPlaneType();
            builder->buildEngine();
            builder->buildBody();
            return builder->getPlane();
        }      
};

int main(){
    Director dir;
    JetBuilder j;
    PropellerBuilder p;

    Plane *jet = dir.createPlane(&j);
    Plane *propeller = dir.createPlane(&p);

    jet->display();
    propeller->display();

    delete jet;
    delete propeller;

    return 0;
}