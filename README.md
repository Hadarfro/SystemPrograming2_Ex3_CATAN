# Player Class

## Description
This C++ class represents a player in a game. It includes methods for managing resources, placing settlements and roads on the board, buying development cards, trading resources, and more.

## Author
- **Hadar Froimowich**
- **ID:** 213118458
- **Email:** hadarfro12@gmail.com

## Introduction
Welcome to my Player class! This class provides functionalities to manage players in a game scenario. From resource management to turn handling and trading, the Player class is designed to facilitate various player-related actions in a game environment.

## Class Structure

### Constructor and Destructor
- `Player(string myName)`: Initializes a player with the given name and default resources. Implementation: Initializes resource cards to 0, sets settlement and road amounts to default, and sets playing status to false.
- `~Player()`: Destructor.

### Player Operations

#### `void addResource(Resource resource, int amount)`
Adds a specified amount of a resource to the player. 
- **Implementation**: Increases the resource card count for the given resource by the specified amount.

#### `const string getName() const`
Returns the name of the player.
- **Implementation**: Returns the name attribute of the player.

#### `void setIsPlaying(bool flag)`
Sets the playing status of the player.
- **Implementation**: Sets the `isPlaying` attribute to the provided flag value.

#### `bool getIsPlaying()`
Returns true if the player is playing.
- **Implementation**: Returns the value of the `isPlaying` attribute.

#### `void addPoints(int amount)`
Adds points to the player.
- **Implementation**: Increases the points attribute by the specified amount.

#### `void placeSettelemnt(int v, Board& board)`
Places a settlement on the board.
- **Implementation**: Checks if the specified vertex is available, then sets the owner of the vertex to the player's name and decreases the settlement amount.

#### `void placeRoad(int edge, Board& board)`
Places a road on the board.
- **Implementation**: Checks if the specified edge is available, then sets the owner of the edge to the player's name and decreases the road amount.

#### `bool hasResource(Resource resource, int amount)`
Checks if the player has a certain amount of a resource.
- **Implementation**: Returns true if the player has at least the specified amount of the given resource.

#### `void removeResource(Resource resource, int amount)`
Removes a specified amount of a resource from the player.
- **Implementation**: Decreases the resource card count for the given resource by the specified amount if the player has enough resources.

#### `void addDevelopmentCard(DevelopmentCard* card)`
Adds a development card to the player.
- **Implementation**: Increases the count of the specific development card owned by the player.

#### `void endTurn()`
Ends the player's turn.
- **Implementation**: Sets the playing status of the player to false.

#### `void trade(Player& p, string tradeCard, string givenCard, int amountTrade, int amountGiven)`
Trades resources with another player.
- **Implementation**: Transfers specified resources between two players if conditions are met.

#### `void buyDevelopmentCard()`
Buys a development card.
- **Implementation**: Checks if the player has enough resources to buy a card, then randomly selects and adds a development card to the player's collection.

#### `void buySettelemnt()`
Buys a settlement.
- **Implementation**: Checks if the player has enough resources to buy a settlement, then increases settlement amount and points.

#### `void buyRoad()`
Buys a road.
- **Implementation**: Checks if the player has enough resources to buy a road, then increases road amount.

#### `void printPoints()`
Prints the player's points.
- **Implementation**: Prints the points attribute of the player.

#### `int rollDice() const`
Rolls the dice and returns the result.
- **Implementation**: Generates a random number between 2 and 12 (inclusive) and returns the result.

#### `int getPoints()`
Returns the player's points.
- **Implementation**: Returns the points attribute of the player.

#### `void addRandomResources()`
Adds random resources to the player.
- **Implementation**: Adds two random resources to the player's resource cards.

#### `void addParticipants(Player* newParticipants[])`
Adds participants to the game.
- **Implementation**: Copies the array of participants to the internal array of the Player object.

#### `map<ResourceCard, int> getResourceCard()`
Returns the player's resource cards.
- **Implementation**: Returns the map containing resource cards and their counts.

#### `void playMonopolCard()`
Plays the Monopoly card.
- **Implementation**: Randomly selects a resource type and takes that resource from other players.

### Usage Example

#include "player.hpp"
#include "board.hpp" // Assuming you have a Board class

 ***

## Class Board 

In this section, I provide an implementation of a board class representing a game board for the board of catan. The board consists tiles, vertices, and edges, forming the structure of the game environment.

## board.cpp

### Constructor
#### `Board::Board()`
- Initializes the game board by creating tiles, vertices, and edges.
- Fixed resources and numbers are assigned to tiles.
- Vertices are initialized based on the connections between tiles.

### Copy Constructor
#### `Board::Board(const Board& other)`
- Creates a copy of the Board object by copying tiles and vertices from another board.

### Public Member Functions

#### `vector<Edge>& Board::getEdges()`
- Returns a reference to the vector of edges.

#### `void Board::printBoard() const`
- Prints the resources and numbers of each tile on the board.
- Throws an exception if the number of tiles is too large.

#### `string Board::getCurrentPlayerName()`
- Returns the name of the current player.

## Private Member Functions

#### `void Board::initializeTiles()`
- Initializes the tiles with fixed resources and numbers.

#### `string Board::resourceToString(Resource res)`
- Converts a Resource enum value to a string representation.


