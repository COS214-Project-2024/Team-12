#include "ReactingNPCS.h"
#include "NPCManager.h"
#include "NPCState.h"
#include "NeutralState.h"
#include "DonationState.h"
#include "RevoltState.h"

#include <string>

ReactingNPCS::ReactingNPCS() : state(new NeutralState()) {}

ReactingNPCS::~ReactingNPCS() { delete state; }

void ReactingNPCS::update(){
	// Update all NPCS
	int happinessLevel = NPCManager::getInstance().getHappinessLevel();

        // Transition between states based on happiness level
        if (happinessLevel > 70 && dynamic_cast<DonationState*>(state) == nullptr) {
            changeState(new DonationState());
        } else if (happinessLevel < 30 && dynamic_cast<RevoltState*>(state) == nullptr) {
            changeState(new RevoltState());
        } else if (happinessLevel >= 30 && happinessLevel <= 70 && dynamic_cast<NeutralState*>(state) == nullptr) {
            changeState(new NeutralState());
        }

        // Call the current state's reaction
        state->handle();
}