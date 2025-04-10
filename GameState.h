//
// Created by user on 10.04.2025.
//

#ifndef GAMESTATE_H
#define GAMESTATE_H
#include <vector>
#include "Point.h"

namespace game {

class GameState {
private:
    std::pmr::vector<Point> points[2];
    [[nodiscard]] bool checkWin(int player, const Point* origin) const;
public:
    int place(int player, int row_x);
};

} // game

#endif //GAMESTATE_H
