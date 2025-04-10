#include <iostream>
#include <limits>

#include "GameState.h"

int main() {
    std::cout << "hello world" << "\n";
    auto* game = new game::GameState();
    bool gameEnd = false;
    int player = 0;
    while (!gameEnd) {
        std::cout << "Player" << player << " chooses row: ";
        int input;
        std::cin >> input;
        if (std::cin.fail()) {
            std::cout << "Invalid Input";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        if (game->place(player, input)) {
            std::cout << "Player" << player << " wins.";
            gameEnd = true;
        }
        if (player == 0) {
            player = 1;
        }else {
            player = 0;
        }
    }
}
