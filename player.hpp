/*
 * Author: Hadar Froimowich.
 * ID: 213118458
 * Email: hadarfro12@gmail.com
 */
#pragma once
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <ctime>
#include <cstdlib>
#include <random>
#include <stdexcept>
#include "resource.hpp"
#include "board.hpp"
#include "cards.hpp"

class Board;
using namespace std;

// Player class
class Player {
    private:
        string name;
        mutable map<ResourceCard, int> ResourceCards; // cards can be modified even if it's a part of an object that is declared as const
        mutable map<DevelopmentCard*, int> DevelopmentCards;
        Player* participants[4];
        int SettelemntAmount;
        int CitesAmount;
        int roadAmount;
        int points;
        bool isPlaying;
    public:
        Player(string name = "");// initillezed list
        void addParticipants(Player* participants[]);
        void setIsPlaying(bool flag);
        map<ResourceCard, int> getResourceCard();
        void playMonopolCard();
        bool getIsPlaying();
        int getPoints();
        void addResource(Resource resource, int amount) const;
        void buySettelemnt();
        void buyCity();
        void buyRoad();
        void addPoints(int amount);
        void placeSettelemnt(int v,Board& board);
        void placeCity(int v, Board& board);
        void placeRoad(int edge,Board& board);
        void endTurn();
        void addRandomResources();
        int rollDice() const;  
        const string getName() const;
        void trade(Player& p, string tradeCard, string givenCard, int amountTrade, int amountGiven);
        void buyDevelopmentCard();
        void printPoints();
        bool hasResource(Resource resource, int amount);
        void removeResource(Resource resource, int amount);
        Player& operator=(const Player& other) {  // Copy assignment operator
            if (this != &other) {
                name = other.name;
            }
            return *this;
        }
        void printResources() const {
            cout << "the resources of " << name << " is:" << endl;
            for (const auto& pair : ResourceCards) {
                cout << "there is " << pair.second << " " << resourceToString(pair.first.getResourceType()) << endl;
                //cout << "amount of cards: " << pair.second << endl; 
            }
        }
        void addDevelopmentCard(DevelopmentCard* card);
        string& getName(){
            return name;
        }
        int getSettlementAmount(){
            return SettelemntAmount;
        }
        int getRoadAmount(){
            return roadAmount;
        }
};