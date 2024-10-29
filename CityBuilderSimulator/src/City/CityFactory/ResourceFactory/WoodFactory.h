#ifndef WOODFACTORY_H
#define WOODFACTORY_H

#include "ResourceCreator.h"
#include "CityComponent/Resources/Resource.h"

class WoodFactory : public ResourceCreator {
public:
    std::unique_ptr<Resource> createResource();
};

#endif