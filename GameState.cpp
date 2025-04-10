//
// Created by user on 10.04.2025.
//

#include "GameState.h"
#include "Point.h"

namespace game {
    int GameState::place(const int player, const int row_x) {
        int highest_y = 0;
        for (const Point point: points[0]) {
            if (point.x == row_x) {
                highest_y = point.y;
            }
        }
        for (const Point point: points[1]) {
            if (point.x == row_x) {
                highest_y = point.y;
            }
        }
        const auto* p = new Point(row_x, highest_y + 1);
        points[player].push_back(*p);
        if (checkWin(player, p)) {
            return 1;
        }
        return 0;
    }
    bool GameState::checkWin(const int player, const Point * origin) const {
        // for any given point there are many patterns to win
        int horizontal = 1;
        int vertical = 1;
        for (const auto point: this->points[player]) {
            if (point.y == origin->y) {
                //to left
                if (point.x == origin->x-1) {
                    horizontal++;
                }
                if (point.x == origin->x-2) {
                    horizontal++;
                }
                if (point.x == origin->x-3) {
                    horizontal++;
                }
                //to right
                if (point.x == origin->x+1) {
                    horizontal++;
                }
                if (point.x == origin->x+2) {
                    horizontal++;
                }
                if (point.x == origin->x+3) {
                    horizontal++;
                }
                if (horizontal >= 4){return true;}
            }
            //wait origin is last placed there only need to be checks for vertical going down, upwards cant exist
            //vertical checks
            if (origin->y >= 4 && point.x == origin->x) {
                if (point.y == origin->y-1) {
                    vertical++;
                }
                if (point.y == origin->y-2) {
                    vertical++;
                }
                if (point.y == origin->y-3) {
                    vertical++;
                }
            }
            if (vertical==4){return true;}
            //diagonal checks
            /*
            *#     #
            * #   #
            *  # #
            *   #
            *  # #
            * #   #
            *#     #
             */
            int top_left_diagonal = 0;
            int bottom_left_diagonal = 0;
            for (int i = -3; i < 4; i++) {
                if (point.x == origin->x+i) {
                    if (point.y == origin->y-i) {
                        top_left_diagonal++;
                    }
                    if (point.y == origin->y+i) {
                        bottom_left_diagonal++;
                    }
                }
            }
            if (top_left_diagonal>=4) {return true;}
            if (bottom_left_diagonal>=4){return true;}
        }
        return false;
    }


} // game