#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <ctime>
#include <cstdlib>

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

class Catan {
    private:
        Board board;
        vector<Player> players;
        int currentPlayer;

    public:
    Catan(Player p1,Player p2,Player p3){//continue!!!!!!!!!!!!11
        players[1] = p1;
        players[2] = p2;
        players[3] = p3;
    }

    void ChooseStartingPlayer();
    Board getBoard();
    void printWinner();
};
