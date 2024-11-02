#ifndef POLICESTATIONFACTORY_H
#define POLICESTATIONFACTORY_H

#include "PublicServiceFactory.h"
#include "PublicService.h"

class PoliceStationFactory : public PublicServiceFactory {
public:
    std::unique_ptr<PublicService> createPublicService() ;
};

#endif
