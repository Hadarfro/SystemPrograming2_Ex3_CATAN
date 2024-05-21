#include "board.hpp"
#include <iostream>
#include <vector>

using namespace std;


// Board class
class Board {
public:
    vector<Tile> tiles;
    int numPlayer;

    Board() {
        // Simplified board with fixed resources and numbers
        tiles = {
            Tile(Resource::Wood, 11), Tile(Resource::Brick, 2), Tile(Resource::Sheep, 3),
            Tile(Resource::Wheat, 4), Tile(Resource::Ore, 5), Tile(Resource::Wood, 6),
            Tile(Resource::Brick, 2), Tile(Resource::Sheep, 8), Tile(Resource::Wheat, 9),
            Tile(Resource::Wood, 10), Tile(Resource::Brick, 11), Tile(Resource::Sheep, 12),
            Tile(Resource::Wheat, 3), Tile(Resource::Ore, 4), Tile(Resource::Wood, 5),
            Tile(Resource::Brick, 6), Tile(Resource::Sheep, 8), Tile(Resource::Wheat, 9),
            Tile(Resource::Brick, 10)
        };
        numPlayer = 0;
    }

    void printBoard() const {
        for (const auto& tile : tiles) {
            std::cout << resourceToString(tile.resource) << " (" << tile.number << ")\n";
        }
    }
};