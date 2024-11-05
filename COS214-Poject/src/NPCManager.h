// NPCManager.h
#ifndef NPC_MANAGER_H
#define NPC_MANAGER_H

#include <string>

/**
 * @brief Singleton class managing the state and statistics of NPCs.
 * 
 * The NPCManager class tracks various NPC states, their counts, and calculates
 * city-wide metrics such as happiness level, employment, and crime rate.
 */
class NPCManager {
public:
    /**
     * @brief Retrieves the singleton instance of NPCManager.
     * 
     * @return NPCManager& Reference to the singleton instance.
     */
    static NPCManager& getInstance();

    // Delete copy constructor and assignment operator for singleton
    NPCManager(NPCManager const&) = delete;
    void operator=(NPCManager const&) = delete;

    /**
     * @brief Gets the current happiness level of NPCs.
     * 
     * @return int The current happiness level.
     */
    int getHappinessLevel() const;

    /**
     * @brief Sets or adjusts the NPC happiness level.
     * 
     * @param level The value to adjust the happiness level by.
     */
    void setHappinessLevel(int level);

    /**
     * @brief Retrieves the count of NPCs in the Donation (happy) state.
     * 
     * @return int Count of NPCs in the Donation state.
     */
    int getDonationCount() const;

    /**
     * @brief Retrieves the count of NPCs in the Neutral state.
     * 
     * @return int Count of NPCs in the Neutral state.
     */
    int getNeutralCount() const;

    /**
     * @brief Retrieves the count of NPCs in the Revolt state.
     * 
     * @return int Count of NPCs in the Revolt state.
     */
    int getRevoltCount() const;

    /**
     * @brief Retrieves the count of NPCs in the Productive state.
     * 
     * @return int Count of NPCs in the Productive state.
     */
    int getProductiveCount() const;

    /**
     * @brief Retrieves the count of NPCs in the Crime state.
     * 
     * @return int Count of NPCs in the Crime state.
     */
    int getCrimeCount() const;

    /**
     * @brief Increments the count for a given NPC state.
     * 
     * @param stateName The name of the state to increment.
     */
    void incrementCount(const std::string& stateName);

    /**
     * @brief Decrements the count for a given NPC state.
     * 
     * @param stateName The name of the state to decrement.
     */
    void decrementCount(const std::string& stateName);

    /**
     * @brief Resets all state counts to zero.
     */
    void resetCounts();

    /**
     * @brief Determines the state with the highest count.
     * 
     * @return std::string Name of the state with the highest count.
     */
    std::string getHighestState() const;

    /**
     * @brief Gets the total number of NPCs across all states.
     * 
     * @return int Total number of NPCs.
     */
    int getTotalNPCs() const;

    /**
     * @brief Calculates employment levels based on the dominant state.
     */
    void EmployeedNpcs();

    /**
     * @brief Updates and retrieves the crime rate based on NPC counts.
     */
    void getCrimeRate();

protected:
    /**
     * @brief Default constructor for NPCManager.
     */
    NPCManager();

private:
    int happinessLevel;      ///< Overall happiness level of NPCs.
    int happyCount;          ///< Count of NPCs in the Donation (happy) state.
    int neutralCount;        ///< Count of NPCs in the Neutral state.
    int revoltCount;         ///< Count of NPCs in the Revolt state.
    int productiveCount;     ///< Count of NPCs in the Productive state.
    int crimeCount;          ///< Count of NPCs in the Crime state.

    int employedNpcs;        ///< Number of employed NPCs.
    int unemployedNpcs;      ///< Number of unemployed NPCs.
};

#endif // NPC_MANAGER_H
