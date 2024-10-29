#include "Government.h"
#include "../NPCManager.h"
#include "CrimeState.h"

#include <random>
#include <iostream>
#include <string>

void CrimeState::handle() {
    // Base chance for crime impact
    const float baseCrimeChance = 0.2f;  // 20% base chance for crime effect
    const double crimeImpactFactor = 0.005;  // 0.5% increase in mortality per criminal NPC

    // Get the number of NPCs in CrimeState
    int crimeNPCCount = NPCManager::getInstance().getCrimeCount();

    // Calculate the chance of crime effect based on crime NPCs
    float crimeChance = baseCrimeChance + (crimeNPCCount * 0.02f);

    // Cap the maximum chance at 100%
    if (crimeChance > 1.0f) {
        crimeChance = 1.0f;
    }

    // Calculate the total impact on mortality rate based on crime NPCs
    double impactFactor = crimeImpactFactor * crimeNPCCount;

    // Random number generator for determining if crime impact occurs
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0.0, 1.0);

    // Check if crime impact should apply
    if (dis(gen) < crimeChance) {
        // Apply increase in mortality rate due to crime in Government
        Government::getInstance().increaseCrimeRate(impactFactor);
        std::cout << "Mortality rate increased by " << (impactFactor * 100) << "% due to crime.\n";
    } else {
        std::cout << "No crime impact this time.\n";
    }
}

std::string CrimeState::getStateName(){
	return "CrimeState";
}