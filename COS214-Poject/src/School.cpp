#include "School.h"
#include <iostream>

School::School(bool waterStatus, bool electricityStatus, bool wasteManagementStatus, bool sewageStatus, std::string buildingStatus) 
:PublicService(waterStatus,electricityStatus, wasteManagementStatus, sewageStatus, buildingStatus) {

}
void School::provideService(){
    std::cout << "Here to educate the citizens of this city." << std::endl;
}
std::unique_ptr<PublicService> School::clone() const {
    return std::make_unique<School>(*this);

}