#ifndef COMMERCIALBUILDING_H
#define COMMERCIALBUILDING_H

#include <string>
#include "taxCollector.h"
#include "CityComponent.h"
#include "Government.h"

class CommercialBuilding : public CityComponent {
private:
    double price;
    bool taxPaid;
    int capacity;

public:
    // Default arguments only in header
    CommercialBuilding(double initialPrice = 200000, int initialCapacity = 50);

    void accept(taxCollector* TC) override;
    std::string getBuildingType() override;
    void displayStatus() override;
    void setTaxPaid(bool paid);

    // Getters
    double getPrice() const { return price; }
    int getCapacity() const { return capacity; }
    bool isTaxPaid() const { return taxPaid; }
};

#endif