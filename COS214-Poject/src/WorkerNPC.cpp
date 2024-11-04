// #include "WorkerNPC.h"

// WorkerNPC::WorkerNPC(std::string name, double cost, std::unique_ptr<CollectionStrategy> strategy)
//         : name(std::move(name)), cost(cost), strategy(std::move(strategy)) {}

// std::string WorkerNPC::getName() const { return name; }
// double WorkerNPC::getCost() const { return cost; }

// int WorkerNPC::collect(int baseAmount) const {
//     return strategy->collect(baseAmount);  // Use strategy to determine collection amount
// }