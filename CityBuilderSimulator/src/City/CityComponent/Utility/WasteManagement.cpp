#include "../src/City/CityComponent/Utility/WasteManagement.h"

WasteManagement::WasteManagement(const std::string& n, double c, int cap, double radius, bool operational, int l, int consumption, const std::map<std::string, int>& resources)
        : UtilityFlyweight(n, c, cap, radius, operational, l, consumption, resources) {}

void WasteManagement::connect(double distance){
    if (isOperational && distance <= effectRadius) {
        std::cout << name << " collecting waste within range.\n";
    } else {
        std::cout << "Out of range of the WasteManagement.\n";
    }
}

std::unique_ptr<UtilityFlyweight> WasteManagement::clone() const  {
    return std::make_unique<WasteManagement>(*this);
}