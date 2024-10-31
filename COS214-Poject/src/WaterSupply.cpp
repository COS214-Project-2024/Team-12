#include "WaterSupply.h"

//WaterSupply::WaterSupply():UtilityFlyweight("WaterSupply", 800, 60, 12.0, true, 1, 10, {{"Steel", 40}, {"Plastic", 20}}) {}

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