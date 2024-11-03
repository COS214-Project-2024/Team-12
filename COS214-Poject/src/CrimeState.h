#ifndef CRIME_STATE_H
#define CRIME_STATE_H

#include "NPCManager.h"
#include "NPCState.h"

#include <string>

class CrimeState : public NPCState{
	public:
	void handle() override;
	std::string getStateName() override;
	NPCState* clone() const override;
	~CrimeState() override = default;
};

#endif