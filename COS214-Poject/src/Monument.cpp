#include "Monument.h"

Monument::Monument(const std::string& type, int  capacity, double price, std::shared_ptr<UtilityFlyweight> water, std::shared_ptr<UtilityFlyweight> power,
        std::shared_ptr<UtilityFlyweight> waste, std::shared_ptr<UtilityFlyweight> sewage)
        : LandMark(type,capacity,price, water, power, waste, sewage) {}

Monument::~Monument(){}

void Monument::displayStatus() {
    std::cout << "Monument Status:\n";
    LandMark::displayStatus();
}


std::unique_ptr<LandMark> Monument::clone() const {
    std::unique_ptr<Monument> monument = std::make_unique<Monument>(
    landMarkType, visitorCapacity, price, waterSupply, powerSupply, wasteManagement, sewageManagement
);

    return monument;

}

std::string Monument::getBuildingType() const {
    return "Monument";
}