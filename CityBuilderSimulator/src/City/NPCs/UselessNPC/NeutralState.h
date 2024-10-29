#ifndef NEUTRAL_STATE_H
#define NEUTRAL_STATE_H

#include "../NPCManager.h"
#include "NPCState.h"

#include <string>

class NeutralState : public NPCState{
	public:
	void handle() override;
	std::string getStateName() override;
	NPCState* clone() const override;
};

#endif