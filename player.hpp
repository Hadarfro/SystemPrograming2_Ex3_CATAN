#pragma once
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <ctime>
#include <cstdlib>
#include "catan.hpp"
#include "resource.hpp"
#include "board.hpp"
#include "player.hpp"

class Board;
using namespace std;

// Player class
class Player {
    private:
        string name;
        mutable map<Resource, int> cards; // cards can be modified even if it's a part of an object that is declared as const
        int SettelemntAmount;
        int roadAmount;
        int points;
        const Board* board;
    public:
        Player(const string& name = "", const Board* b = nullptr);// initillezed list

        void addResource(Resource resource, int amount) const;
        void printResources() const {
            cout << "Resources of " << name << ":\n";
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
        const Board* getBoard();
        int rollDice();  
        const string getName() const;
        void trade(Player p, string tradeCard, string givenCard, int amountTrade, int amountGiven);
        void buyDevelopmentCard();
        void printPoints();
        bool hasResource(Resource resource, int amount);
       // void addDevelopmentCard(const DevelopmentCard& card);
        void removeResource(Resource resource, int amount);
};
