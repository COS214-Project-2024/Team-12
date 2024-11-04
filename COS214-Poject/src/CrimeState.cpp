/**
 * @file CrimeState.cpp
 * @brief Implementation of the CrimeState class, representing the behavior of NPCs in a crime state.
 */

#include "Government.h"
#include "NPCManager.h"
#include "CrimeState.h"

#include <random>
#include <iostream>
#include <string>

/**
 * @brief Handles the effects of the CrimeState on the city's mortality rate.
 * 
 * Calculates the likelihood and impact of crime affecting the mortality rate based on the number of NPCs
 * in the crime state. If a randomly generated value falls within the calculated chance, the mortality rate
 * is increased by a factor proportional to the crime NPC count.
 */
void CrimeState::handle() {
    const float baseCrimeChance = 0.2f;         /**< Base probability of crime impact. */
    const double crimeImpactFactor = 0.005;     /**< Mortality rate increase factor per crime NPC. */

    // Get the count of NPCs in CrimeState
    int crimeNPCCount = NPCManager::getInstance().getCrimeCount();

    // Calculate adjusted crime chance
    float crimeChance = baseCrimeChance + (crimeNPCCount * 0.02f);
    if (crimeChance > 1.0f) {
        crimeChance = 1.0f;
    }

    // Calculate total impact on mortality rate
    double impactFactor = crimeImpactFactor * crimeNPCCount;

    // Random number generator for crime impact
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0.0, 1.0);

    // Determine if crime impact occurs
    if (dis(gen) < crimeChance) {
        Government::getInstance().increaseCrimeRate(impactFactor);
        std::cout << "Mortality rate increased by " << (impactFactor * 100) << "% due to crime.\n";
    } else {
        std::cout << "No crime impact this time.\n";
    }
}

/**
 * @brief Retrieves the name of the current state.
 * 
 * @return The name of this state, "CrimeState".
 */
std::string CrimeState::getStateName() {
    return "CrimeState";
}

/**
 * @brief Creates a copy of the current CrimeState instance.
 * 
 * @return A pointer to a new CrimeState object, cloned from this instance.
 */
NPCState* CrimeState::clone() const {
    return new CrimeState(*this);
}
