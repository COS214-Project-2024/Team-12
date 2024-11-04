#ifndef COMMERCIALBUILDING_H
#define COMMERCIALBUILDING_H

#include "CityComponent.h"
#include <memory>
#include <string>

class UtilityFlyweight;
class Government;
class taxCollector;
class CommercialBuilding : public CityComponent {
protected:
    double price;
    bool taxPaid;

    // Utility connections
    std::shared_ptr<UtilityFlyweight> waterSupply;
    std::shared_ptr<UtilityFlyweight> powerSupply;
    std::shared_ptr<UtilityFlyweight> wasteManagement;
    std::shared_ptr<UtilityFlyweight> sewageManagement;

public:
    CommercialBuilding(double cost,
                    std::shared_ptr<UtilityFlyweight> water,
                    std::shared_ptr<UtilityFlyweight> power,
                    std::shared_ptr<UtilityFlyweight> waste,
                    std::shared_ptr<UtilityFlyweight> sewage);

    // Tax related methods
    void accept(taxCollector* TC) override;
    void setTaxPaid(bool paid);
    double getPrice() const { return price; }
    bool isTaxPaid() const { return taxPaid; }

    // Display methods
    std::string getBuildingType() const override;
    void displayStatus() override;
    virtual char getDisplaySymbol() const = 0;

    // Utility coverage
    int getUtilityCoverage() const;

    void setWaterSupply(std::shared_ptr<UtilityFlyweight> utility) { waterSupply = utility; }
    void setPowerSupply(std::shared_ptr<UtilityFlyweight> utility) { powerSupply = utility; }
    void setWasteManagement(std::shared_ptr<UtilityFlyweight> utility) { wasteManagement = utility; }
    void setSewageManagement(std::shared_ptr<UtilityFlyweight> utility) { sewageManagement = utility; }

    virtual std::string getDisplayColor() const {
        int coverage = getUtilityCoverage();
        std::cout << "Commercial coverage: " << coverage << " for " << getBuildingType() << std::endl;
        if (coverage == 4) {
            return "\033[1;33m"; // Yellow for full
        } else if (coverage >= 2) {
            return "\033[1;37m"; // White for partial
        } else {
            return "\033[1;31m"; // Red for insufficient
        }
    }
};

#endif