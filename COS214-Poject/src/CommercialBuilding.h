#ifndef COMMERCIALBUILDING_H
#define COMMERCIALBUILDING_H

#include <string>
#include "taxCollector.h"
#include "CityComponent.h"

class CommercialBuilding : public CityComponent {
private:
    double price;
    bool taxPayed;
    int capacity;

public:
    // Default arguments only in header
    CommercialBuilding(double initialPrice = 200000, int initialCapacity = 50);

    //void accept(taxCollector* TC) override;
    //void payTax();
    std::string getBuildingType() override;
    void displayStatus() override;

    // Getters
    double getPrice() const { return price; }
    int getCapacity() const { return capacity; }
    bool isTaxPayed() const { return taxPayed; }
};

#endif