#ifndef SEWAGESYSTEM_H
#define SEWAGESYSTEM_H

#include "UtilityFlyweight.h"

class SewageSystem : public UtilityFlyweight {
public:
    SewageSystem() = default;
    SewageSystem(const std::string& n, double c, int cap, double radius, bool operational, int l, int consumption, const std::map<std::string, int>& resources);
    void connect( double distance);
    std::shared_ptr<UtilityFlyweight> clone() const;
};

#endif // SEWAGE_SYSTEM_H