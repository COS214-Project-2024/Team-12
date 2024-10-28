#include "RevoltState.h"
#include "NPCManager.h"
#include "../City/Government.h"

#include <iostream>
#include <random>
#include <string>

void RevoltState::handle() {
    // Base chance of production reduction
    const float baseRevoltChance = 0.1f;  // 10% base chance for production reduction
    const double baseReductionFactor = 0.02;  // 2% reduction in production per revolting NPC

    // Get the number of NPCs in RevoltState
    int revoltNPCCount = NPCManager::getInstance().getRevoltCount();
    
    // Calculate the chance of production reduction based on the number of revolting NPCs
    float revoltChance = baseRevoltChance + (revoltNPCCount * 0.02f);

    // Cap the maximum chance at 100%
    if (revoltChance > 1.0f) {
        revoltChance = 1.0f;
    }

    // Calculate the reduction factor based on the number of revolting NPCs
    double reductionFactor = baseReductionFactor * revoltNPCCount;

    // Random number generator for determining if reduction occurs
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0.0, 1.0);

    // Check if the production reduction should apply
    if (dis(gen) < revoltChance) {
        // Apply reduction to production rate in Government
        Government::getInstance().reduceProduction(reductionFactor);
        std::cout << "Production reduced by " << (reductionFactor * 100) << "% due to revolt.\n";
    } else {
        std::cout << "No production impact from revolt this time.\n";
    }
}

std::string RevoltState::getStateName(){
	return "Revolt";
}
/* 100% 
cheap 5%
moderate 8%
Expensive 13%

50%
cheap 1%
moderate 2%
Expensive 3%

resources
utilites, not as much efficiency */