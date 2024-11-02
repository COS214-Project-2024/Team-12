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

    NPCManager() : happinessLevel(50), happyCount(0), neutralCount(0), revoltCount(0), productiveCount(0), crimeCount(0) {}

private:

    int happinessLevel;
    int happyCount;
    int neutralCount;
    int revoltCount;
    int productiveCount;
    int crimeCount;
};

#endif // NPC_MANAGER_H
