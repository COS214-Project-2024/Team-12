#include "OfficeFactory.h"
#include "CityComponent/COmmercial/Office.h"

std::unique_ptr<CommercialBuilding> OfficeFactory::createBuilding() {
    return std::make_unique<Office>();
}