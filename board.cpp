#include "board.hpp"
#include <iostream>
#include <vector>

using namespace std;

void Board::distributeResources(int roll) {
        for (auto& tile : tiles) {
            if (tile.number == roll) {
                for (auto vertex : tile.vertices) {
                    for (auto player : vertex->players) {
                        player->addResource(tile.resource, 1);
                    }
                }
            }
        }
    }    