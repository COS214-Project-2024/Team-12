#include "Park.h"

Park::Park(const std::string& type, int  capacity, double price, std::shared_ptr<UtilityFlyweight> water, std::shared_ptr<UtilityFlyweight> power,
        std::shared_ptr<UtilityFlyweight> waste, std::shared_ptr<UtilityFlyweight> sewage)
        : LandMark(type,capacity,price, water, power, waste, sewage) {}

Park::Park(): LandMark("Park", 50,30000.00,nullptr, nullptr,nullptr,nullptr){}

void Park::displayStatus(){
    std::cout << "Park Status:\n";
    LandMark::displayStatus();
}


std::unique_ptr<LandMark> Park::clone() const {
    return std::make_unique<Park>(*this);
}