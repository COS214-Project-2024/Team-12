#include "CulturalCenter.h"

CulturalCenter::CulturalCenter(const std::string& type, int  capacity, double price, std::shared_ptr<UtilityFlyweight> water, std::shared_ptr<UtilityFlyweight> power,
        std::shared_ptr<UtilityFlyweight> waste, std::shared_ptr<UtilityFlyweight> sewage)
        : LandMark(type,capacity,price, water, power, waste, sewage) {}

CulturalCenter::~CulturalCenter(){}

void CulturalCenter::displayStatus(){
    std::cout << "Cultural Center Status:\n";
    LandMark::displayStatus();
}


std::unique_ptr<LandMark> CulturalCenter::clone() const {
    std::unique_ptr<CulturalCenter> culturalCenter = std::make_unique<CulturalCenter>(
    landMarkType, visitorCapacity, price, waterSupply, powerSupply, wasteManagement, sewageManagement
);

    return culturalCenter;

}

std::string CulturalCenter::getBuildingType() const {
    return "Cultural Center";
}