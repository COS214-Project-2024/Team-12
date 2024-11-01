#ifndef NPC_SYSTEM_H
#define NPC_SYSTEM_H

#include <string>
#include <memory>

// Base strategy class
class CollectionStrategy {
public:
    virtual ~CollectionStrategy() = default;
    virtual int collect(int amount) const = 0;
};

// Concrete strategies
class SlowCollectionStrategy : public CollectionStrategy {
public:
    int collect(int amount) const override { 
        return amount / 2;  // 50% efficiency
    }
};

class ModerateCollectionStrategy : public CollectionStrategy {
public:
    int collect(int amount) const override { 
        return amount;      // 100% efficiency
    }
};

class FastCollectionStrategy : public CollectionStrategy {
public:
    int collect(int amount) const override { 
        return amount * 2;  // 200% efficiency
    }
};

// Worker NPC class
class WorkerNPC {
private:
    std::string name;
    double cost;
    std::unique_ptr<CollectionStrategy> strategy;

public:
    WorkerNPC(const std::string& workerName, double workerCost, 
              std::unique_ptr<CollectionStrategy> collectionStrategy)
        : name(workerName), cost(workerCost), strategy(std::move(collectionStrategy)) {}

    std::string getName() const { return name; }
    double getCost() const { return cost; }
    
    int collect(int amount) const {
        if (strategy) {
            return strategy->collect(amount);
        }
        return 0;
    }
};

// NPC Factory class
class NPCContext {
public:
    static std::unique_ptr<WorkerNPC> hireNPC(const std::string& npcType) {
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
};

#endif