#include "SchoolFactory.h"
#include "School.h"


std::unique_ptr<PublicService> SchoolFactory::createPublicService() {
    return std::make_unique<School>();
}
