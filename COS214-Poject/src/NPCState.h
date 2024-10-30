#ifndef NPC_STATE_H
#define NPC_STATE_H

#include <string>

class NPCState{
public:
	void virtual handle() = 0;
	virtual std::string getStateName() = 0;
	virtual NPCState* clone() const = 0;
	virtual ~NPCState() = default;
};

#endif