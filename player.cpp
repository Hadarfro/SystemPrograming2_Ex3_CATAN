#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <ctime>
#include <cstdlib>
#include "board.hpp"
#include "player.hpp"

using namespace std;

// Game class
class Game {
public:
    Board board;
    vector<Player> players;
    int currentPlayer;

    Game(const std::vector<std::string>& playerNames) {
        for (const auto& name : playerNames) {
            players.emplace_back(name);
        }
        currentPlayer = 0;
    }

    void nextTurn() {
        currentPlayer = (currentPlayer + 1) % players.size();
    }

    void rollDice() {
        int roll = (std::rand() % 6 + 1) + (std::rand() % 6 + 1); // Rolling two six-sided dice
        std::cout << "Dice roll: " << roll << "\n";

        for (const auto& tile : board.tiles) {
            if (tile.number == roll) {
                for (auto& player : players) {
                    player.addResource(tile.resource, 1); // Simplified resource distribution
                }
            }
        }
    }

    void printGameState() const {
        std::cout << "Current player: " << players[currentPlayer].name << "\n";
        board.printBoard();
        for (const auto& player : players) {
            player.printResources();
        }
    }
};