#include "HouseFactory.h"
#include "CityComponent/Residential/House.h"

class HouseFactory : public ResidentialBuildingFactory {
public:
    std::unique_ptr<ResidentialBuilding> createBuilding() override {
        return std::make_unique<House>();
    }
};
