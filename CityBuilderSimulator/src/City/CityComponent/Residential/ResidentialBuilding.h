#ifndef RESIDENTIALBUILDING_H
#define RESIDENTIALBUILDING_H

#include <iostream>

class ResidentialBuilding {
protected:
    int populationCapacity;
    double comfortLevel;
    double waterConsumption;
    double powerConsumption;
    double pollutionContribution;
    double maintenanceCost;
    double desirabilityFactor;
    double noiseLevel;
    std::string buildingType;

public:
    ResidentialBuilding(const std::string& type, int population, double comfort, double water, 
                        double power, double pollution, double maintenance, 
                        double desirability, double noise);

    virtual void displayStatus() const ;

    virtual ~ResidentialBuilding() {}
};

#endif