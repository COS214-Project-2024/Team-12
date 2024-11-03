#include "RevoltState.h"
#include "NPCManager.h"
#include "Government.h"

#include <iostream>
#include <random>
#include <string>

RevoltState::~RevoltState() = default;

void RevoltState::handle() {
    // Base values for revolt impact
    const float BASE_REVOLT_CHANCE = 0.1f;
    const double BASE_REDUCTION_FACTOR = 0.02;
    const double MAX_REDUCTION_FACTOR = 0.5;

    int revoltNPCCount = NPCManager::getInstance().getRevoltCount();
    float revoltChance = std::min(BASE_REVOLT_CHANCE + (revoltNPCCount * 0.02f), 1.0f);
    double reductionFactor = std::min(BASE_REDUCTION_FACTOR * revoltNPCCount, MAX_REDUCTION_FACTOR);

    // Random number generator for production reduction determination
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0.0, 1.0);

    if (dis(gen) < revoltChance) {
        Government::getInstance().reduceProduction(reductionFactor);
        std::cout << "Production reduced by " << (reductionFactor * 100) << "% due to revolt.\n";
        std::cout << "New production rate: " << Government::getInstance().getProductionRate() << "\n";
    } else {
        std::cout << "No production impact from revolt this time.\n";
    }
}

std::string RevoltState::getStateName() {
    return "RevoltState";
}

NPCState* RevoltState::clone() const{
    return new RevoltState(*this);
}
