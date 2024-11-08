#include "Government.h"
#include "NPCManager.h"
#include "ProductiveState.h"

#include <iostream>
#include <random>
#include <string>

ProductiveState::~ProductiveState() = default;

/**
 * @brief Handles the logic for the productive state of NPCs.
 * 
 * This method calculates the chance of a productivity boost based on the number
 * of NPCs in the productive state. If the productivity boost occurs, it increases
 * the production rate in the Government class.
 */
void ProductiveState::handle() {
    // Base chance for a productivity boost
    const float baseProductiveChance = 0.15f;  // 15% base chance for productivity boost
    const double productivityBoostFactor = 0.01;  // 1% production boost per productive NPC

    // Get the number of NPCs in ProductiveState
    int productiveNPCCount = NPCManager::getInstance().getProductiveCount();
    
    // Calculate the chance of productivity boost based on productive NPCs
    float productiveChance = baseProductiveChance + (productiveNPCCount * 0.015f);

    // Cap the maximum chance at 100%
    if (productiveChance > 1.0f) {
        productiveChance = 1.0f;
    }

    // Calculate the total boost factor based on the number of productive NPCs
    double boostFactor = productivityBoostFactor * productiveNPCCount;

    // Random number generator for determining if boost occurs
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0.0, 1.0);

    // Check if productivity boost should apply
    if (dis(gen) < productiveChance) {
        // Apply boost to production rate in Government
        Government::getInstance().increaseProduction(boostFactor);
        std::cout << "Production increased by " << (boostFactor * 100) << "% due to productive NPCs.\n";
    } else {
        std::cout << "No productivity boost this time.\n";
    }
}

/**
 * @brief Retrieves the name of the state.
 * 
 * @return A string representing the name of the state.
 */
std::string ProductiveState::getStateName(){
    return "ProductiveState";
}

/**
 * @brief Clones the current ProductiveState instance.
 * 
 * This method creates a new instance of ProductiveState that is a copy of the current instance.
 * 
 * @return A pointer to the newly created ProductiveState instance.
 */
NPCState* ProductiveState::clone() const{
    return new ProductiveState(*this);
}
