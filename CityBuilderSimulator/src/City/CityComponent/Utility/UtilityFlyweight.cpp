#include "UtilityFlyweight.h"

UtilityFlyweight::UtilityFlyweight(const std::string& n, double c, int cap, double radius, bool operational, int t, int consumption, const std::map<std::string, int>& resources)
        : name(n), cost(c), capacity(cap), effectRadius(radius), isOperational(operational), level(t), resourceConsumption(consumption), resourceNeeds(resources) {}

bool UtilityFlyweight::getOperationalStatus() const { return isOperational; }
double UtilityFlyweight::getCost() const { return cost; }
int UtilityFlyweight::getCapacity() const { return capacity; }
double UtilityFlyweight::getEffectRadius() const { return effectRadius; }
int UtilityFlyweight::getLevel() const { return level; }
int UtilityFlyweight::getResourceConsumption() const { return resourceConsumption; }
std::map<std::string, int> UtilityFlyweight:: getResourceNeeds() const { return resourceNeeds;}

void UtilityFlyweight::activate() {
    if(!isOperational) {
        isOperational = true;
        std::cout  << name << " is now operational.\n";
    }
}

void UtilityFlyweight::deactivate() {
    if(isOperational) {
        isOperational = false;
        std::cout  << name << " is now operational.\n";
    }
}

void UtilityFlyweight::displayStatus() {
    std::cout << "Utility: " << name << "\n"
            << "Status: " << (isOperational ? "Operational" : "Inactive") << "\n"
            << "Level: " << level << "\n"
            << "Capacity: " << capacity << " buildings\n"
            << "Effect Radius: " << effectRadius << " units\n"
            << "Cost to Build: $" << cost << "\n"
            << "Resource Consumption per Cycle: " << resourceConsumption << "\n"
            << "Resources Needed for Construction: ";

    for (const auto& resource : resourceNeeds) {
        std::cout << resource.first << ": " << resource.second << " ";
    }
    std::cout << "\n";
}

double UtilityFlyweight::getTaxRevenue() {
    return 0.0; // We don't collect tax from utilities
}