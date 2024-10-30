#include "OfficeFactory.h"
#include "Office.h"

std::unique_ptr<CommercialBuilding> OfficeFactory::createBuilding() {
    return std::make_unique<Office>();
}