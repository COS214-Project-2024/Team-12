#ifndef MINEFACTORY_H
#define MINEFACTORY_H

#include "ResourceCreator.h"
#include "../CityComponent/Resources/Resource.h"

class MineFactory : public ResourceCreator {
public:
    std::unique_ptr<Resource> createResource();
};

#endif