#include "ReactingNPCS.h"
#include "NPCManager.h"
#include "NPCState.h"
#include "NeutralState.h"
#include "DonationState.h"
#include "RevoltState.h"
#include "ProductiveState.h"
#include "CrimeState.h"
#include "Government.h"

#include <string>
#include <random>
#include <iostream>

ReactingNPCS::ReactingNPCS() : state(new NeutralState()) {
    NPCManager::getInstance().incrementCount("NeutralState");
    std::cout << "[Init] NPC created in NeutralState.\n"; // Debug log
}

ReactingNPCS::~ReactingNPCS() { 
    NPCManager::getInstance().decrementCount(state->getStateName()); // Ensure decrement
    delete state; 
}

// Copy constructor for deep copying
ReactingNPCS::ReactingNPCS(const ReactingNPCS& other) {
    if (other.state) {
        state = other.state->clone();  // Deep copy of the state
        NPCManager::getInstance().incrementCount(state->getStateName()); // Increment new state count
        std::cout << "[Copy] NPC copied in state: " << state->getStateName() << "\n"; // Debug log
    } else {
        state = nullptr;
    }
}

void ReactingNPCS::update() {
    int happinessLevel = NPCManager::getInstance().getHappinessLevel();
    int pollutionLevel = Government::getInstance().getPollutionLevel();
    float consensusProbability = 0.8f;

    // Random generator for consensus
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0.0, 1.0);
    bool followsConsensus = dis(gen) < consensusProbability;

    // Adjust happiness thresholds based on pollution level
    if (pollutionLevel > 50) {
        happinessLevel -= pollutionLevel / 10;
    }

    if (followsConsensus) {
        if (happinessLevel > 85 && dynamic_cast<DonationState*>(state) == nullptr) {
            changeState(new DonationState());
        }
        else if (happinessLevel > 70 && dynamic_cast<ProductiveState*>(state) == nullptr) {
            changeState(new ProductiveState());
        }
        else if (happinessLevel >= 5 && happinessLevel <= 70 && dynamic_cast<NeutralState*>(state) == nullptr) {
            changeState(new NeutralState());
        }
        else if (happinessLevel < 5 && happinessLevel >= 1 && dynamic_cast<CrimeState*>(state) == nullptr) {
            changeState(new CrimeState());
        }
        else if (happinessLevel <= 0 && dynamic_cast<RevoltState*>(state) == nullptr) {
            changeState(new RevoltState());
        }
    } else {
        // Non-consensus case
        if (dynamic_cast<NeutralState*>(state) && happinessLevel > 70) {
            changeState(new DonationState());
        }
        else if (dynamic_cast<DonationState*>(state) && happinessLevel < 30) {
            changeState(new RevoltState());
        }
    }

    state->handle();
}

void ReactingNPCS::changeState(NPCState* newState) {
    // Decrement the count of the old state
    std::string oldStateName = state->getStateName();
    NPCManager::getInstance().decrementCount(oldStateName);
    std::cout << "[ChangeState] NPC leaving " << oldStateName << "\n"; // Debug log

    // Update state
    delete state;
    state = newState;

    // Increment the count of the new state
    std::string newStateName = state->getStateName();
    NPCManager::getInstance().incrementCount(newStateName);
    std::cout << "[ChangeState] NPC entered " << newStateName << "\n"; // Debug log
}

// Clone method to create a deep copy
NPCObserver* ReactingNPCS::clone() {
    return new ReactingNPCS(*this);  // Use the copy constructor for deep copy
}
