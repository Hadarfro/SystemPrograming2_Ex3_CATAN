#ifndef PLAYER_HPP
#define PLAYER_HPP
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <ctime>
#include <cstdlib>
#include "catan.hpp"
#include "resource.hpp"
#include "board.hpp"

class Board;
using namespace std;

// Player class
class Player {
    private:
        string name;
        map<Resource, int> cards;
        int SettelemntAmount;
        int roadAmount;
        int points;
        Board& board;
    public:
        Player(const std::string& myName, Board& b) : name(myName), board(b), SettelemntAmount(2), roadAmount(2), points(2) {
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

        string& getName(){
            return name;
        }

        void placeSettelemnt(int v,Board board);
        void placeRoad(int edge,Board board);
        void endTurn();
        Board& getBoard();
        int rollDice();  
        const string getName() const;
        void trade(Player p, string tradeCard, string givenCard, int amountTrade, int amountGiven);
        void buyDevelopmentCard();
        void printPoints();
        bool hasResource(Resource resource, int amount);
       // void addDevelopmentCard(const DevelopmentCard& card);
        void removeResource(Resource resource, int amount);
};
#endif // PLAYER_HPP