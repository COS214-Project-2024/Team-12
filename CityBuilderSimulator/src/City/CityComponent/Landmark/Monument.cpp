#include "Monument.h"

Monument::Monument(const std::string& type, int  capacity, double price, std::shared_ptr<UtilityFlyweight> water, std::shared_ptr<UtilityFlyweight> power,
        std::shared_ptr<UtilityFlyweight> waste, std::shared_ptr<UtilityFlyweight> sewage)
        : LandMark(type,capacity,price, water, power, waste, sewage) {}

Monument::Monument(): LandMark("Monument", 70 ,35000.00,nullptr, nullptr,nullptr,nullptr){}

void Monument::displayStatus(){
    std::cout << "Monument Status:\n";
    LandMark::displayStatus();
}


std::unique_ptr<LandMark> Monument::clone() const {
    return std::make_unique<Monument>(*this);
}