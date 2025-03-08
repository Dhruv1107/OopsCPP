#include<iostream>
using namespace std;

class ICar {
    public:
        virtual void drift() = 0;
};

class IBike {
    public:
        virtual void wheelie() = 0;
};

class IVehicleFactory {
    public:
        virtual ICar* createCar() = 0;
        virtual IBike* createBike() = 0;
};


class HyundaiCar: public ICar {
    public:
        void drift() {
            cout<<"Hyundai drift"<<endl;
        }
};

class ToyotaCar: public ICar {
    public:
        void drift() {
            cout<<"Toyota drift"<<endl;
        }
};

class HyundaiBike: public IBike {
    public:
        void wheelie() {
            cout<<"Hyundai wheelie"<<endl;
        }
};

class ToyotaBike: public IBike {
    public:
        void wheelie() {
            cout<<"Toyota wheelie"<<endl;
        }
};

class HyundaiFactory: public IVehicleFactory {
    public:
        ICar* createCar() override{
            return new HyundaiCar();
        }
        IBike* createBike() override{
            return new HyundaiBike();
        }
};

class ToyotaFactory: public IVehicleFactory {
    public:
        ICar* createCar() override{
            return new ToyotaCar();
        }
        IBike* createBike() override{
            return new ToyotaBike();
        }
};

class CarAbstractFactory {
    public:
        static IVehicleFactory* CreateFactory(string carType) {
            if(carType == "hyundai") {
                return new HyundaiFactory();
            } else if(carType == "toyota") {
                return new ToyotaFactory();
            } else {
                return new HyundaiFactory();
            }
        }
};


int main() {
    cout<<"Enter your Car Brand"<<endl;
    string carType;
    cin>>carType;

    IVehicleFactory* vf = CarAbstractFactory::CreateFactory(carType);
    
    ICar* car = vf->createCar();
    car->drift();

    IBike* bike = vf->createBike();
    bike->wheelie();

    return 0;
}