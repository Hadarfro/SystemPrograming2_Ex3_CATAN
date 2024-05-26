#include <iostream>
#include <vector>
#include <unordered_map>

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

//Vertex class
class Vertex {
    public:
        int id;
        vector<Tile> tiles;
        vector<int> neighbors;
        vector<int> edges;

        Vertex(int id) : id(id) {}

        void addTile(const Tile& tile) {
            tiles.push_back(tile);
        }

        void addNeighbor(int neighborId) {
            neighbors.push_back(neighborId);
        }

        void addEdge(int edgeId) {
            edges.push_back(edgeId);
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
        vector<vector<Vertex>> vertices; // 2D vector to store vertices
        vector<vector<Edge>> edges; // 2D vector to store edges
    public:
        unordered_map<int, Vertex> vertices;
        unordered_map<int, Edge> edges;
        int edgeCounter;


        Board() {
            // Simplified board with fixed resources and numbers
            vertices = {
               {Tile(Resource::Wood, 11), Tile(Resource::Brick, 2), Tile(Resource::Sheep, 3)},
                {Tile(Resource::Wheat, 4), Tile(Resource::Ore, 5), Tile(Resource::Wood, 6),
                Tile(Resource::Brick, 11)}, {Tile(Resource::Sheep, 8), Tile(Resource::Wheat, 9),
                Tile(Resource::None, 7), Tile(Resource::Wood, 10), Tile(Resource::Sheep, 12)},
                {Tile(Resource::Wheat, 3), Tile(Resource::Ore, 4), Tile(Resource::Wood, 5),
                Tile(Resource::Brick, 6)}, {Tile(Resource::Sheep, 8), Tile(Resource::Wheat, 9),
                Tile(Resource::Brick, 10)}
            };
        }

        void printBoard() const {
            for (const auto& tile : tiles) {
                //std::cout << resourceToString(tile.resource) << " (" << tile.number << ")\n";
            }
        }
};