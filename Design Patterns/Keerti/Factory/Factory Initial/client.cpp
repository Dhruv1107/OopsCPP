#include <iostream>
#include "car.hpp"
#include "bike.hpp"
using namespace std;

int main() {
    string vehicleType;
    cin >> vehicleType;
    Vehicle *vehicle;
    if (vehicleType == "car") {
        vehicle = new Car();
    } 
    else if (vehicleType == "bike") {
        vehicle = new Bike();
    }
    // Everytime we change anything in the library we need to tell the client to include the hpp files and add the 
    // if else statements for different types of vehicles
    // Here when we change the vechile library we need to change the client, it is tightly coupled
    // The client should not be bothered what we are doing with the library.
    // So we are going to create a factory => it will take care of entire creation logic without exposing to client
    vehicle->createVehicle();
    return 0;
}
