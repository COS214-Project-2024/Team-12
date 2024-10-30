#include "HouseFactory.h"
#include "House.h"

class HouseFactory : public ResidentialBuildingFactory {
public:
    std::unique_ptr<ResidentialBuilding> createBuilding() override {
        return std::make_unique<House>();
    }
};
