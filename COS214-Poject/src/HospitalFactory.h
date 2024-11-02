#ifndef HOSPITALFACTORY_H
#define HOSPITALFACTORY_H

#include "PublicServiceFactory.h"
#include "PublicService.h"

class HospitalFactory : public PublicServiceFactory {
public:
    std::unique_ptr<PublicService> createPublicService() ;  
};

#endif
