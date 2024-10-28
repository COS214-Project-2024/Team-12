#ifndef PRODUCTIVE_STATE_H
#define PRODUCTIVE_STATE_H

#include "NPCManager.h"
#include "NPCState.h"

#include <string>

class ProductiveState : public NPCState{
	public:
	void handle() override;
	std::string getStateName() override;
};

#endif