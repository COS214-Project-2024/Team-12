#include "MockUtility.h"


MockUtility::MockUtility(const std::string& n, double c, int cap, double radius, bool operational, int l, int consumption, const std::map<std::string, int>& resources)
        : UtilityFlyweight(n, c, cap, radius, operational, l, consumption, resources), connected(false) {}

void MockUtility::connect(double distance) {
    if (isOperational && distance <= effectRadius) {
        connected = true;
        std::cout << name << " connected within range.\n";
    } else {
        connected = false;
        std::cout << name << " out of range.\n";
    }
}

std::unique_ptr<UtilityFlyweight> MockUtility::clone() const{
        return std::make_unique<MockUtility>(*this);
    }

bool MockUtility::isConnected() const { return connected; }