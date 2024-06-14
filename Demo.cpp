/*
 * Author: Hadar Froimowich.
 * ID: 213118458
 * Email: hadarfro12@gmail.com
 */

#include <iostream>
#include <stdexcept>
#include <vector>
#include <cstdlib>  // For rand() and srand()
#include <ctime>    // For time()
#include "catan.hpp"
#include "player.hpp"
#include "board.hpp"


using namespace std;
//using namespace ResourceUtils;

int main(){
    srand(time(0));
    Player p1("Hadar");
    Player p2("hila");
    Player p3("shira");
    Board board;   
    Catan myCatan(p1, p2, p3,Player(),&board);
    // Starting of the game. Every player places two settlements and two roads.
    myCatan.ChooseStartingPlayer(); // should print the name of the starting player, assume it is Amit. 
    //Board& board = myCatan.getBoard(); // get the board of the game.
    board.printBoard();
    int vertex1 = 34;
    int edge1 = 15;
    p1.placeSettelemnt(vertex1, board);
    p1.placeRoad(edge1, board);
    int vertex2 = 46;
    int edge2 = 12;
    p1.placeSettelemnt(vertex2, board);
    p1.placeRoad(edge2, board); // p1 chooses Forest, hills, Agricultural Land, Desert with numbers 5, 6, 3, 4.

    int vertex3 = 31;
    int edge3 = 22;
    p2.placeSettelemnt(vertex3, board);
    p2.placeRoad(edge3, board);
    try
    {
        p3.placeSettelemnt(edge3, board); // p3 tries to place a settlement in the same location as p2.
    }
    catch (const exception &e)
    {
        cout << e.what() << endl;
    }
    int vertex4 = 50;
    int edge4 = 42;
    p2.placeSettelemnt(vertex4, board);
    p2.placeRoad(edge4, board); // p2 chooses Mountains, Pasture Land, and Forest with numbers 4, 9, 5.

    int vertex5 = 5;
    int edge5 = 37;
    p3.placeSettelemnt(vertex5, board);
    p3.placeRoad(edge5, board);
   int vertex6 = 39;
    int edge6 = 22;
    p3.placeSettelemnt(vertex6, board);
    p3.placeRoad(edge6, board); // p3 chooses Mountains, Pasture Land, Agricultural Land, Pasture Land with numbers 3, 8, 3, 9.

    // p1 has wood,bricks, and wheat, p2 has wood, ore, and wool, p3 has ore, wool, wheat.
    //p1.rollDice();// Lets say it's print 4. Then, p2 gets ore from the mountations.
    myCatan.rollDiceOfCurrentPlayer();
    p1.placeRoad(23, board); // p1 continues to build a road.
    p1.addResource(Resource::Wood,1);
    p1.addResource(Resource::Brick,1);
    p1.addResource(Resource::Wheat,1);
    p1.addResource(Resource::Sheep,1);
    p1.addResource(Resource::Ore,1);
    p1.buyDevelopmentCard();
    p1.buyRoad();
    //myCatan.nextPlayer();
    p1.endTurn(); // p1 ends his turn.

    //p2.rollDice(); // Lets say it's print 9. Then, p3 gets wool from the Pasture Land, p2 gets wool from the Pasture Land.
    myCatan.rollDiceOfCurrentPlayer();
    //myCatan.nextPlayer();
    p2.endTurn();  // p2 ends his turn.

    //p3.rollDice(); // Lets say it's print 3. Then, p3 gets wheat from the Agricultural Land and Ore from the Mountains, p1 gets wheat from the Agricultural Land.
    myCatan.rollDiceOfCurrentPlayer();
    //myCatan.nextPlayer();
    p3.endTurn();  // p3 ends his turn.

    try
    {
        p2.rollDice(); // p2 tries to roll the dice again, but it's not his turn.
    }
    catch (const std::exception &e)
    {
        cout << e.what() << endl;
    }

    //p1.rollDice();                       // Lets say it's print 6. Then, p1 gets bricks from the hills.
    myCatan.rollDiceOfCurrentPlayer();
    p1.addResource(Resource::Wood,1);
    p2.addResource(Resource::Brick,1);
    p1.trade(p2, "Wood", "Brick", 1, 1); // p1 trades 1 wood for 1 brick with p2.
    p1.endTurn();                        // p1 ends his turn.
    //myCatan.nextPlayer();

    //p2.rollDice();           // Lets say it's print 9. Then, p3 gets wool from the Pasture Land, p2 gets wool from the Pasture Land.
    myCatan.rollDiceOfCurrentPlayer();
    p2.buyDevelopmentCard(); // p2 buys a development card. Lets say it is a bonus points card.
    //myCatan.nextPlayer();
    p2.endTurn();            // p2 ends his turn.

    p1.printPoints(); // p1 has 2 points because it has two settelments.
    p2.printPoints(); // p2 has 3 points because it has two settelments and a bonus points card.
    p3.printPoints(); // p3 has 2 points because it has two settelments.

    myCatan.printWinner(); // Should print None because no player reached 10 points.
    myCatan.printGameState();

}