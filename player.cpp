#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <ctime>
#include <cstdlib>
#include <cstring>
#include "player.hpp"

using namespace std;

Player::Player(string myName) : name(myName), SettelemntAmount(2), roadAmount(2), points(2) {
    ResourceCards[Resource::Wood] = 0;
    ResourceCards[Resource::Brick] = 0;
    ResourceCards[Resource::Sheep] = 0;
    ResourceCards[Resource::Wheat] = 0;
    ResourceCards[Resource::Ore] = 0;
    isPlaying = false;
}

void Player::addResource(Resource resource, int amount) const {
    cout << "adding " << amount << " " << resourceToString(resource) << " to " << name << endl;
    ResourceCards[resource] += amount;
}

const string Player::getName() const{
    return name;
}

void Player::setIsPlaying(bool flag){
    isPlaying = flag;
}

bool Player::getIsPlaying(){
    return isPlaying;
}

void Player::placeSettelemnt(int v,Board& board){
    size_t u = (size_t) v;
    if(board.getVertcis()[u].owner != ""){ 
        throw runtime_error("place is taken");
        return;
    }
    if(this->SettelemntAmount == 0){
        cout << "no settelments to place" << endl;
        return;
    }
    board.getVertcis()[u].owner = name;
    this->SettelemntAmount--;
}

void Player::placeRoad(int edge,Board& board){//need to continue
    size_t v = (size_t) edge;
    if(roadAmount == 0){
        cout << "no roads to place" << endl;
        return;
    }
    if(board.getEdges()[v].owner != ""){
        cout << "place is taken by " << board.getEdges()[v].owner << endl;
        return;
    }
    board.getEdges()[v].owner = name;
    roadAmount--;
}

bool Player::hasResource(Resource resource, int amount) {
    return ResourceCards[resource] >= amount;
}

void Player::removeResource(Resource resource, int amount) {
    if (hasResource(resource, amount)) {
        ResourceCards[resource] -= amount;
    }
}

void Player::addDevelopmentCard(const DevelopmentCard& card) {
    //  Increment the count if the card exists, otherwise add it with count 1
    auto it = DevelopmentCards.find(card);
    if (it != DevelopmentCards.end()) {
        ++(it->second);
    } 
    else {
        DevelopmentCards[card] = 1;
    }
}

void Player::endTurn(){//need to continue
    setIsPlaying(false);
}

void Player::trade(Player p, string tradeCard, string givenCard, int amountTrade, int amountGiven){
    Resource tradeResource = stringToResource(tradeCard);
    Resource givenResource = stringToResource(givenCard);

    if (tradeResource == Resource::None || givenResource == Resource::None) {
        cout << "Invalid resource type for trading." << endl;
        return;
    }

    if (p.hasResource(givenResource, amountGiven)&&hasResource(tradeResource, amountTrade)) {
        p.removeResource(givenResource, amountGiven);
        p.addResource(tradeResource, amountTrade);
        addResource(givenResource,amountGiven);
        removeResource(tradeResource, amountTrade);
        cout << "Trade successful: " << amountTrade << " " << tradeCard << " for " << amountGiven << " " << givenCard << endl;
    } 
    else {
        cout << "Trade failed: Not enough resources." << endl;
    }
}

void Player::buyDevelopmentCard(){ //continue after there's edges in the board 
    if (this->hasResource(Resource::Wheat, 1) && this->hasResource(Resource::Sheep, 1) && this->hasResource(Resource::Ore, 1)) {
        this->removeResource(Resource::Wheat, 1);
        this->removeResource(Resource::Sheep, 1);
        this->removeResource(Resource::Ore, 1);

        DevelopmentCard newCard("Development"); // Assuming all development ResourceCards are the same for simplicity.
        this->addDevelopmentCard(newCard);
        cout << "Development card purchased successfully." << endl;
    } 
    else {
        cout << "Purchase failed: Not enough resources." << endl;
    }
}

void Player::buySettelemnt(){ //continue after there's edges in the board 
    if (this->hasResource(Resource::Wheat, 1) && this->hasResource(Resource::Sheep, 1) && this->hasResource(Resource::Wood, 1) && this->hasResource(Resource::Brick, 1)) {
        this->removeResource(Resource::Wheat, 1);
        this->removeResource(Resource::Sheep, 1);
        this->removeResource(Resource::Wood, 1);
        this->removeResource(Resource::Brick, 1);

        SettelemntAmount++;
        cout << "Settelment purchased successfully." << endl;
    } 
    else {
        cout << "Purchase failed: Not enough resources." << endl;
    }
}

void Player::buyRoad(){ //continue after there's edges in the board 
    if (this->hasResource(Resource::Wood, 1) && this->hasResource(Resource::Brick, 1)) {
        this->removeResource(Resource::Wood, 1);
        this->removeResource(Resource::Brick, 1);

        roadAmount++;
        cout << "Road purchased successfully." << endl;
    } 
    else {
        cout << "Purchase failed: Not enough resources." << endl;
    }
}

void Player::printPoints(){
    cout << name << " have " << points << " points" << endl;
}

int Player::rollDice() const{
    int roll = (rand() % 6 + 1) + (rand() % 6 + 1); // Rolling two six-sided dice
    cout << "Dice roll is: " << roll << "\n";
    return roll;
}

int Player::getPoints(){
    return points;
}
