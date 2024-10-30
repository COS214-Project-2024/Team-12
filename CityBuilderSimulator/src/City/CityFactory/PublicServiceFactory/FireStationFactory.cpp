#include "FireStationFactory.h"
#include "../PublicService/FireStation.h"

std::unique_ptr<PublicService> FireStationFactory::createPublicService() {
    return std::make_unique<FireStation>();
}
