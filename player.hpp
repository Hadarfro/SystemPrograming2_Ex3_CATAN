#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <ctime>
#include <cstdlib>
#include "board.hpp"

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
        case Resource::None: return "None";
    }
    return "Unknown";
}

// Player class
class Player {
    private:
        string name;
        map<Resource, int> cards;
        Board board;
    public:
        Player(string name = "") : name(name) {
            cards[Resource::Wood] = 0;
            cards[Resource::Brick] = 0;
            cards[Resource::Sheep] = 0;
            cards[Resource::Wheat] = 0;
            cards[Resource::Ore] = 0;
        }

        void addResource(Resource resource, int amount) {
            cards[resource] += amount;
        }

        void printResources() const {
            std::cout << "Resources of " << name << ":\n";
            for (const auto& pair : cards) {
                cout << resourceToString(pair.first) << ": " << pair.second << "\n";
            }
        }

        void placeSettelemnt(vector<string> places,vector<int> placesNum,Board board);
        void placeRoad(vector<string> places,vector<int> placesNum,Board board);
        void endTurn();
        Board getBoard();
        int rollDice();  
        const string getName() const;
        void trade(Player p, string tradeCard, string givenCard, int amountTrade, int amountGiven);
        void buyDevelopmentCard();
        void printPoints();
};