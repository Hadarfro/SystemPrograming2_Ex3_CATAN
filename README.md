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

## Board Class 

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

***
# Catan Class

## Introduction

The Catan class represents the logic for managing a game of Catan. It includes methods for initializing the game, managing player turns, rolling dice, and determining the game's state. This class integrates with other components such as the Player and Board classes to simulate the gameplay.

## catan.cpp

### Constructor
#### `Catan::Catan(Player p1, Player p2, Player p3, Player p4, Board* b)`
- Initializes the Catan game with up to four players and a game board.
- Checks the number of provided players and sets the `numPlayers` attribute accordingly.
- Sets the first player as the current player.

### Public Member Functions

#### `void Catan::printGameState() const`
- Prints the current game state including the current player, board state, and each player's resources.

#### `void Catan::ChooseStartingPlayer()`
- Randomly selects the starting player.
- Sets the selected player as the current player and updates the board.

#### `Board* Catan::getBoard()`
- Returns a pointer to the game board.

#### `void Catan::printWinner()`
- Checks if any player has reached the winning condition (10 points).
- Prints the winner's name if there is one, otherwise prints "There is no winner".

#### `bool Catan::isVertexAvilable(int v)`
- Checks if a vertex is available for building (i.e., it has no owner).

#### `void Catan::nextPlayer()`
- Switches to the next player's turn.
- Prints the name of the new current player.
- Checks if the current player has won the game (10 points).

#### `size_t Catan::getPlayerByName(string name)`
- Finds and returns the index of a player by their name.
- Returns -1 if the player is not found.

#### `void Catan::rollDiceOfCurrentPlayer()`
- Rolls the dice for the current player and distributes resources based on the roll.
- If a 7 is rolled, no resources are distributed.
- Ends the current player's turn and moves to the next player's turn.

#### `Player* Catan::getCurrentPlayer()`
- Returns a pointer to the current player.

## Player Class

### Constructor and Destructor

- `Player` Default constructor to initialize a player with default values.
- `~Player` Destructor to deallocate memory.

### Player Operations

- `getName` Returns the player's name.
- `getPoints` Returns the player's current points.
- `getIsPlaying` Checks if the player is currently playing.
- `printResources` Prints the player's resources.
- `setIsPlaying` Sets the player's playing status.
- `rollDice` Rolls the dice for the player and returns the result.
- `addResource` Adds resources to the player's inventory.
- `endTurn` Ends the player's turn.

## Board Class

### Constructor and Destructor

- `Board` Default constructor to initialize the game board.
- `~Board` Destructor to deallocate memory.

### Board Operations

- `getEdges` Returns a reference to the vector of edges.
- `printBoard` Prints the resources and numbers of each tile on the board.
- `getCurrentPlayerName` Returns the name of the current player.
- `setCurrentPlayerName` Sets the name of the current player.
- `getVertcis` Returns a vector of vertices on the board.

***
# Resource Class

## Introduction

This class provides utility functions for converting between `Resource` enum values and their corresponding string representations. The `Resource` enum represents different types of resources used in the game of Catan, and these functions facilitate the conversion needed for displaying resource names and processing resource inputs.

## resource.hpp

### Enum Class
#### `enum class Resource { Wood, Brick, Sheep, Wheat, Ore, Sea, Desert, None }`
- Enumerates the possible resources in the game of Catan:
  - `Wood`
  - `Brick`
  - `Sheep`
  - `Wheat`
  - `Ore`
  - `Sea`
  - `Desert`
  - `None`

### Inline Functions

#### `string resourceToString(Resource resource)`
- Converts a `Resource` enum value to its corresponding string representation.
- **Parameters:**
  - `Resource resource`: The resource enum value to be converted.
- **Returns:**
  - A `string` representing the name of the resource.

**Example Usage:**

Resource res = Resource::Wood;
string resStr = resourceToString(res);  // resStr will be "Wood"

***
# Card Class

## Description
The `Card` class and its derived classes represent different types of cards used in a game. The base class `Card` defines common attributes and methods, while the derived classes `ResourceCard` and `DevelopmentCard` represent specific types of cards, demonstrating inheritance in C++.

## Introduction
The Card class hierarchy demonstrates the use of inheritance in object-oriented programming. The base class `Card` defines common properties and methods shared by all types of cards, while the derived classes `ResourceCard` and `DevelopmentCard` extend this functionality with specific attributes and behaviors.

## Class Structure

### Card (Base Class)

#### Public Methods
- `virtual string getType() const = 0`: Pure virtual function to get the type of the card.
- `virtual void display() const = 0`: Pure virtual function to display the card information.
- `virtual ~Card() = default`: Virtual destructor for proper cleanup of derived classes.

### ResourceCard (Derived from Card)

#### Constructor
- `ResourceCard(Resource type)`: Initializes a resource card with a specific resource type.

#### Public Methods
- `string getType() const override`: Returns "Resource".
- `Resource getResourceType() const`: Returns the specific resource type of the card.
- `void display() const override`: Displays the resource card type.
- `bool operator<(const ResourceCard& other) const`: Compares two `ResourceCard` objects based on resource types.

### DevelopmentCard (Derived from Card)

#### Constructor
- `DevelopmentCard(string type)`: Initializes a development card with a specific type.

#### Public Methods
- `string getType() const override`: Returns "Development".
- `DevelopmentType getDevelopmentType()`: Returns the specific development card type.
- `void display() const override`: Displays the development card type.
- `bool operator<(const DevelopmentCard& other) const`: Compares two `DevelopmentCard` objects based on card types.

#### DevelopmentType (Nested Enum)
- `enum class DevelopmentType { KNIGHT, VICTORY_POINT, ROAD_BUILDING, YEAR_OF_PLENTY, MONOPOLY, UNKNOWN }`: Enumerates different types of development cards.

### Derived Development Card Classes
- `KnightCard`: Represents a Knight development card.
- `VictoryPointCard`: Represents a Victory Point development card.
- `RoadBuildingCard`: Represents a Road Building development card.
- `YearOfPlentyCard`: Represents a Year of Plenty development card.
- `MonopolyCard`: Represents a Monopoly development card.

## Inheritance
- **Base Class (`Card`)**: Defines common properties and methods.
- **Derived Classes (`ResourceCard`, `DevelopmentCard`, and their subclasses)**: Inherit from the base class and extend its functionality with specific attributes and methods.




