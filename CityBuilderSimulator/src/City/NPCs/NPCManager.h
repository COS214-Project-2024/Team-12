// NPCManager.h
#ifndef NPC_MANAGER_H
#define NPC_MANAGER_H

#include <utility>
class NPCManager {
public:
    static NPCManager& getInstance() {
        static NPCManager instance;  // Guaranteed to be destroyed, instantiated on first use
        return instance;
    }

    // Delete copy constructor and assignment operator for singleton
    NPCManager(NPCManager const&) = delete;
    void operator=(NPCManager const&) = delete;

    // Getters and setters for NPC data
    int getHappinessLevel() const;
    void setHappinessLevel(int level);

    double getMortalityRate() const;
    void setMortalityRate(double rate);

    int getPopulationGrowth() const;
    void setPopulationGrowth(int growth);

    int getPopulation() const;
    void updatePopulation();

    // Other NPC-related methods and attributes can be added similarly

private:
    NPCManager() : happinessLevel(50), mortalityRate(0.01), populationGrowth(5), population(1000) {}

    int happinessLevel;
    double mortalityRate;
    int populationGrowth;
    int population;
};

#endif // NPC_MANAGER_H
