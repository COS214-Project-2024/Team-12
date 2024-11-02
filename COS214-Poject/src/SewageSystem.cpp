#include "SewageSystem.h"

SewageSystem::SewageSystem() : UtilityFlyweight(
    "Sewage System",   // name
    175.0,            // cost - moderately high
    40,               // capacity - lower capacity
    2.5,              // radius - smaller coverage
    true,             // operational
    1,                // level
    8,                // consumption - lower resource usage
    {{"Steel", 30}, {"Plastic", 40}, {"Concrete", 20}}  // varied resources
) {}

SewageSystem::SewageSystem(const std::string& n, double c, int cap, double radius, bool operational, int l, int consumption, const std::map<std::string, int>& resources)
        : UtilityFlyweight(n, c, cap, radius, operational, l, consumption, resources) {}

void SewageSystem::connect(double distance) {
    if (isOperational && distance <= effectRadius) {
        std::cout << name << " managing sewage within range.\n";
    } else {
        std::cout << "Out of range of the SewageSystem.\n";
    }
}

std::shared_ptr<UtilityFlyweight> SewageSystem::clone() const {
    return std::make_shared<SewageSystem>(*this);
}