#ifndef GAMESTATEMEMENTO_H
#define GAMESTATEMEMENTO_H

#include <vector>
#include <memory>
#include "Command.h"

class GameStateMemento {
private:
    std::vector<std::unique_ptr<Command>> commandHistory;
    size_t currentCommandIndex;

public:
    friend class GameState;

    GameStateMemento(const std::vector<std::unique_ptr<Command>>& history, size_t index)
        : currentCommandIndex(index) {
        for (const auto& cmd : history) {
            commandHistory.push_back(cmd->clone());
        }
    }
    // Static factory method
    static std::unique_ptr<GameStateMemento> create(
        const std::vector<std::unique_ptr<Command>>& history, 
        size_t index) 
    {
        return std::unique_ptr<GameStateMemento>(
            new GameStateMemento(history, index)
        );
    }
};

#endif