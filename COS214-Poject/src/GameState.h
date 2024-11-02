#ifndef GAMESTATE_H
#define GAMESTATE_H

#include <vector>
#include <memory>
#include <algorithm>
#include "Command.h"

class GameState {
private:
    std::vector<std::unique_ptr<Command>> commandHistory;
    size_t currentCommandIndex = 0;

public:
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