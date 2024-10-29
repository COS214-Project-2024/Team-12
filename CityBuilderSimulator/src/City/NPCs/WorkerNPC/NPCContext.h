// NPCContext.h
#ifndef NPCCONTEXT_H
#define NPCCONTEXT_H

#include "WorkerNPC.h"
#include "SlowCollectionStrategy.h"
#include "ModerateCollectionStrategy.h"
#include "FastCollectionStrategy.h"
#include <string>
#include <memory>

/*
The NPCContext class acts as a factory to create WorkerNPC instances
based on the collection strategy selected by the player.
*/

class NPCContext {
public:
    static std::unique_ptr<WorkerNPC> hireNPC(const std::string& npcType);
};

#endif
