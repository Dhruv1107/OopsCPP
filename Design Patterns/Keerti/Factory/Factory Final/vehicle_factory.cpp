#include "vehicle_factory.hpp"

Vehicle* VehicleFactory::getVehicle(string vehicleType) {
    Vehicle *vehicle;
    if (vehicleType == "car") {
        vehicle = new Car();
    } 
    else if (vehicleType == "bike") {
        vehicle = new Bike();
    }
    // you can add if else over here without making any changes to client
    return vehicle;
}