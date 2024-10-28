#ifndef OILFACTORY_H
#define OILFACTORY_H

#include "ResourceCreator.h"
#include "CityComponent/Resources/Resource.h"

class OilFactory : public ResourceCreator {
public:
    std::unique_ptr<Resource> createResource();
};

#endif