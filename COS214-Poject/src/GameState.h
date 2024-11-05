#ifndef GAMESTATE_H
#define GAMESTATE_H

#include <vector>
#include <memory>
#include <algorithm>
#include "Command.h"
#include "GameStateMemento.h"

/**
 * @brief Manages the game state and command history.
 *
 * The GameState class maintains a history of executed commands
 * and allows undoing and redoing of commands. It also supports
 * saving and restoring the game state using mementos.
 */
class GameState {
private:
    std::vector<std::unique_ptr<Command>> commandHistory; /**< A history of executed commands. */
    size_t currentCommandIndex = 0; /**< The index of the current command for undo/redo operations. */

public:
    /**
     * @brief Creates a memento that captures the current game state.
     * 
     * @return std::unique_ptr<GameStateMemento> A unique pointer to the created memento,
     * containing the current command history and index.
     */
    std::unique_ptr<GameStateMemento> createMemento() const {
        return std::make_unique<GameStateMemento>(commandHistory, currentCommandIndex);
    }

    /**
     * @brief Restores the game state from a given memento.
     * 
     * This function clears the existing command history and restores
     * it from the specified memento, including the current command index.
     * 
     * @param memento The memento to restore the game state from.
     */
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

    /**
     * @brief Executes a command and adds it to the command history.
     * 
     * This method clears any redo history when a new command is executed,
     * then executes the command and adds it to the history.
     * 
     * @param command A unique pointer to the command to execute.
     */
    void executeCommand(std::unique_ptr<Command> command) {
        // Clear redo history when new command is executed
        while (commandHistory.size() > currentCommandIndex) {
            commandHistory.pop_back();
        }
        
        command->execute();
        commandHistory.push_back(std::move(command));
        currentCommandIndex++;
    }
    
    /**
     * @brief Undoes the last executed command.
     * 
     * If there is a command to undo, it decrements the current command index
     * and invokes the undo operation on the last command.
     */
    void undo() {
        if (currentCommandIndex > 0) {
            currentCommandIndex--;
            commandHistory[currentCommandIndex]->undo();
        }
    }
    
    /**
     * @brief Redoes the last undone command.
     * 
     * If there is a command to redo, it executes the command at the current
     * command index and increments the index.
     */
    void redo() {
        if (currentCommandIndex < commandHistory.size()) {
            commandHistory[currentCommandIndex]->execute();
            currentCommandIndex++;
        }
    }
};

#endif
