#include "PowerPlant.h"

PowerPlant::PowerPlant() : UtilityFlyweight(
    "Power Plant",     // name
    200.0,            // cost - highest cost due to importance
    100,              // capacity - highest capacity
    4.0,              // radius - largest coverage
    true,             // operational
    1,                // level
    15,               // consumption - high resource usage
    {{"Steel", 60}, {"Copper", 40}, {"Coal", 30}}  // more complex resources
){}

PowerPlant::PowerPlant(const std::string& n, double c, int cap, double radius, bool operational, int l, int consumption, const std::map<std::string, int>& resources)
        : UtilityFlyweight(n, c, cap, radius, operational, l, consumption, resources) {}

void PowerPlant::connect(double distance) {
    if (isOperational && distance <= effectRadius) {
        std::cout << name <<" providing power within range.\n";
    } else {
        std::cout << "Out of range of the PowerPlant.\n";
    }
}

std::shared_ptr<UtilityFlyweight> PowerPlant::clone() const{
    return std::make_shared<PowerPlant>(*this);
}