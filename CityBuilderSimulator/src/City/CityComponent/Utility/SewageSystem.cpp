#include "SewageSystem.h"

SewageSystem::SewageSystem(const std::string& n, double c, int cap, double radius, bool operational, int l, int consumption, const std::map<std::string, int>& resources)
        : UtilityFlyweight(n, c, cap, radius, operational, l, consumption, resources) {}

void SewageSystem::connect(double distance) {
    if (isOperational && distance <= effectRadius) {
        std::cout << name << " managing sewage within range.\n";
    } else {
        std::cout << "Out of range of the SewageSystem.\n";
    }
}

std::unique_ptr<UtilityFlyweight> SewageSystem::clone() const {
    return std::make_unique<SewageSystem>(*this);
}