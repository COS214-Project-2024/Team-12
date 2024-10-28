#ifndef FIRESTATIONFACTORY_H
#define FIRESTATIONFACTORY_H

#include "PublicServiceFactory.h"
#include "CityComponent/PublicService/PublicService.h"

class FireStationFactory : public PublicServiceFactory {
public:
    std::unique_ptr<PublicService> createPublicService() ;
};

#endif
