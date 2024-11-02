#include "NPCContext.h"

std::unique_ptr<WorkerNPC> NPCContext::hireNPC(const std::string& npcType) {
        if (npcType == "Slow") {
            return std::make_unique<WorkerNPC>(
                "Slow Worker", 
                50.0, 
                std::make_unique<SlowCollectionStrategy>()
            );
        } else if (npcType == "Moderate") {
            return std::make_unique<WorkerNPC>(
                "Moderate Worker", 
                100.0, 
                std::make_unique<ModerateCollectionStrategy>()
            );
        } else if (npcType == "Fast") {
            return std::make_unique<WorkerNPC>(
                "Fast Worker", 
                200.0, 
                std::make_unique<FastCollectionStrategy>()
            );
        }
        return nullptr;
    }