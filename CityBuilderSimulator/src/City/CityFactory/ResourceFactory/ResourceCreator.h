#ifndef RESOURCECREATOR_H
#define RESOURCECREATOR_H

#include <memory>
#include "CityComponent/Resources/Resource.h"

class ResourceCreator {
public:
    virtual std::unique_ptr<Resource> createResource() = 0;
    virtual ~ResourceCreator() {}
};

#endif