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
        const Board& board;
    public:
        Player(const string& myName = "",const Board& b = Board());

        void addResource(Resource resource, int amount);
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
        const Board& getBoard();
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