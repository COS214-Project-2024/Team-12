#ifndef NPC_SYSTEM_H
#define NPC_SYSTEM_H

#include <string>
#include <memory>

/**
 * @brief Base class for collection strategies in the NPC system.
 * 
 * Provides an interface for defining different collection efficiency levels
 * for Worker NPCs.
 */
class CollectionStrategy {
public:
    virtual ~CollectionStrategy() = default;

    /**
     * @brief Pure virtual function to determine collection efficiency.
     * 
     * @param amount The base amount to be collected.
     * @return int The adjusted amount based on the strategy's efficiency.
     */
    virtual int collect(int amount) const = 0;
};

/**
 * @brief Collection strategy for slow collection rate.
 * 
 * Implements a 50% collection efficiency.
 */
class SlowCollectionStrategy : public CollectionStrategy {
public:
    int collect(int amount) const override { 
        return amount / 2;  ///< Returns half of the input amount.
    }
};

/**
 * @brief Collection strategy for moderate collection rate.
 * 
 * Implements a 100% collection efficiency.
 */
class ModerateCollectionStrategy : public CollectionStrategy {
public:
    int collect(int amount) const override { 
        return amount; ///< Returns the input amount unchanged.
    }
};

/**
 * @brief Collection strategy for fast collection rate.
 * 
 * Implements a 200% collection efficiency.
 */
class FastCollectionStrategy : public CollectionStrategy {
public:
    int collect(int amount) const override { 
        return amount * 2; ///< Returns double the input amount.
    }
};

/**
 * @brief Represents a Worker NPC that collects resources.
 * 
 * Uses a collection strategy to determine the NPC's collection efficiency.
 */
class WorkerNPC {
private:
    std::string name; ///< Name of the Worker NPC.
    double cost;      ///< Cost of hiring the Worker NPC.
    std::unique_ptr<CollectionStrategy> strategy; ///< Strategy for resource collection.

public:
    /**
     * @brief Constructs a Worker NPC with a specific name, cost, and collection strategy.
     * 
     * @param workerName The name of the Worker NPC.
     * @param workerCost The cost associated with the Worker NPC.
     * @param collectionStrategy The strategy for resource collection.
     */
    WorkerNPC(const std::string& workerName, double workerCost, 
              std::unique_ptr<CollectionStrategy> collectionStrategy);

    /**
     * @brief Gets the name of the Worker NPC.
     * 
     * @return std::string The NPC's name.
     */
    std::string getName() const;

    /**
     * @brief Gets the cost of the Worker NPC.
     * 
     * @return double The hiring cost of the Worker NPC.
     */
    double getCost() const;

    /**
     * @brief Collects resources based on the collection strategy.
     * 
     * @param amount The base amount to be collected.
     * @return int The amount collected after applying the collection strategy.
     */
    int collect(int amount) const;
};

/**
 * @brief Factory class to hire Worker NPCs with specific collection strategies.
 * 
 * Creates different types of Worker NPCs based on the specified type.
 */
class NPCContext {
public:
    /**
     * @brief Hires a Worker NPC of a specified type.
     * 
     * The type determines the collection strategy and cost of the NPC.
     * 
     * @param npcType The type of NPC to hire ("Slow", "Moderate", "Fast").
     * @return std::unique_ptr<WorkerNPC> A unique pointer to the hired Worker NPC.
     */
    static std::unique_ptr<WorkerNPC> hireNPC(const std::string& npcType);
};

#endif // NPC_SYSTEM_H
