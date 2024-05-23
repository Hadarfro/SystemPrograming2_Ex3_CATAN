#include <iostream>
#include <vector>

using namespace std;
// Enum for resource types
enum class Resource { Wood, Brick, Sheep, Wheat, Ore, None };

// Function to get string representation of resource
string resourceToString(Resource resource) {
    switch (resource) {
        case Resource::Wood: return "Wood";
        case Resource::Brick: return "Brick";
        case Resource::Sheep: return "Sheep";
        case Resource::Wheat: return "Wheat";
        case Resource::Ore: return "Ore";
        case Resource::None: return "None";
    }
    return "Unknown";
}


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
                Tile(Resource::Wood, 11), Tile(Resource::Brick, 2), Tile(Resource::Sheep, 3),
                Tile(Resource::Wheat, 4), Tile(Resource::Ore, 5), Tile(Resource::Wood, 6),
                Tile(Resource::Brick, 2), Tile(Resource::Sheep, 8), Tile(Resource::Wheat, 9),
                Tile(Resource::Wood, 10), Tile(Resource::Brick, 11), Tile(Resource::Sheep, 12),
                Tile(Resource::Wheat, 3), Tile(Resource::Ore, 4), Tile(Resource::Wood, 5),
                Tile(Resource::Brick, 6), Tile(Resource::Sheep, 8), Tile(Resource::Wheat, 9),
                Tile(Resource::Brick, 10)
            };
        }

        void printBoard() const {
            for (const auto& tile : tiles) {
                std::cout << resourceToString(tile.resource) << " (" << tile.number << ")\n";
            }
        }
};