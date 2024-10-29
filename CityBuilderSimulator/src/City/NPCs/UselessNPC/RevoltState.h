#ifndef REVOLT_STATE_H
#define REVOLT_STATE_H

#include "../NPCManager.h"
#include "NPCState.h"

#include <string>

class RevoltState : public NPCState{
	public:
	void handle() override;
	std::string getStateName() override;
	NPCState* clone() const override;
};

#endif