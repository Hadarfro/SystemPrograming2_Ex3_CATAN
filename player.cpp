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
    cout << "the player is " << flag << " playing" << endl;
}

bool Player::getIsPlaying(){
    return isPlaying;
}
void Player::addPoints(int amount){
    points += amount; 
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
    cout << "you have " << ResourceCards[resource] << " " << resourceToString(resource) << endl;
    return ResourceCards[resource] >= amount;
}

void Player::removeResource(Resource resource, int amount) {
    if (hasResource(resource, amount)) {
        ResourceCards[resource] -= amount;
    }
}

void Player::addDevelopmentCard(DevelopmentCard* card) {
    DevelopmentCards[card]++;
}

void Player::endTurn(){//need to continue
    setIsPlaying(false);
    cout << name << " has ended his turn" << endl;
}

void Player::trade(Player& p, string tradeCard, string givenCard, int amountTrade, int amountGiven){
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


void Player::buyDevelopmentCard(){ 
    if (this->hasResource(Resource::Wheat, 1) && this->hasResource(Resource::Sheep, 1) && this->hasResource(Resource::Ore, 1)) {
        this->removeResource(Resource::Wheat, 1);
        this->removeResource(Resource::Sheep, 1);
        this->removeResource(Resource::Ore, 1);
        
        //Seed random number generator
        srand(static_cast<unsigned int>(time(nullptr)));

        // Randomly select a type of development card
        int cardType = rand() % 5; // Assuming 5 types of development cards

        DevelopmentCard* newCard = nullptr;
        switch (cardType) {
            case 0:
                newCard = new KnightCard();
                cout << "got a knight" << endl;
                this->addDevelopmentCard(newCard);
                break;
            case 1:
                newCard = new VictoryPointCard();
                cout << name << "got victory point" << endl;
                points++;
                break;
            case 2:
                newCard = new RoadBuildingCard();
                cout << name << "got Road Building card" << endl;
                roadAmount += 2;
                break;
            case 3:
                newCard = new YearOfPlentyCard();
                cout << name << "got Year Of Plenty Card" << endl;
                addRandomResources();
                break;
            case 4:
                newCard = new MonopolyCard();
                playMonopolCard();
                break;
            default:
                cout << "Invalid card type." << endl;
                return;
        }
         // Add the new card to the player's collection (assuming you have a method for this)
        //this->addDevelopmentCard(newCard);
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
        points++;
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

void Player::addRandomResources() {
    //Seed random number generator
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

void Player::addParticipants(Player* newParticipants[]){
    for (size_t i = 0; i < 4; i++){
        participants[i] = newParticipants[i];
    }    
}

map<ResourceCard, int> Player::getResourceCard(){
    return ResourceCards;
}

void Player::playMonopolCard(){
    int amount = 0;
    int currentAmount = 0;
    // Randomly select a resource type
    int resourceType = rand() % 5; // Assuming 5 types of resources
    Resource randomResource = static_cast<Resource>(resourceType);
    for(size_t i = 0;i < 4;i++){
        currentAmount = 0;
        if(participants[i]->getName() != "" && participants[i]->getName() != name){
            if(participants[i]->hasResource(randomResource,1)){
                currentAmount = participants[i]->getResourceCard()[randomResource];
                amount += currentAmount;
                participants[i]->removeResource(randomResource,currentAmount);
            }
        }
    }
    addResource(randomResource,amount);
}
