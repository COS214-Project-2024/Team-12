#include <iostream>
#include <string>
#include "Trains.h"

std::unique_ptr<Transport> Trains::clone() const {
    return std::make_unique<Trains>(*this);
}


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