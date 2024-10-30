#ifndef FIRESTATIONFACTORY_H
#define FIRESTATIONFACTORY_H

#include "PublicServiceFactory.h"
#include "PublicService.h"

class FireStationFactory : public PublicServiceFactory {
public:
    std::unique_ptr<PublicService> createPublicService() ;
};

#endif
