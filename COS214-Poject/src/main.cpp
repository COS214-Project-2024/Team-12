#include "CityGame.h"

int main() {
    try {
        CityGame game(25, 25);
        game.run();
    } catch (const std::exception& e) {
        std::cerr << "\033[1;31mError: " << e.what() << "\033[0m\n";
        return 1;
    }
    return 0;
}