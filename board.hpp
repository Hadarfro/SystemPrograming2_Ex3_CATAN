#include <iostream>
#include <vector>
#include <unordered_map>
#include "player.hpp"

using namespace std;
// Enum for resource types
enum class Resource { Wood, Brick, Sheep, Wheat, Ore, Sea,Desert,None };

// Function to get string representation of resource
string resourceToString(Resource resource) {
    switch (resource) {
        case Resource::Wood: return "Wood";
        case Resource::Brick: return "Brick";
        case Resource::Sheep: return "Sheep";
        case Resource::Wheat: return "Wheat";
        case Resource::Ore: return "Ore";
        case Resource::Sea: return "Sea";
        case Resource::Desert: return "Desert";
    }
    return "Unknown";
}


// Tile class
class Tile {
public:
    Resource resource;
    int number;
    vector<Tile> neighbors;
    Tile(Resource resource, int number,vector<Tile> myneighbors = {}) : resource(resource), number(number) {
        neighbors = myneighbors;
    }
};

// Vertex class
class Vertex {
    private:
        vector<Player> players;
        vector<int> adjacentTiles;
    public:
        void addPlayer(Player player) {
            players.push_back(player);
        }

        void addAdjacentTile(int tileIndex) {
            adjacentTiles.push_back(tileIndex);
        }
};

// Edge class
class Edge {
    public:
        int id;
        int vertex1;
        int vertex2;

        Edge(int id, int vertex1, int vertex2)
            : id(id), vertex1(vertex1), vertex2(vertex2) {}
    };

// Board class
class Board {
    private:
        vector<Tile> tiles;
        vector<Vertex> vertices;
    public:
        Board();

        vector<Tile> getTiles(){
            return tiles;
        }

        void printBoard() const {
            for (const auto& tile : tiles) {
                //std::cout << resourceToString(tile.resource) << " (" << tile.number << ")\n";
            }
        }
        void distributeResources(int roll);
};