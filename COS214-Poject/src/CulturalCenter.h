#ifndef CULTURALCENTER_H
#define CULTURALCENTER_H

#include "LandMark.h"

class CulturalCenter : public LandMark {
public:
    CulturalCenter(const std::string& type, int  capacity, double price, std::shared_ptr<UtilityFlyweight> water, std::shared_ptr<UtilityFlyweight> power,
        std::shared_ptr<UtilityFlyweight> waste, std::shared_ptr<UtilityFlyweight> sewage);
    ~CulturalCenter();
    void displayStatus();
    std::unique_ptr<LandMark> clone() const;
};

#endif