#include "SchoolFactory.h"
#include "CityComponent/PublicService/School.h"


std::unique_ptr<PublicService> SchoolFactory::createPublicService() {
    return std::make_unique<School>();
}
