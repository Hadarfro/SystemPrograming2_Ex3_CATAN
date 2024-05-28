#include "board.hpp"
#include <iostream>
#include <vector>

using namespace std;

void Board::distributeResources(int roll) {
        for (int i = 0; i < vertices.size();i++) {
                for (int j = 0;j < vertices[i].adjacentTiles.size();j++) {
                    if (vertices[i].adjacentTiles[j] == roll) {
                    for (auto player : vertex->players) {
                        player->addResource(tile.resource, 1);
                    }
                }
            }
        }
    }    