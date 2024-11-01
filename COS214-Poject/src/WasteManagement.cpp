#include "WasteManagement.h"

WasteManagement::   WasteManagement() : UtilityFlyweight(
    "Waste Management", // name
    125.0,             // cost - lowest cost
    50,                // capacity - moderate capacity
    2.0,               // radius - smallest coverage
    true,              // operational
    1,                 // level
    5,                 // consumption - lowest resource usage
    {{"Steel", 20}, {"Plastic", 30}}  // simpler resources
) {}

WasteManagement::WasteManagement(const std::string& n, double c, int cap, double radius, bool operational, int l, int consumption, const std::map<std::string, int>& resources)
        : UtilityFlyweight(n, c, cap, radius, operational, l, consumption, resources) {}

void WasteManagement::connect(double distance){
    if (isOperational && distance <= effectRadius) {
        std::cout << name << " collecting waste within range.\n";
    } else {
        std::cout << "Out of range of the WasteManagement.\n";
    }
}

std::shared_ptr<UtilityFlyweight> WasteManagement::clone() const  {
    return std::make_shared<WasteManagement>(*this);
}