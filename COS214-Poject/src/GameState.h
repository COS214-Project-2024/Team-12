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
    int money = 1000;
    int happiness = 100;

public:
    void executeCommand(std::unique_ptr<Command> command) {
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

    bool spendMoney(int amount) {
        if (money >= amount) {
            money -= amount;
            return true;
        }
        return false;
    }

    void addMoney(int amount) { money += amount; }
    int getMoney() const { return money; }
    int getHappiness() const { return happiness; }
    void updateHappiness(int delta) { 
        happiness = std::clamp(happiness + delta, 0, 100);
    }
};

#endif