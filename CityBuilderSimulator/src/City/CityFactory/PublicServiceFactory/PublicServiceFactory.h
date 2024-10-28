#ifndef PUBLICSERVICEFACTORY_H
#define PUBLICSERVICEFACTORY_H

#include <memory>
#include "CityComponent/PublicService/PublicService.h"

class PublicServiceFactory {
public:
    virtual std::unique_ptr<PublicService> createPublicService() = 0;  // Pure virtual function
    virtual ~PublicServiceFactory() {}  // Virtual destructor
};

#endif
