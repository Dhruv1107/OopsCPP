#include "vehicle_factory.hpp"
#include <iostream>

using namespace std;

int main() {
    string vehicleType;
    cin >> vehicleType;
    // Client uses the factory to create a product
    Vehicle* vehicle = VehicleFactory::getVehicle(vehicleType);
    vehicle->createVehicle();
    return 0;
}
