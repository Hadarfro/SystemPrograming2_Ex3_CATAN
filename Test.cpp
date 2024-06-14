#include "doctest.h"
#include "player.hpp"
#include "board.hpp"
#include "catan.hpp"


/*
 * Author: Hadar Froimowich.
 * ID: 213118458
 * Email: hadarfro12@gmail.com
 */

using namespace std;
using namespace doctest;

TEST_CASE("Test Player Actions"){
    Player testPlayer("Test Player");

    // Test 1: Place Settlement and Road
    SUBCASE("Place Settlement and Road"){
        Board board; // Create a new board
        int vertex = 10; // Assume valid vertex number
        int edge = 5; // Assume valid edge number

        testPlayer.placeSettelemnt(vertex, board);
        testPlayer.placeRoad(edge, board);

        CHECK(board.getVertcis()[10].owner == testPlayer.getName());
        CHECK(board.getEdges()[5].owner == testPlayer.getName());
    }

    // Test 2: Trade Resources
    SUBCASE("Trade Resources"){
        Player trader1("Trader 1");
        Player trader2("Trader 2");

        trader1.addResource(Resource::Wood, 3);
        trader1.addResource(Resource::Brick, 2);
        trader2.addResource(Resource::Sheep, 2);
        trader2.addResource(Resource::Wheat, 3);

        trader1.trade(trader2, "Wood", "Sheep", 2, 2);

        CHECK(trader1.hasResource(Resource::Wood, 1));
        CHECK(trader1.hasResource(Resource::Sheep, 4) == false);
        CHECK(trader2.hasResource(Resource::Wood, 2));
    }

    // Add more test cases for other player actions...
}

TEST_CASE("Test Game Logic"){
    // Initialize players and board
    Player p1("Hadar");
    Player p2("hila");
    Player p3("shira");
    Board board;
    Catan myCatan(p1, p2, p3, Player(), &board);
    
    myCatan.ChooseStartingPlayer();
    CHECK(myCatan.getCurrentPlayer()->getName() == "Hadar");
    myCatan.rollDiceOfCurrentPlayer();
    myCatan.rollDiceOfCurrentPlayer();
    CHECK(myCatan.getCurrentPlayer()->getName() == "hila");
    
}

// Test cases for board functions...
TEST_CASE("Test Board Functions"){
    Board testBoard;

    // Test invalid vertex access
    SUBCASE("Invalid Vertex Access") {
        int invalidVertexIndex = -1;
        if (invalidVertexIndex < 0) {
            CHECK_THROWS_AS(testBoard.getVertcis().at(static_cast<size_t>(invalidVertexIndex)), std::out_of_range);
        }
    }

    // Test invalid edge access
    SUBCASE("Invalid Edge Access") {
        int invalidEdgeIndex = -1;
        if (invalidEdgeIndex < 0) {
            CHECK_THROWS_AS(testBoard.getEdges().at(static_cast<size_t>(invalidEdgeIndex)), std::out_of_range);
        }
    }

    
}

// Test cases for winning conditions...
TEST_CASE("Test Winning Conditions"){
    Player p1("Player1");
    Player p2("Player2");
    Player p3("Player3");
    Player p4("Player4");
    Board board;
    Catan game(p1, p2, p3, p4, &board);

    // Simulate extreme resource accumulation for winning
    SUBCASE("Extreme Resource Accumulation") {
        for (int i = 0; i < 100; ++i) {
            p1.addResource(Resource::Brick, 1);
            p1.addResource(Resource::Wood, 1);
            p1.addResource(Resource::Sheep, 1);
            p1.addResource(Resource::Wheat, 1);
        }

        CHECK(p1.hasResource(Resource::Brick, 100));
        CHECK(p1.hasResource(Resource::Wood, 100));
        CHECK(p1.hasResource(Resource::Sheep, 100));
        CHECK(p1.hasResource(Resource::Wheat, 100));
    }

    // Test player winning with extreme points
    SUBCASE("Winning with Extreme Points") {
        // p1.addPoints(20);
        // CHECK(p1.getPoints() == 20);
        // CHECK(game.checkWinningConditions() == true);
    }
    
}

TEST_CASE("Test Player Turn and Game Flow"){
    Player p1("Player 1");
    Player p2("Player 2");
    Player p3("Player 3");
    Board board;
    Catan game(p1, p2, p3, Player(), &board);

    // Test 1: Check the starting player
    SUBCASE("Starting Player"){
        game.ChooseStartingPlayer();
        CHECK(game.getCurrentPlayer()->getName() == "Player 1");
    }

    // Test 2: Rotate turns and perform actions
    SUBCASE("Player Turns and Actions"){
        // Assume starting player is Player 1
        game.getCurrentPlayer()->addResource(Resource::Wood, 3);
        game.getCurrentPlayer()->addResource(Resource::Brick, 2);

        // Player 1 places a settlement and road
        game.getCurrentPlayer()->placeSettelemnt(5, board);
        game.getCurrentPlayer()->placeRoad(7, board);

        // Rotate to next player
        game.nextPlayer();

        // Assume Player 2 has resources to buy a development card
        game.getCurrentPlayer()->addResource(Resource::Wheat, 1);
        game.getCurrentPlayer()->addResource(Resource::Sheep, 1);
        game.getCurrentPlayer()->addResource(Resource::Ore, 1);
        game.getCurrentPlayer()->buyDevelopmentCard();

        // Rotate to next player
        game.nextPlayer();

        // Assume Player 3 has resources to buy a settlement
        game.getCurrentPlayer()->addResource(Resource::Wood, 1);
        game.getCurrentPlayer()->addResource(Resource::Brick, 1);
        game.getCurrentPlayer()->addResource(Resource::Sheep, 1);
        game.getCurrentPlayer()->addResource(Resource::Wheat, 1);
        game.getCurrentPlayer()->buySettelemnt();

        // Rotate back to Player 1
        game.nextPlayer();
        game.nextPlayer();

        // Assume Player 1 has resources to trade with Player 2
        game.getCurrentPlayer()->addResource(Resource::Wood, 2);
        game.getCurrentPlayer()->addResource(Resource::Wheat, 1);
        game.getCurrentPlayer()->trade(p2, "Wood", "Wheat", 2, 1);

        // Rotate to next player
        game.nextPlayer();

        // Test ending a turn
        game.getCurrentPlayer()->endTurn();
        CHECK(game.getCurrentPlayer()->getIsPlaying() == false);
    }


    // Test multiple consecutive turns without rotation
    SUBCASE("Consecutive Turns Without Rotation") {
        for (int i = 0; i < 10; ++i) {
            game.getCurrentPlayer()->addResource(Resource::Wood, 1);
            game.getCurrentPlayer()->addResource(Resource::Brick, 1);
        }

        CHECK(game.getCurrentPlayer()->hasResource(Resource::Wood, 10));
        CHECK(game.getCurrentPlayer()->hasResource(Resource::Brick, 10));
    }

    // Test rapid turn rotation
    SUBCASE("Rapid Turn Rotation") {
        for (int i = 0; i < 100; ++i) {
            game.nextPlayer();
        }

        CHECK(game.getCurrentPlayer()->getName() == "Player 2");
    }

}


// Test Player Resource Management
TEST_CASE("PlayerTest, ResourceManagement") {
    Player player("TestPlayer");
    player.addResource(Resource::Brick, 3);
    player.addResource(Resource::Wood, 2);

    CHECK(player.hasResource(Resource::Brick, 3));
    CHECK(player.hasResource(Resource::Wood, 2));

    player.removeResource(Resource::Brick, 2);
    CHECK(player.hasResource(Resource::Brick, 1));

    // Test adding and removing non-existing resources
    //CHECK(player.removeResource(Resource::Ore, 1), out_of_range);
}

// Test Buying Settlements and Roads
TEST_CASE("PlayerTest, BuyingSettlementsAndRoads") {
    Player player("TestPlayer");
    Player p2("Player 2");
    Player p3("Player 3");
    Board board;
    Catan game(player, p2, p3, Player(), &board);
    player.addResource(Resource::Brick,3);
    player.addResource(Resource::Sheep,2);
    player.addResource(Resource::Wheat,2);
    player.addResource(Resource::Wood,3);
    player.buySettelemnt();
    player.buySettelemnt();
    player.buyRoad();

    CHECK(player.getSettlementAmount() == 4);//at first starting with 2 settlments
    CHECK(player.getRoadAmount() == 3);
    CHECK(player.getPoints() == 4);
}

// Test Gameplay
TEST_CASE("PlayerTest, Gameplay") {
    Player player("TestPlayer");
    Board board;
    player.placeSettelemnt(1, board);
    player.placeRoad(2, board);
    // Add more gameplay tests...
}

// Test Turn Management
TEST_CASE("PlayerTest, TurnManagement") {
    Player player("TestPlayer");
    player.endTurn();

    CHECK(!player.getIsPlaying());
}

// Test Starting Player
TEST_CASE("CatanTest, StartingPlayer") {
    Player p1("Player1"), p2("Player2"), p3("Player3"), p4("Player4");
    Board board;
    Catan game(p1, p2, p3, p4, &board);

    game.ChooseStartingPlayer();

    // Add assertions to check if the starting player is chosen correctly
}

// Test Roll Dice
TEST_CASE("CatanTest, RollDice") {
    Player p1("Player1"), p2("Player2"), p3("Player3"), p4("Player4");
    Board board;
    Catan game(p1, p2, p3, p4, &board);

    // Test rolling the dice for each player and check if the result is valid
}

// Test Next Player
TEST_CASE("CatanTest, NextPlayer") {
    Player p1("Player1"), p2("Player2"), p3("Player3"), p4("Player4");
    Board board;
    Catan game(p1, p2, p3, p4, &board);

    game.nextPlayer();
    CHECK(game.getCurrentPlayer()->getName() == "Player2");
    // Add more assertions...
}

// Test Vertex Availability
TEST_CASE("CatanTest, VertexAvailability") {
    Player p1("Player1"), p2("Player2"), p3("Player3"), p4("Player4");
    Board board;
    Catan game(p1, p2, p3, p4, &board);

    // Test vertex availability for different cases
}

// Test Print Winner
TEST_CASE("CatanTest, PrintWinner") {
    Player p1("Player1"), p2("Player2"), p3("Player3"), p4("Player4");
    Board board;
    Catan game(p1, p2, p3, p4, &board);

    // Simulate game end and check if the winner is printed correctly
}

// Test Get Player by Name
TEST_CASE("CatanTest, GetPlayerByName") {
    Player p1("Player1"), p2("Player2"), p3("Player3"), p4("Player4");
    Board board;
    Catan game(p1, p2, p3, p4, &board);

    CHECK(game.getPlayerByName("Player1") == 0);
}

