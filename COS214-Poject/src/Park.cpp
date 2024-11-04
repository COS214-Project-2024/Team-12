#include "Park.h"

Park::Park(const std::string& type, int  capacity, double price, std::shared_ptr<UtilityFlyweight> water, std::shared_ptr<UtilityFlyweight> power,
        std::shared_ptr<UtilityFlyweight> waste, std::shared_ptr<UtilityFlyweight> sewage)
        : LandMark(type,capacity,price, water, power, waste, sewage) {}

Park::~Park(){}

void Park::displayStatus(){
    std::cout << "Park Status:\n";
    LandMark::displayStatus();
}


std::unique_ptr<LandMark> Park::clone() const {
    std::unique_ptr<Park> park = std::make_unique<Park>(
    landMarkType, visitorCapacity, price, waterSupply, powerSupply, wasteManagement, sewageManagement
);

    return park;

}