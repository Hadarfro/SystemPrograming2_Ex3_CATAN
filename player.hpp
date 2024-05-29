#pragma once
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <ctime>
#include <cstdlib>
#include "catan.hpp"

using namespace std;

// Enum for resource types
enum class Resource { Wood, Brick, Sheep, Wheat, Ore,Sea ,Desert,None };

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

Resource stringToResource(const string& resourceStr) {
    if (resourceStr == "Wood") return Resource::Wood;
    if (resourceStr == "Brick") return Resource::Brick;
    if (resourceStr == "Sheep") return Resource::Sheep;
    if (resourceStr == "Wheat") return Resource::Wheat;
    if (resourceStr == "Ore") return Resource::Ore;
    return Resource::None;
}

// Player class
class Player {
    private:
        string name;
        map<Resource, int> cards;
        int SettelemntAmount;
        int roadAmount;
        int points;
        Board board;
    public:
        Player(string myName = "") : name(myName) {
            cards[Resource::Wood] = 0;
            cards[Resource::Brick] = 0;
            cards[Resource::Sheep] = 0;
            cards[Resource::Wheat] = 0;
            cards[Resource::Ore] = 0;
            SettelemntAmount = 2;
            roadAmount = 2;
            points = 2;
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

        void placeSettelemnt(int v,Board board);
        void placeRoad(int edge,Board board);
        void endTurn();
        Board getBoard();
        int rollDice();  
        const string getName() const;
        void trade(Player p, string tradeCard, string givenCard, int amountTrade, int amountGiven);
        void buyDevelopmentCard();
        void printPoints();
        bool hasResource(Resource resource, int amount);
       // void addDevelopmentCard(const DevelopmentCard& card);
        void removeResource(Resource resource, int amount);
};