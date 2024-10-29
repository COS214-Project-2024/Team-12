#ifndef WASTEMANAGEMENT_H
#define WASTEMANAGEMENT_H

#include "../src/City/CityComponent/Utility/UtilityFlyweight.h"

class WasteManagement : public UtilityFlyweight {
public:
    WasteManagement() = default;
    WasteManagement(const std::string& n, double c, int cap, double radius, bool operational, int l, int consumption, const std::map<std::string, int>& resources);
    void connect(double distance);
    std::unique_ptr<UtilityFlyweight> clone() const;
};

#endif