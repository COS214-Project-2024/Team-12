#include "CulturalCenter.h"

CulturalCenter::CulturalCenter(const std::string& type, int  capacity, double price, std::shared_ptr<UtilityFlyweight> water, std::shared_ptr<UtilityFlyweight> power,
        std::shared_ptr<UtilityFlyweight> waste, std::shared_ptr<UtilityFlyweight> sewage)
        : LandMark(type,capacity,price, water, power, waste, sewage) {}

CulturalCenter::CulturalCenter(): LandMark("Cultural Center", 80,40000.00,nullptr, nullptr,nullptr,nullptr){}

void CulturalCenter::displayStatus(){
    std::cout << "Cultural Center Status:\n";
    LandMark::displayStatus();
}


std::unique_ptr<LandMark> CulturalCenter::clone() const {
    return std::make_unique<CulturalCenter>(*this);
}