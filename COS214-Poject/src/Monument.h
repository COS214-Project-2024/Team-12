#ifndef MONUMENT_H
#define MONUMENT_H

#include "LandMark.h"

class Monument : public LandMark {
public:
    Monument(const std::string& type, int  capacity, double price, std::shared_ptr<UtilityFlyweight> water, std::shared_ptr<UtilityFlyweight> power,
        std::shared_ptr<UtilityFlyweight> waste, std::shared_ptr<UtilityFlyweight> sewage);
    ~Monument();
    void displayStatus();
    std::unique_ptr<LandMark> clone() const;
};

#endif