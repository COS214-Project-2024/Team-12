#ifndef WATERSUPPLY_H
#define WATERSUPPLY_H

#include "UtilityFlyweight.h"

#include <memory>
#include <map>
#include <string>

class CityComponent;


class WaterSupply : public UtilityFlyweight {
public:
    WaterSupply();
    WaterSupply(const std::string& n, double c, int cap, double radius, bool operational, int l, int consumption, const std::map<std::string, int>& resources);
    void connect(double distance);
    std::shared_ptr<UtilityFlyweight> clone() const;
};

#endif