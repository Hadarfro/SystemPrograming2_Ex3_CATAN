#include "board.hpp"
#include <iostream>
#include <vector>

using namespace std;
Board() {
    Tile tile1 = Tile(Resource::Wood, 11,{Tile(Resource::Brick, 2),Tile(Resource::Wheat, 4),Tile(Resource::Ore, 5),Tile(Resource::Sea,0)});
    Tile tile2 = Tile(Resource::Brick, 2,{tile1,Tile(Resource::Ore, 5),Tile(Resource::Wood, 6),Tile(Resource::Sheep, 3),Tile(Resource::Sea,0)});
    Tile tile3 = Tile(Resource::Sheep, 3,{tile2,Tile(Resource::Ore, 5),Tile(Resource::Wood, 6),Tile(Resource::Brick, 11),Tile(Resource::Sea,0)});
    Tile tile4 = Tile(Resource::Wheat, 4,{tile1,Tile(Resource::Ore, 5),Tile(Resource::Wheat, 9),Tile(Resource::Sheep, 8)});
    Tile tile5 = Tile(Resource::Ore, 5,{tile1,tile2,tile4,Tile(Resource::Wood, 6),Tile(Resource::Wheat, 9),Tile(Resource::Desert, 7)});
    Tile tile6 = Tile(Resource::Wood, 6,{tile5,tile2,tile3,Tile(Resource::Brick, 11),Tile(Resource::Wood, 10),Tile(Resource::Desert, 7)});
    Tile tile7 = Tile(Resource::Brick, 11,{tile6,tile3,Tile(Resource::Wood, 10),Tile(Resource::Wood, 10),Tile(Resource::Sea, 0)});
    Tile tile8 = Tile(Resource::Sheep, 8,{tile4,Tile(Resource::Wheat, 9),Tile(Resource::Wheat, 3),Tile(Resource::Sea, 0)});
    Tile tile9 = Tile(Resource::Wheat, 9,{tile4,tile5,tile8,Tile(Resource::Wheat, 3),Tile(Resource::Ore, 4),Tile(Resource::Desert, 7)});
    Tile tile10 = Tile(Resource::Desert, 7,{tile9,tile5,tile6,Tile(Resource::Wood, 10),Tile(Resource::Wood, 5),Tile(Resource::Ore, 4)});
    Tile tile11 = Tile(Resource::Wood, 10,{tile6,tile7,tile10,Tile(Resource::Sheep, 12),Tile(Resource::Ore, 6),Tile(Resource::Wood, 5)});
    Tile tile12 = Tile(Resource::Sheep, 12,{tile7,tile11,Tile(Resource::Brick, 6),Tile(Resource::Sea, 0)});
    Tile tile13 = Tile(Resource::Wheat, 3,{tile8,tile9,Tile(Resource::Ore, 4),Tile(Resource::Sheep, 8),Tile(Resource::Sea, 0)});
    Tile tile14 = Tile(Resource::Ore, 4,{tile13,tile9,tile10,Tile(Resource::Wood, 5),Tile(Resource::Wheat, 9),Tile(Resource::Sheep, 8)});
    Tile tile15 = Tile(Resource::Wood, 5,{tile14,tile10,tile11,Tile(Resource::Brick, 6),Tile(Resource::Brick, 10),Tile(Resource::Wheat, 9)});
    Tile tile16 = Tile(Resource::Brick, 6,{tile15,tile11,tile12,Tile(Resource::Brick, 10),Tile(Resource::Sea, 0)});
    Tile tile17 = Tile(Resource::Sheep, 8,{tile13,tile14,Tile(Resource::Wheat, 9),Tile(Resource::Sea, 0)});
    Tile tile18 = Tile(Resource::Wheat, 9,{tile17,tile14,tile15,Tile(Resource::Brick, 10),Tile(Resource::Sea, 0)});
    Tile tile19 = Tile(Resource::Brick, 10,{tile18,tile15,tile16,Tile(Resource::Sea, 0)});
            
    // Simplified board with fixed resources and numbers
            
    tiles = {tile1,tile2,tile3,tile4,tile5,tile6,tile7,
        tile8,tile9,tile10,tile11,tile12,tile13,
        tile14,tile15,tile16,tile17,tile18,tile19
    };

        // Create vertices
    vertices.resize(54);
}
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