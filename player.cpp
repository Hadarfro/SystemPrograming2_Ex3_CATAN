/*
 * Author: Hadar Froimowich.
 * ID: 213118458
 * Email: hadarfro12@gmail.com
 */
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <ctime>
#include <cstdlib>
#include <cstring>
#include "player.hpp"

using namespace std;

// Player class constructor
Player::Player(string myName) : name(myName), SettelemntAmount(2), CitesAmount(0), roadAmount(2), points(2) {
    // Initialize resource cards to 0
    ResourceCards[Resource::Wood] = 0;
    ResourceCards[Resource::Brick] = 0;
    ResourceCards[Resource::Sheep] = 0;
    ResourceCards[Resource::Wheat] = 0;
    ResourceCards[Resource::Ore] = 0;
    isPlaying = false;
}

// Method to add a resource to the player
void Player::addResource(Resource resource, int amount) const {
    cout << "adding " << amount << " " << resourceToString(resource) << " to " << name << endl;
    ResourceCards[resource] += amount;
}

// Method to get the player's name
const string Player::getName() const{
    return name;
}

// Method to set the player's playing status
void Player::setIsPlaying(bool flag){
    isPlaying = flag;
    cout << "the player is " << (flag ? "" : "not ") << "playing" << endl;
}

// Method to get the player's playing status
bool Player::getIsPlaying(){
    return isPlaying;
}

// Method to add points to the player
void Player::addPoints(int amount){
    points += amount; 
}

// Method to place a settlement on the board
void Player::placeSettelemnt(int v, Board& board){
    size_t u = (size_t) v;
    if(board.getVertcis()[u].owner != ""){ 
        throw runtime_error("place is taken");
        return;
    }
    if(this->SettelemntAmount == 0){
        cout << "no settlements to place" << endl;
        return;
    }
    board.getVertcis()[u].owner = name;
    this->SettelemntAmount--;
}

// Method to place a settlement on the board
void Player::placeCity(int v, Board& board){
    size_t u = (size_t) v;
    if(board.getVertcis()[u].owner != ""){ 
        throw runtime_error("place is taken");
        return;
    }
    if(this->CitesAmount == 0){
        cout << "no cites to place" << endl;
        return;
    }
    board.getVertcis()[u].owner = name;
    board.getVertcis()[u].isCity = true;
    this->CitesAmount--;
}

// Method to place a road on the board
void Player::placeRoad(int edge, Board& board){
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

// Method to check if the player has a certain amount of a resource
bool Player::hasResource(Resource resource, int amount) {
    cout << "you have " << ResourceCards[resource] << " " << resourceToString(resource) << endl;
    return ResourceCards[resource] >= amount;
}

// Method to remove a resource from the player
void Player::removeResource(Resource resource, int amount) {
    if (hasResource(resource, amount)) {
        ResourceCards[resource] -= amount;
    }
}

// Method to add a development card to the player
void Player::addDevelopmentCard(DevelopmentCard* card) {
    DevelopmentCards[card]++;
}

// Method to end the player's turn
void Player::endTurn(){
    setIsPlaying(false);
    cout << name << " has ended their turn" << endl;
}

// Method to trade resources with another player
void Player::trade(Player& p, string tradeCard, string givenCard, int amountTrade, int amountGiven){
    Resource tradeResource = stringToResource(tradeCard);
    Resource givenResource = stringToResource(givenCard);

    if (tradeResource == Resource::None || givenResource == Resource::None) {
        cout << "Invalid resource type for trading." << endl;
        return;
    }

    if (p.hasResource(givenResource, amountGiven) && hasResource(tradeResource, amountTrade)) {
        p.removeResource(givenResource, amountGiven);
        p.addResource(tradeResource, amountTrade);
        addResource(givenResource, amountGiven);
        removeResource(tradeResource, amountTrade);
        cout << "Trade successful: " << amountTrade << " " << tradeCard << " for " << amountGiven << " " << givenCard << endl;
    } 
    else {
        cout << "Trade failed: Not enough resources." << endl;
    }
}

// Method to buy a development card
void Player::buyDevelopmentCard(){ 
    if (this->hasResource(Resource::Wheat, 1) && this->hasResource(Resource::Sheep, 1) && this->hasResource(Resource::Ore, 1)) {
        this->removeResource(Resource::Wheat, 1);
        this->removeResource(Resource::Sheep, 1);
        this->removeResource(Resource::Ore, 1);
        
        // Seed random number generator
        srand(static_cast<unsigned int>(time(nullptr)));

        // Randomly select a type of development card
        int cardType = rand() % 5; // Assuming 5 types of development cards

        //DevelopmentCard* newCard = nullptr;
        switch (cardType) {
            case 0:
                //newCard = new KnightCard();
                cout << "got a knight" << endl;
                //this->addDevelopmentCard(newCard);
                break;
            case 1:
                cout << name << " got a victory point" << endl;
                points++;
                break;
            case 2:
                cout << name << " got a Road Building card" << endl;
                roadAmount += 2;
                break;
            case 3:
                cout << name << " got a Year Of Plenty Card" << endl;
                addRandomResources();
                break;
            case 4:
                playMonopolCard();
                break;
            default:
                cout << "Invalid card type." << endl;
                return;
        }
        cout << "Development card purchased successfully." << endl;
    } 
    else {
        cout << "Purchase failed: Not enough resources." << endl;
    }
}

// Method to buy a settlement
void Player::buySettelemnt(){
    if (this->hasResource(Resource::Wheat, 1) && this->hasResource(Resource::Sheep, 1) && this->hasResource(Resource::Wood, 1) && this->hasResource(Resource::Brick, 1)) {
        this->removeResource(Resource::Wheat, 1);
        this->removeResource(Resource::Sheep, 1);
        this->removeResource(Resource::Wood, 1);
        this->removeResource(Resource::Brick, 1);

        SettelemntAmount++;
        points++;
        cout << "Settlement purchased successfully." << endl;
    } 
    else {
        cout << "Purchase failed: Not enough resources." << endl;
    }
}

// Method to buy a city
void Player::buyCity(){
    if (this->hasResource(Resource::Wheat, 2) && this->hasResource(Resource::Ore, 3)) {
        this->removeResource(Resource::Wheat, 2);
        this->removeResource(Resource::Ore, 3);

        CitesAmount++;
        addPoints(2);
        cout << "City purchased successfully." << endl;
    } 
    else {
        cout << "Purchase failed: Not enough resources." << endl;
    }
}

// Method to buy a road
void Player::buyRoad(){
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

// Method to print the player's points
void Player::printPoints(){
    cout << name << " has " << points << " points" << endl;
}

// Method to roll dice
int Player::rollDice() const{
    int roll = (rand() % 6 + 1) + (rand() % 6 + 1); // Rolling two six-sided dice
    cout << "Dice roll is: " << roll << "\n";
    return roll;
}

// Method to get the player's points
int Player::getPoints(){
    return points;
}

// Method to add random resources to the player
void Player::addRandomResources() {
    // Seed random number generator
    srand(static_cast<unsigned int>(time(nullptr)));

    // Add two random resources
    for (int i = 0; i < 2; ++i) {
        // Randomly select a resource type
        int resourceType = rand() % 5; // Assuming 5 types of resources

        Resource randomResource = static_cast<Resource>(resourceType);

        // Add the random resource to the player's resources
        addResource(randomResource, 1);
    }

    cout << "Added 2 random resources to " << name << endl;
}

// Method to add participants to the game
void Player::addParticipants(Player* newParticipants[]){
    for (size_t i = 0; i < 4; i++){
        participants[i] = newParticipants[i];
    }    
}

// Method to get the player's resource cards
map<ResourceCard, int> Player::getResourceCard(){
    return ResourceCards;
}

// Method to play the Monopoly card
void Player::playMonopolCard(){
    int amount = 0;
    int currentAmount = 0;
    // Randomly select a resource type
    int resourceType = rand() % 5; // Assuming 5 types of resources
    Resource randomResource = static_cast<Resource>(resourceType);
    for(size_t i = 0; i < 4; i++){
        currentAmount = 0;
        if(participants[i]->getName() != "" && participants[i]->getName() != name){
            if(participants[i]->hasResource(randomResource, 1)){
                currentAmount = participants[i]->getResourceCard()[randomResource];
                amount += currentAmount;
                participants[i]->removeResource(randomResource, currentAmount);
            }
        }
    }
    addResource(randomResource, amount);
}
