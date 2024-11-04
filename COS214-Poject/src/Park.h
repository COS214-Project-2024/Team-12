#ifndef PARK_H
#define PARK_H

#include "LandMark.h"

class Park : public LandMark {
public:
    Park(const std::string& type, int  capacity, double price, std::shared_ptr<UtilityFlyweight> water, std::shared_ptr<UtilityFlyweight> power,
        std::shared_ptr<UtilityFlyweight> waste, std::shared_ptr<UtilityFlyweight> sewage);
    ~Park();
    void displayStatus() override;
    std::unique_ptr<LandMark> clone() const;
    std::string getBuildingType() const;
};

#endif