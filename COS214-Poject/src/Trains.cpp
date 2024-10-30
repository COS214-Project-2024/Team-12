#include <iostream>
#include <string>
#include "Trains.h"

double Trains::getCapacity() const{
    return 500;
}

double Trains::getCost()const{
    return 1000;
}

double Trains::getMaintainanceCost() const{
    return 50;
}

double Trains::getSpeed() const{
    return 100;
}

std::string Trains::getType() const{
    return "Train";
}