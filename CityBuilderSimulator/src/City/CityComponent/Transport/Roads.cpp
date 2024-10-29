#include <iostream>
#include "Roads.h"

Roads::Roads(int cap, double cost, double maintenanceC, std::string name, int trafficC, roadType road) 
    : Transport(2000, 1000000, 15000, "Road") {
    this->trafficCapacity = trafficC;
    this->road = road;
}

std::unique_ptr<Transport> Roads::clone() const {
    return std::make_unique<Roads>(*this);
}
