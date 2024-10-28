#ifndef REVOLT_STATE_H
#define REVOLT_STATE_H

#include "../NPCManager.h"
#include "NPCState.h"

#include <string>

class RevoltState : public NPCState{
	public:
	void handle() override;
	std::string getStateName() override;
	RevoltState(bool testMode = false) : testMode(testMode) {} //add temporarily for testing

	private:
	bool testMode; //add temporarily
};

#endif