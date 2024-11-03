#ifndef GAMESTATE_H
#define GAMESTATE_H

#include <vector>
#include <memory>
#include <algorithm>
#include "Command.h"
#include "GameStateMemento.h"

class GameState {
private:
    std::vector<std::unique_ptr<Command>> commandHistory;
    size_t currentCommandIndex = 0;

public:
    std::unique_ptr<GameStateMemento> createMemento() const {
        return std::make_unique<GameStateMemento>(commandHistory, currentCommandIndex);
    }

    void restoreFromMemento(const GameStateMemento& memento) {
        // Clear existing state
        commandHistory.clear();
        
        // Restore command history
        for (const auto& cmd : memento.commandHistory) {
            commandHistory.push_back(cmd->clone());
        }
        
        // Restore index
        currentCommandIndex = memento.currentCommandIndex;
    }

    void executeCommand(std::unique_ptr<Command> command) {
        // Clear redo history when new command is executed
        while (commandHistory.size() > currentCommandIndex) {
            commandHistory.pop_back();
        }
        
        command->execute();
        commandHistory.push_back(std::move(command));
        currentCommandIndex++;
    }
    
    void undo() {
        if (currentCommandIndex > 0) {
            currentCommandIndex--;
            commandHistory[currentCommandIndex]->undo();
        }
    }
    
    void redo() {
        if (currentCommandIndex < commandHistory.size()) {
            commandHistory[currentCommandIndex]->execute();
            currentCommandIndex++;
        }
    }
};

#endif