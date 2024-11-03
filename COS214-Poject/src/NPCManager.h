// NPCManager.h
#ifndef NPC_MANAGER_H
#define NPC_MANAGER_H

#include <utility>
#include <string>
class NPCManager {
public:
    static NPCManager& getInstance();

    // Delete copy constructor and assignment operator for singleton
    NPCManager(NPCManager const&) = delete;
    void operator=(NPCManager const&) = delete;

    // Getters and setters for NPC data
    int getHappinessLevel() const;
    void setHappinessLevel(int level);

    //void adjustStateCounts(int happyChange, int neutralChange, int revoltChange, int productiveState, int crimeState);

    // we also need getters for the terminal
    int getDonationCount() const;
    int getNeutralCount() const;
    int getRevoltCount() const;
    int getProductiveCount() const;
    int getCrimeCount() const;

    //adjusting State counts
    void incrementCount(const std::string& stateName);
    void decrementCount(const std::string& stateName);

    void resetCounts();

    std::string getHighestState() const;

    int getTotalNPCs() const;

    void EmployeedNpcs();

    void getCrimeRate();

    NPCManager();

private:

    int happinessLevel;
    int happyCount;
    int neutralCount;
    int revoltCount;
    int productiveCount;
    int crimeCount;

    //Employment
    int employedNpcs;
    int unemployedNpcs;
};

#endif // NPC_MANAGER_H
