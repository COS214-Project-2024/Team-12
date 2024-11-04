#include "DonationState.h"
#include "NPCManager.h"
#include "Government.h"

#include <iostream>
#include <random>
#include <string>

/**
 * @brief Destructor for the DonationState class.
 * 
 * This destructor cleans up any resources associated with the DonationState.
 */
DonationState::~DonationState() = default;

/**
 * @brief Handles the logic for NPCs in the donation state.
 * 
 * This method calculates whether a donation occurs based on the number of
 * NPCs in the donation state and updates the city's funds accordingly.
 * 
 * The chance of receiving an investment increases with the number of NPCs
 * in the DonationState. If an investment occurs, the specified amount is added
 * to the city's funds.
 */
void DonationState::handle() {
    // Base probability of getting an investment
    const float baseInvestmentChance = 0.05f;  // 5% base chance
    const double investmentAmount = 1000;      // Amount added on successful investment

    // Get the number of NPCs in DonationState to adjust probability
    int donationNPCCount = NPCManager::getInstance().getDonationCount();
    
    // Scale the chance based on the number of donation NPCs
    float investmentChance = baseInvestmentChance + (donationNPCCount * 0.01f);

    // Cap the maximum chance at 100%
    if (investmentChance > 1.0f) {
        investmentChance = 1.0f;
    }

    // Random number generator
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0.0, 1.0);

    // Determine if investment occurs based on probability
    if (dis(gen) < investmentChance) {
        // Successful investment, increase city's money
        Government::getInstance().addMoney(investmentAmount);
        std::cout << "Investment received! Added " << investmentAmount << " to city funds.\n";
    } else {
        std::cout << "No investment this time.\n";
    }
}

/**
 * @brief Gets the name of the current state.
 * 
 * @return A string representing the name of the donation state.
 */
std::string DonationState::getStateName() {
    return "DonationState";
}

/**
 * @brief Clones the current DonationState instance.
 * 
 * @return A pointer to a new DonationState instance that is a copy of this state.
 */
NPCState* DonationState::clone() const {
    return new DonationState(*this);
}
