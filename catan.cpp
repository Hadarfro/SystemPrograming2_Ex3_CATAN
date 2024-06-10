#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <ctime>
#include <cstdlib>
#include <cstring>
#include "catan.hpp"


// Constructor with default arguments
Catan::Catan(Player p1,Player p2,Player p3,Player p4,Board* b,size_t indexOfCurrentP) {
    board = b;
    players[0] = p1;  // Initialize all players to default Player objects
    players[1] = p2;
    //players[2] = p;
    if (p3.getName() != "") {  // Check if a fourth player is provided
        players[2] = p3;
        numPlayers = 3;
    } 
    else if (p4.getName() != "") {  // Check if a third player is provided
        players[3] = p4;
        numPlayers = 4;
    } 
    else {  // Only two players provided
        numPlayers = 2;
    }
}

void Catan::printGameState() const {
    cout << "Current player is: " << currentPlayer->getName() << "\n";
    board->printBoard();
    for (const auto& player : players) {
        if(player.getName()!= ""){
            player.printResources();
        }
    }
}

void Catan::ChooseStartingPlayer(){
    // Generate a random number between 1 and 3
    size_t i = (size_t)rand() % 3 + 1;
    currentPlayer = &players[i];
    indexOfCurrentP = i;
    cout << "the starting player is: " << players[i].getName() << endl;
}

Board* Catan::getBoard(){
    return board;
}

void Catan::printWinner(){
    for(size_t i = 0;i < 4;i++){
        if(players[i].getPoints() >= 10){
            cout << players[i].getName() << endl;;
        }
    }
    cout << "there is no winner" << endl;
}

bool Catan::isVertexAvilable(int v){
    size_t u = (size_t) v;
    if(board->getVertcis()[u].owner == ""){
        return true;
    }
    return false;
}

void Catan::takeCards(){
    int roll = currentPlayer->rollDice();
    for (size_t i = 0; i < board->getVertcis().size();i++) { //goning over all the vertices
        if (board->getVertcis()[i].owner != "") { //if theres a player on the vertex
            for (size_t j = 0;j < board->getVertcis()[i].adjacentTiles.size();j++) { //goning over all tiles of the current vertex
                if(board->getVertcis()[i].adjacentTiles[j]->getNumber() == roll){ //if the player have a setlment on a tile with the number of the roll dice
                    for(size_t k = 0;k < 4;k++){
                        if(board->getVertcis()[i].owner == players[k].getName()){ // find the player the vertex belong to
                            players[k].addResource(board->getVertcis()[i].adjacentTiles[j]->resource, 1); // add to the player resource card
                        }
                    }
                }
            }
        }
    }
}
