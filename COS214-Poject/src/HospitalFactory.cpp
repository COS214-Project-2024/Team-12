#include "HospitalFactory.h"
#include "Hospital.h"

std::unique_ptr<PublicService> HospitalFactory::createPublicService() {
    return std::make_unique<Hospital>();
}
