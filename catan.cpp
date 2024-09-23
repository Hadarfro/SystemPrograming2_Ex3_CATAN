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
#include "catan.hpp"

// Constructor with default arguments
Catan::Catan(Player p1, Player p2, Player p3, Player p4, Board* b) {
    board = b;
    players[0] = p1;  // Initialize all players to default Player objects
    players[1] = p2;
    numPlayers = 2; // Only two players provided
    if (p3.getName() != "") {  // Check if a third player is provided
        players[2] = p3;
        numPlayers = 3;
    } 
    if (p4.getName() != "") {  // Check if a fourth player is provided
        players[3] = p4;
        numPlayers = 4;
    } 
    indexOfCurrentP = 0; // the default starting player is player number 1
}

// Method to print the current game state
void Catan::printGameState() const {
    cout << "Current player is: " << currentPlayer->getName() << "\n";
    board->printBoard();
    for (size_t i = 0; i < numPlayers; i++) {
        if (players[i].getName() != "") {
            cout << players[i].getName() << " has:" << endl;
            players[i].printResources(); // Print each player's resources
        }
    }
}

// Method to choose the starting player randomly
void Catan::ChooseStartingPlayer(){
    // Randomly choose the starting player
    srand(time(0));  // Use current time as seed for random generator
    unsigned int random = static_cast<unsigned int>(rand()) % numPlayers;
    players[random].setIsPlaying(true);
    currentPlayer = &players[random];
    indexOfCurrentP = (size_t)random;
    board->setCurrentPlayerName(currentPlayer->getName());
    cout << "The starting player is: " << players[random].getName() << endl;
}

// Method to get the game board
Board* Catan::getBoard(){
    return board;
}

// Method to print the winner if there's any
void Catan::printWinner(){
    for (size_t i = 0; i < 4; i++) {
        if (players[i].getPoints() >= 10) {
            cout << players[i].getName() << " is the winner" << endl;
            return;
        }
    }
    cout << "There is no winner" << endl;
}

// Method to check if a vertex is available
bool Catan::isVertexAvilable(int v){
    size_t u = (size_t) v;
    if (board->getVertcis()[u].owner == "") {
        return true; // Vertex is available if it has no owner
    }
    return false;
}

// Method to switch to the next player's turn
void Catan::nextPlayer(){
    if (currentPlayer->getPoints() >= 10) { // Check for a winner
        printWinner();
        return;
    }
    indexOfCurrentP = (indexOfCurrentP + 1) % numPlayers; // Move to the next player
    currentPlayer = &players[indexOfCurrentP];
    board->setCurrentPlayerName(currentPlayer->getName());
    cout << "The current player is: " << currentPlayer->getName() << endl;
}

// Method to get player index by name
size_t Catan::getPlayerByName(string name){
    for (size_t i = 0; i < numPlayers; i++) {
        if (players[i].getName() == name) {
            return i;
        }
    }
    return (size_t)-1; // Return -1 if player not found
}

// Method to roll the dice for the current player
void Catan::rollDiceOfCurrentPlayer(){
    size_t i = getPlayerByName(board->getCurrentPlayerName());
    if (i == -1) {
        throw invalid_argument("There is no player with that name");
    }
    else if (!players[i].getIsPlaying()) { // If current player is not playing
        nextPlayer(); // Move to the next player
    }
    int roll = currentPlayer->rollDice(); // Roll the dice
    if (roll == 7) { // If dice roll is 7, do nothing
        return;
    }
    // Distribute resources to players based on dice roll and settlements
    for (size_t i = 0; i < board->getVertcis().size(); i++) { // Loop through all vertices
        if (board->getVertcis()[i].owner != "") { // If there's a settlement on the vertex
            for (size_t j = 0; j < board->getVertcis()[i].adjacentTiles.size(); j++) { // Loop through adjacent tiles
                if (board->getVertcis()[i].adjacentTiles[j]->getNumber() == roll) { // If the tile has the rolled number
                    for (size_t k = 0; k < numPlayers; k++) { // Loop through players
                        if (board->getVertcis()[i].owner == players[k].getName()) { // Find the owner of the settlement
                            if(!board->getVertcis()[i].isCity){
                                players[k].addResource(board->getVertcis()[i].adjacentTiles[j]->resource, 1); // Add resource to player
                            }
                            else{
                                players[k].addResource(board->getVertcis()[i].adjacentTiles[j]->resource, 2); // Add resource to player with a city
                            }
                        }
                    }
                }
            }
        }
    }
    currentPlayer->endTurn(); // End current player's turn
    nextPlayer(); // Move to the next player's turn
}

// Method to get the current player
Player* Catan::getCurrentPlayer(){
    return currentPlayer;
}
