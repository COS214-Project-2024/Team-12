#include "WaterSupply.h"

WaterSupply::    WaterSupply() : UtilityFlyweight(
    "Water Supply",    // name
    150.0,            // cost - moderate cost
    60,               // capacity - can serve many buildings
    3.0,              // radius - moderate coverage
    true,             // operational
    1,                // level
    10,               // consumption - moderate resource usage
    {{"Steel", 40}, {"Plastic", 20}}  // basic resources needed
) {}

WaterSupply::WaterSupply(const std::string& n, double c, int cap, double radius, bool operational, int l, int consumption, const std::map<std::string, int>& resources)
        : UtilityFlyweight(n, c, cap, radius, operational, l, consumption, resources) {}

void WaterSupply::connect(double distance){
    if (isOperational && distance <= effectRadius) {
        std::cout << name << " providing water within range.\n";
    } else {
        std::cout << "Out of range of the WaterSupply.\n";
    }
}

std::shared_ptr<UtilityFlyweight> WaterSupply::clone() const{
    return std::make_shared<WaterSupply>(*this);
}