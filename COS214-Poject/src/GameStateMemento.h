#ifndef GAMESTATEMEMENTO_H
#define GAMESTATEMEMENTO_H

#include <vector>
#include <memory>
#include "Command.h"

/**
 * @class GameStateMemento
 * @brief Represents a memento for the GameState, capturing command history and the current command index.
 *
 * The GameStateMemento class allows for saving and restoring the state of the game, specifically the history
 * of commands executed and the current position in that history. It provides a way to implement undo and redo
 * functionality.
 */
class GameStateMemento {
private:
    std::vector<std::unique_ptr<Command>> commandHistory; ///< The history of commands executed.
    size_t currentCommandIndex; ///< The index of the current command in the history.

public:
    friend class GameState; ///< Allows GameState to access private members.

    /**
     * @brief Constructs a GameStateMemento with a command history and current command index.
     * @param history A vector of unique pointers to the command history.
     * @param index The current command index.
     */
    GameStateMemento(const std::vector<std::unique_ptr<Command>>& history, size_t index)
        : currentCommandIndex(index) {
        for (const auto& cmd : history) {
            commandHistory.push_back(cmd->clone());
        }
    }

    /**
     * @brief Static factory method to create a new GameStateMemento instance.
     * @param history A vector of unique pointers to the command history.
     * @param index The current command index.
     * @return A unique pointer to the newly created GameStateMemento.
     */
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
