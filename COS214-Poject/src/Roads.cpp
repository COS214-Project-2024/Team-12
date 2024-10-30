#include <iostream>
#include <string>
#include "Roads.h"

/* Roads::Roads(int cap, double cost, double maintenanceC, std::string name, int trafficC, roadType road) 
    : Transport(2000, 1000000, 15000, "Road") {
    this->trafficCapacity = trafficC;
    this->road = road;
} */

std::unique_ptr<Transport> Roads::clone() const {
    return std::make_unique<Roads>(*this);
}

double Roads::getCapacity() const{
    return 200;
}

double Roads::getCost()const{
    return 800;
}

double Roads::getMaintainanceCost() const{
    return 10;
}

double Roads::getSpeed() const{
    return 60;
}

std::string Roads::getType() const{
    return "Road";
}
