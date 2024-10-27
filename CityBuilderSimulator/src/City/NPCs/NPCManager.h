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

    //if we want the population to grow without using the observers but just to show a big number without actually having that many npcs
    int getPopulationGrowth() const;
    void setPopulationGrowth(int growth);

    int getPopulation() const;
    void updatePopulation();

    void adjustStateCounts(int happyChange, int neutralChange, int revoltChange);

    // we also need getters for the terminal
    int getHappyCount() const;
    int getNeutralCount() const;
    int getRevoltCount() const;

    //if we want to grow the population as we add the NPCs we use this method
    void increasePopulation(int num); 

    // Other NPC-related methods and attributes can be added similarly

private:
    NPCManager() : happinessLevel(50), mortalityRate(0.01), populationGrowth(5), population(0), happyCount(0), neutralCount(0), revoltCount(0) {}

    int happinessLevel;
    double mortalityRate;
    int populationGrowth;
    int population;
    int happyCount;
    int neutralCount;
    int revoltCount;
};

#endif // NPC_MANAGER_H
