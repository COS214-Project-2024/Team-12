#ifndef SCHOOLFACTORY_H
#define SCHOOLFACTORY_H

#include "PublicServiceFactory.h"
#include "PublicService.h"

class SchoolFactory : public PublicServiceFactory {
public:
    std::unique_ptr<PublicService> createPublicService() override;  // Implement the factory method
};

#endif
