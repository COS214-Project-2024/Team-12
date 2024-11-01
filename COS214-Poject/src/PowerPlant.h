#ifndef POWERPLANT_H
#define POWERPLANT_H

#include "UtilityFlyweight.h"

class PowerPlant : public UtilityFlyweight {
public:
    PowerPlant();
    PowerPlant(const std::string& n, double c, int cap, double radius, bool operational, int l, int consumption, const std::map<std::string, int>& resources);
    void connect(double distance);
    std::shared_ptr<UtilityFlyweight> clone() const;
};

#endif