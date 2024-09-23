/*
 * Author: Hadar Froimowich.
 * ID: 213118458
 * Email: hadarfro12@gmail.com
 */

#pragma once
#include <iostream>
#include <vector>
#include <unordered_map>
#include <ctime>
#include <string>
#include <cstdlib>
#include <functional>  // for std::reference_wrapper
#include "resource.hpp"


using namespace std;


// Tile class
class Tile {
    public:
        Resource resource;
        int number;
        vector<Tile>* neighbors;
        vector<int> vertcies;
        Tile(Resource resource, int number = 0,vector<Tile> myneighbors = {},vector<int> myvertcies = {}) : resource(resource), number(number) {
            neighbors = &myneighbors;
            vertcies = myvertcies;
        }
        // Default constructor
        Tile() : resource(Resource::None), number(0) {}
        int getNumber() {
            return number;
        }
        Resource getResource() {
            return resource;
        }
};

// Vertex class
class Vertex {  
    public:
        string owner;
        vector<Tile*> adjacentTiles;
        bool isCity;
        inline void addAdjacentTile(vector<Tile*> tile) {
            for(size_t i = 0;i < tile.size();i++){
                adjacentTiles.push_back(tile[i]);
            }
        }
        Vertex(string o = "", vector<Tile*> adjacentTiles = {})
        : adjacentTiles(adjacentTiles), owner(o), isCity(false) {
            // owner is not initialized here
        }
};

// Edge class
class Edge {
    public:
        int vertex1;
        int vertex2;
        string owner;
        Edge(int vertex1 = -1, int vertex2 = -1,string owner = "")
            : vertex1(vertex1), vertex2(vertex2) , owner(owner) {}
    };

// Board class
class Board {
    private:
        vector<Tile> tiles;
        vector<Vertex> vertices;
        vector<Edge> edges;
        string currentPlayerName;
    public:
        Board();
        Board(const Board& other);
        void setCurrentPlayerName(const std::string& newName) {
            currentPlayerName = newName;
        }
        vector<Tile>& getTiles(){
            return tiles;
        }
        void initializeTiles() {
            size_t numTiles = 19;
            tiles.clear();
            tiles.resize(numTiles, Tile(Resource::None, 0));
        }

        vector<Vertex>& getVertcis(){
            return vertices;
        }

        vector<Edge>& getEdges();
        string getCurrentPlayerName();
        void printBoard() const; 
        //void distributeResources(int roll) const; 
};
