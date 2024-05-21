#include "board.hpp"
#include <iostream>
#include <vector>

using namespace std;

// Tile class
class Tile {
public:
    Resource resource;
    int number;

    Tile(Resource resource, int number) : resource(resource), number(number) {}
};

// Board class
class Board {
public:
    vector<Tile> tiles;

    Board() {
        // Simplified board with fixed resources and numbers
        tiles = {
            Tile(Resource::Wood, 5), Tile(Resource::Brick, 6), Tile(Resource::Sheep, 8),
            Tile(Resource::Wheat, 3), Tile(Resource::Ore, 4), Tile(Resource::Wood, 9),
            Tile(Resource::Brick, 10), Tile(Resource::Sheep, 11), Tile(Resource::Wheat, 12)
        };
    }

    void printBoard() const {
        for (const auto& tile : tiles) {
            std::cout << resourceToString(tile.resource) << " (" << tile.number << ")\n";
        }
    }
};