#include "ReactingNPCS.h"
#include "NPCManager.h"
#include "NPCState.h"
#include "NeutralState.h"
#include "DonationState.h"
#include "RevoltState.h"
#include "ProductiveState.h"
#include "CrimeState.h"

#include <string>
#include <random>

ReactingNPCS::ReactingNPCS() : state(new NeutralState()) {}

ReactingNPCS::~ReactingNPCS() { delete state; }

//Hopefully this works
void ReactingNPCS::update() {
    // Get the latest happiness level from NPCManager
    int happinessLevel = NPCManager::getInstance().getHappinessLevel();

    // Define the probability for NPCs to follow the majority consensus
    float consensusProbability = 0.8f;  // 80% probability to follow the consensus

    // Random number generator
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0.0, 1.0);

    // Determine if this NPC should follow the consensus
    bool followsConsensus = dis(gen) < consensusProbability;

    // Update state based on consensus and current happiness level
    if (followsConsensus) {
        // 80% of NPCs follow the general consensus based on happiness level
        if (followsConsensus) {
        if (happinessLevel > 85 && dynamic_cast<DonationState*>(state) == nullptr) {
            changeState(new DonationState());
        } else if (happinessLevel > 70 && dynamic_cast<ProductiveState*>(state) == nullptr) {
            changeState(new ProductiveState());
        } else if (happinessLevel >= 30 && happinessLevel <= 70 && dynamic_cast<NeutralState*>(state) == nullptr) {
            changeState(new NeutralState());
        } else if (happinessLevel < 30 && happinessLevel >= 15 && dynamic_cast<CrimeState*>(state) == nullptr) {
            changeState(new CrimeState());
        } else if (happinessLevel < 15 && dynamic_cast<RevoltState*>(state) == nullptr) {
            changeState(new RevoltState());
        }
    } else {
        // 20% retain their current state or randomly select an alternate state
        if (dynamic_cast<NeutralState*>(state) && happinessLevel > 70) {
            changeState(new DonationState());  // small chance of changing
        } else if (dynamic_cast<DonationState*>(state) && happinessLevel < 30) {
            changeState(new RevoltState());  // small chance of changing
        }
        // Otherwise, NPC remains in its current state
    }

    // Call the current state's reaction
    state->handle();
}
}