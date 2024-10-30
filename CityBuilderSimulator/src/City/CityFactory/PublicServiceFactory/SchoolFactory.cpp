#include "SchoolFactory.h"
#include "../PublicService/School.h"


std::unique_ptr<PublicService> SchoolFactory::createPublicService() {
    return std::make_unique<School>();
}
