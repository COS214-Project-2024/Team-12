#include "ResidentialBuilding.h"

ResidentialBuilding::ResidentialBuilding(const std::string& type, int population, double comfort, double water, 
        double power, double pollution, double maintenance, double desirability, double noise)
        : buildingType(type), populationCapacity(population), comfortLevel(comfort),
        waterConsumption(water), powerConsumption(power), pollutionContribution(pollution),
        maintenanceCost(maintenance), desirabilityFactor(desirability), noiseLevel(noise) {}

void ResidentialBuilding::displayStatus() const {
        std::cout << "Building Type: " << buildingType << "\n"
                << "  Population Capacity: " << populationCapacity << "\n"
                << "  Comfort Level: " << comfortLevel << "\n"
                << "  Water Consumption: " << waterConsumption << " units\n"
                << "  Power Consumption: " << powerConsumption << " units\n"
                << "  Pollution Contribution: " << pollutionContribution << "\n"
                << "  Maintenance Cost: $" << maintenanceCost << " per month\n"
                << "  Desirability Factor: " << desirabilityFactor << "\n"
                << "  Noise Level: " << noiseLevel << "\n";
    }