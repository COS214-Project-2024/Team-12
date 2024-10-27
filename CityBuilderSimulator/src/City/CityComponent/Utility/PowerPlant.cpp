#include "PowerPlant.h"

PowerPlant::PowerPlant(const std::string& n, double c, int cap, double radius, bool operational, int l, int consumption, const std::map<std::string, int>& resources)
        : UtilityFlyweight(n, c, cap, radius, operational, l, consumption, resources) {}

void PowerPlant::connect(double distance) {
    if (isOperational && distance <= effectRadius) {
        std::cout << name <<" providing power within range.\n";
    } else {
        std::cout << "Out of range of the PowerPlant.\n";
    }
}

std::unique_ptr<UtilityFlyweight> PowerPlant::clone() const{
    return std::make_unique<PowerPlant>(*this);
}