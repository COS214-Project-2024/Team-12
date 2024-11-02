#ifndef WASTEMANAGEMENT_H
#define WASTEMANAGEMENT_H

#include "UtilityFlyweight.h"

class WasteManagement : public UtilityFlyweight {
public:
    WasteManagement();
    WasteManagement(const std::string& n, double c, int cap, double radius, bool operational, int l, int consumption, const std::map<std::string, int>& resources);
    void connect(double distance);
    std::shared_ptr<UtilityFlyweight> clone() const;
};

#endif