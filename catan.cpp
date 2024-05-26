#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <ctime>
#include <cstdlib>
#include "catan.hpp"
#include "board.hpp"
#include "player.hpp"


// Constructor with default arguments
Catan::Catan(Player p1, Player p2, Player p3 = Player(), Player p4 = Player()) {
    players[0] = Player();  // Initialize all players to default Player objects
    players[1] = p1;
    players[2] = p2;
    players[3] = p3;
    if (p4.getName() != "") {  // Check if a fourth player is provided
        players[4] = p4;
        numPlayers = 4;
    } 
    else if (p3.getName() != "") {  // Check if a third player is provided
        numPlayers = 3;
    } 
    else {  // Only two players provided
        numPlayers = 2;
    }
}

void Catan::printGameState() const {
    cout << "Current player: " << players[currentPlayer].getName() << "\n";
    board.printBoard();
    for (const auto& player : players) {
        player.printResources();
    }
}

void Catan::ChooseStartingPlayer(){
    // Generate a random number between 1 and 3
    size_t i = rand() % 3 + 1;
    cout << players[i].getName() << endl;
}

Board Catan::getBoard(){
    return board;
}

void Catan::printWinner(){

}

int Catan::rollDice(){
    int roll = (std::rand() % 6 + 1) + (std::rand() % 6 + 1); // Rolling two six-sided dice
    std::cout << "Dice roll: " << roll << "\n";

    // for (const auto& tile : board.tiles) {
    //     if (board.tiles. == roll) {
    //         for (size_t i = 0;i < 3;i++) {
    //             players[i].addResource(tile.resource,1); // Simplified resource distribution
    //         }
    //     }
    // }
    return roll;
}
