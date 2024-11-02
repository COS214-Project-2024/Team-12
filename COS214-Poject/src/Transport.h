//ABSTRACT PRODUCT/PROTOTYPE
#ifndef TRANSPORT_H
#define TRANSPORT_H
#include <iostream>
#include <memory>
#include <string>

#include "CityComponent.h"

class Transport {
private:
    /* int capacity;
    double cost;
    double maintainanceCost;
    std::string name;
    double speed; */

public:
    virtual double getCost() const = 0;
    virtual double getMaintainanceCost() const = 0;
    virtual double getSpeed() const = 0;
    virtual double getCapacity() const = 0;
    virtual std::string getType() const = 0;

    virtual std::unique_ptr<Transport> clone() const = 0;

    virtual ~Transport() = default;

};
#endif