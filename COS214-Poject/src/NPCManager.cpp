#include "NPCManager.h"
#include "Government.h"

#include <utility>
#include <string>
#include <algorithm>
#include <iostream>

/**
 * @brief Singleton instance getter for NPCManager.
 * 
 * @return NPCManager& Singleton instance of NPCManager.
 */
NPCManager& NPCManager::getInstance() {
    static NPCManager instance;
    return instance;
}

/**
 * @brief Default constructor initializing NPCManager with default values.
 */
NPCManager::NPCManager()
    : happinessLevel(0), happyCount(0), neutralCount(0), revoltCount(0),
      productiveCount(0), crimeCount(0), employedNpcs(0) {}

/**
 * @brief Retrieves the current happiness level.
 * 
 * @return int The current happiness level.
 */
int NPCManager::getHappinessLevel() const {
    return happinessLevel;
}

/**
 * @brief Sets and updates the happiness level within a defined range.
 * 
 * @param level The level to add to the current happiness.
 */
void NPCManager::setHappinessLevel(int level) {
    if (Government::getInstance().getPopulation() == 0) {
        return;
    }
    happinessLevel += level;

    if (happinessLevel > 100) {
        happinessLevel = 100;
    } else if (happinessLevel < 0) {
        happinessLevel = 0;
    }
}

/**
 * @brief Increments the count for a given NPC state.
 * 
 * @param stateName Name of the state to increment count for.
 */
void NPCManager::incrementCount(const std::string& stateName) {
    if (stateName == "DonationState") happyCount++;
    else if (stateName == "ProductiveState") productiveCount++;
    else if (stateName == "CrimeState") crimeCount++;
    else if (stateName == "RevoltState") revoltCount++;
    else if (stateName == "NeutralState") neutralCount++;
}

/**
 * @brief Decrements the count for a given NPC state.
 * 
 * @param stateName Name of the state to decrement count for.
 */
void NPCManager::decrementCount(const std::string& stateName) {
    if (stateName == "DonationState") happyCount--;
    else if (stateName == "ProductiveState") productiveCount--;
    else if (stateName == "CrimeState") crimeCount--;
    else if (stateName == "RevoltState") revoltCount--;
    else if (stateName == "NeutralState") neutralCount--;
}

/**
 * @brief Retrieves the number of NPCs in the Donation state.
 * 
 * @return int The count of Donation state NPCs.
 */
int NPCManager::getDonationCount() const {
    return happyCount;
}

/**
 * @brief Retrieves the number of NPCs in the Neutral state.
 * 
 * @return int The count of Neutral state NPCs.
 */
int NPCManager::getNeutralCount() const {
    return neutralCount;
}

/**
 * @brief Retrieves the number of NPCs in the Revolt state.
 * 
 * @return int The count of Revolt state NPCs.
 */
int NPCManager::getRevoltCount() const {
    return revoltCount;
}

/**
 * @brief Retrieves the number of NPCs in the Productive state.
 * 
 * @return int The count of Productive state NPCs.
 */
int NPCManager::getProductiveCount() const {
    return productiveCount;
}

/**
 * @brief Retrieves the number of NPCs in the Crime state.
 * 
 * @return int The count of Crime state NPCs.
 */
int NPCManager::getCrimeCount() const {
    return crimeCount;
}

/**
 * @brief Resets all state counts to zero.
 */
void NPCManager::resetCounts() {
    happyCount = 0;
    neutralCount = 0;
    revoltCount = 0;
    productiveCount = 0;
    crimeCount = 0;
}

/**
 * @brief Determines the state with the highest count among NPCs.
 * 
 * @return std::string The name of the state with the highest count.
 */
std::string NPCManager::getHighestState() const {
    std::pair<std::string, int> states[] = {
        {"Happy", happyCount},
        {"Neutral", neutralCount},
        {"Revolt", revoltCount},
        {"Productive", productiveCount},
        {"Crime", crimeCount}
    };

    auto maxState = std::max_element(std::begin(states), std::end(states),
                                     [](const auto& lhs, const auto& rhs) {
                                         return lhs.second < rhs.second;
                                     });

    std::cout << "State with the highest count is: " << maxState->first << " with count: " << maxState->second << std::endl;
    return maxState->first;
}

/**
 * @brief Retrieves the total number of NPCs across all states.
 * 
 * @return int Total number of NPCs.
 */
int NPCManager::getTotalNPCs() const {
    return happyCount + neutralCount + revoltCount + productiveCount + crimeCount;
}

/**
 * @brief Calculates employment based on the dominant state and updates the Government's employment rate.
 */
void NPCManager::EmployeedNpcs() {
    int total = getTotalNPCs();

    if (getHighestState() == "Neutral") {
        employedNpcs = total * 0.85;    // 85% employed
        unemployedNpcs = total * 0.15;  // 15% unemployed
    } else if (getHighestState() == "Happy") {
        employedNpcs = total * 0.92;    // 92% employed
        unemployedNpcs = total * 0.08;  // 8% unemployed
    } else if (getHighestState() == "Productive") {
        employedNpcs = total * 0.88;    // 88% employed
        unemployedNpcs = total * 0.12;  // 12% unemployed
    } else if (getHighestState() == "Crime") {
        employedNpcs = total * 0.75;    // 75% employed
        unemployedNpcs = total * 0.25;  // 25% unemployed
    } else if (getHighestState() == "Revolt") {
        employedNpcs = total * 0.6;     // 60% employed
        unemployedNpcs = total * 0.4;   // 40% unemployed
    }

    double employmentRate = static_cast<double>(employedNpcs) / total * 100;
    Government::getInstance().increaseEmploymentRate(employmentRate);
}

/**
 * @brief Updates the Government's crime rate based on NPCs in the Crime state.
 */
void NPCManager::getCrimeRate() {
    Government::getInstance().setCrimeRate(crimeCount / getTotalNPCs());
}
