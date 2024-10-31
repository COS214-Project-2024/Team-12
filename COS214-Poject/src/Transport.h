//ABSTRACT PRODUCT/PROTOTYPE
#ifndef TRANSPORT_H
#define TRANSPORT_H
#include <iostream>
#include <memory>
#include <string>

#include "CityComponent.h"

class Transport : public CityComponent {
private:
    int capacity;
    double cost;
    double maintainanceCost;
    std::string name;

public:
    Transport(int cap, double cost, double maintenanceC, std::string name);
    virtual std::unique_ptr<Transport> clone() const = 0; // Pure virtual function for polymorphism

    virtual ~Transport() = default;

    void accept(taxCollector* TC) override;

    std::string getBuildingType() override{
        return "Transport";
    }

};
#endif