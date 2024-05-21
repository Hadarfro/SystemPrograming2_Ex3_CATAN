#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <ctime>
#include <cstdlib>
using namespace std;

// Enum for resource types
enum class Resource { Wood, Brick, Sheep, Wheat, Ore,Devloping, None };

// Function to get string representation of resource
string resourceToString(Resource resource) {
    switch (resource) {
        case Resource::Wood: return "Wood";
        case Resource::Brick: return "Brick";
        case Resource::Sheep: return "Sheep";
        case Resource::Wheat: return "Wheat";
        case Resource::Ore: return "Ore";
        case Resource::Devloping: return "Devloping";
        case Resource::None: return "None";
    }
    return "Unknown";
}

// Player class
class Player {
    private:
    string name;
    map<Resource, int> resources;
    Board board;
    public:
    Player(string name) : name(name) {
        resources[Resource::Wood] = 0;
        resources[Resource::Brick] = 0;
        resources[Resource::Sheep] = 0;
        resources[Resource::Wheat] = 0;
        resources[Resource::Ore] = 0;
    }

    void addResource(Resource resource, int amount) {
        resources[resource] += amount;
    }

    void printResources() const {
        std::cout << "Resources of " << name << ":\n";
        for (const auto& pair : resources) {
            std::cout << resourceToString(pair.first) << ": " << pair.second << "\n";
        }
    }

    void placeSettelemnt(vector<string> places,vector<int> placesNum,Board board);
    void placeRoad(vector<string> places,vector<int> placesNum,Board board);
    int rollDice();
    void endTurn();
    void trade(Player p, string tradeCard, string givenCard, int amountTrade, int amountGiven);
    void buyDevelopmentCard();
    void printPoints();
};