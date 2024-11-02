#include "Hospital.h"
#include <iostream>

Hospital::Hospital(bool waterStatus, bool electricityStatus, bool wasteManagementStatus, bool sewageStatus, std::string buildingStatus) :PublicService(waterStatus,electricityStatus, wasteManagementStatus, sewageStatus, buildingStatus) {

}

Hospital::Hospital() : Hospital(false,false,false,false,"Not opertational") {};
void Hospital::provideService(){
    std::cout << "Providing health care to all citizens in need." << std::endl;
}

std::unique_ptr<PublicService> Hospital::clone() const {
    return std::make_unique<Hospital>(*this);

}

void Hospital::accept(taxCollector* tax){

}

void Hospital::displayStatus(){
    std::cout << "Hospital bread" << std::endl;
}