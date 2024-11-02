#include "PoliceStationFactory.h"
#include "PoliceStation.h"


std::unique_ptr<PublicService> PoliceStationFactory::createPublicService() {
    return std::make_unique<PoliceStation>();
}
