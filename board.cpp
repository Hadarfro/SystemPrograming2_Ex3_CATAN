#include "board.hpp"
#include <iostream>
#include <vector>

using namespace std;

void Board::distributeResources(int roll) const {
    for (int i = 0; i < vertices.size();i++) {
        if (vertices[i].owner.getName() != "") {
            for (int j = 0;j < vertices[i].adjacentTiles.size();j++) {
                if(vertices[i].adjacentTiles[j].getNumber() == roll){
                    vertices[i].owner.addResource(vertices[i].adjacentTiles[j].resource, 1);
                }
            }
        }
    }
}    