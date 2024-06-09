#include "board.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <functional>  // for std::reference_wrapper

using namespace std;

// Board::Board() {
//     Tile tile1 = Tile(Resource::Wood, 11,{Tile(Resource::Brick, 2),Tile(Resource::Wheat, 4),Tile(Resource::Ore, 5),Tile(Resource::Sea,0)});
//     Tile tile2 = Tile(Resource::Brick, 2,{tile1,Tile(Resource::Ore, 5),Tile(Resource::Wood, 6),Tile(Resource::Sheep, 3),Tile(Resource::Sea,0)});
//     Tile tile3 = Tile(Resource::Sheep, 3,{tile2,Tile(Resource::Ore, 5),Tile(Resource::Wood, 6),Tile(Resource::Brick, 11),Tile(Resource::Sea,0)});
//     Tile tile4 = Tile(Resource::Wheat, 4,{tile1,Tile(Resource::Ore, 5),Tile(Resource::Wheat, 9),Tile(Resource::Sheep, 8)});
//     Tile tile5 = Tile(Resource::Ore, 5,{tile1,tile2,tile4,Tile(Resource::Wood, 6),Tile(Resource::Wheat, 9),Tile(Resource::Desert, 7)});
//     Tile tile6 = Tile(Resource::Wood, 6,{tile5,tile2,tile3,Tile(Resource::Brick, 11),Tile(Resource::Wood, 10),Tile(Resource::Desert, 7)});
//     Tile tile7 = Tile(Resource::Brick, 11,{tile6,tile3,Tile(Resource::Wood, 10),Tile(Resource::Wood, 10),Tile(Resource::Sea, 0)});
//     Tile tile8 = Tile(Resource::Sheep, 8,{tile4,Tile(Resource::Wheat, 9),Tile(Resource::Wheat, 3),Tile(Resource::Sea, 0)});
//     Tile tile9 = Tile(Resource::Wheat, 9,{tile4,tile5,tile8,Tile(Resource::Wheat, 3),Tile(Resource::Ore, 4),Tile(Resource::Desert, 7)});
//     Tile tile10 = Tile(Resource::Desert, 7,{tile9,tile5,tile6,Tile(Resource::Wood, 10),Tile(Resource::Wood, 5),Tile(Resource::Ore, 4)});
//     Tile tile11 = Tile(Resource::Wood, 10,{tile6,tile7,tile10,Tile(Resource::Sheep, 12),Tile(Resource::Ore, 6),Tile(Resource::Wood, 5)});
//     Tile tile12 = Tile(Resource::Sheep, 12,{tile7,tile11,Tile(Resource::Brick, 6),Tile(Resource::Sea, 0)});
//     Tile tile13 = Tile(Resource::Wheat, 3,{tile8,tile9,Tile(Resource::Ore, 4),Tile(Resource::Sheep, 8),Tile(Resource::Sea, 0)});
//     Tile tile14 = Tile(Resource::Ore, 4,{tile13,tile9,tile10,Tile(Resource::Wood, 5),Tile(Resource::Wheat, 9),Tile(Resource::Sheep, 8)});
//     Tile tile15 = Tile(Resource::Wood, 5,{tile14,tile10,tile11,Tile(Resource::Brick, 6),Tile(Resource::Brick, 10),Tile(Resource::Wheat, 9)});
//     Tile tile16 = Tile(Resource::Brick, 6,{tile15,tile11,tile12,Tile(Resource::Brick, 10),Tile(Resource::Sea, 0)});
//     Tile tile17 = Tile(Resource::Sheep, 8,{tile13,tile14,Tile(Resource::Wheat, 9),Tile(Resource::Sea, 0)});
//     Tile tile18 = Tile(Resource::Wheat, 9,{tile17,tile14,tile15,Tile(Resource::Brick, 10),Tile(Resource::Sea, 0)});
//     Tile tile19 = Tile(Resource::Brick, 10,{tile18,tile15,tile16,Tile(Resource::Sea, 0)});
        
//             // Simplified board with fixed resources and numbers
                    
//             tiles = {tile1,tile2,tile3,tile4,tile5,tile6,tile7,
//                 tile8,tile9,tile10,tile11,tile12,tile13,
//                 tile14,tile15,tile16,tile17,tile18,tile19
//             };

//             // Create vertices
//             vertices.resize(54);
//             vertices[0].addAdjacentTile({tile3});
//             vertices[1].addAdjacentTile({tile3});
//             vertices[2].addAdjacentTile({tile3,tile2});
//             vertices[3].addAdjacentTile({tile2});
//             vertices[4].addAdjacentTile({tile2,tile1});
//             vertices[5].addAdjacentTile({tile1});
//             vertices[6].addAdjacentTile({tile1});
//             vertices[7].addAdjacentTile({tile3,tile7});
//             vertices[8].addAdjacentTile({tile3,tile6,tile7});;
//             vertices[9].addAdjacentTile({tile2,tile3,tile6});
//             vertices[10].addAdjacentTile({tile2,tile5,tile6});
//             vertices[11].addAdjacentTile({tile2,tile1,tile5});
//             vertices[12].addAdjacentTile({tile1,tile4,tile5});
//             vertices[13].addAdjacentTile({tile1,tile4});
//             vertices[14].addAdjacentTile({tile4});
//             vertices[15].addAdjacentTile({tile7});
//             vertices[16].addAdjacentTile({tile12});
//             vertices[17].addAdjacentTile({tile7,tile12});
//             vertices[18].addAdjacentTile({tile7,tile11,tile12});
//             vertices[19].addAdjacentTile({tile6,tile7,tile11});
//             vertices[20].addAdjacentTile({tile6,tile10,tile11});
//             vertices[21].addAdjacentTile({tile5,tile6,tile10});
//             vertices[22].addAdjacentTile({tile5,tile9,tile10});
//             vertices[23].addAdjacentTile({tile4,tile5,tile9});
//             vertices[24].addAdjacentTile({tile4,tile8,tile9});
//             vertices[25].addAdjacentTile({tile4,tile8});
//             vertices[26].addAdjacentTile({tile8});
//             vertices[27].addAdjacentTile({tile8});
//             vertices[28].addAdjacentTile({tile8,tile13});
//             vertices[29].addAdjacentTile({tile8,tile9,tile13});
//             vertices[30].addAdjacentTile({tile9,tile13,tile14});
//             vertices[31].addAdjacentTile({tile9,tile10,tile14});
//             vertices[32].addAdjacentTile({tile10,tile14,tile15});
//             vertices[33].addAdjacentTile({tile10,tile11,tile15});
//             vertices[34].addAdjacentTile({tile11,tile15,tile16});
//             vertices[35].addAdjacentTile({tile11,tile12,tile16});
//             vertices[36].addAdjacentTile({tile12,tile16});
//             vertices[37].addAdjacentTile({tile12});
//             vertices[38].addAdjacentTile({tile16});
//             vertices[39].addAdjacentTile({tile16,tile19});
//             vertices[40].addAdjacentTile({tile15,tile16,tile19});
//             vertices[41].addAdjacentTile({tile15,tile18,tile19});
//             vertices[42].addAdjacentTile({tile14,tile15,tile18});
//             vertices[43].addAdjacentTile({tile14,tile18,tile17});
//             vertices[44].addAdjacentTile({tile13,tile14,tile17});
//             vertices[45].addAdjacentTile({tile13,tile17});
//             vertices[46].addAdjacentTile({tile13});
//             vertices[47].addAdjacentTile({tile17});
//             vertices[48].addAdjacentTile({tile17});
//             vertices[49].addAdjacentTile({tile17,tile18});
//             vertices[50].addAdjacentTile({tile18});
//             vertices[51].addAdjacentTile({tile18,tile19});
//             vertices[52].addAdjacentTile({tile19});
//             vertices[53].addAdjacentTile({tile19});

//         }
   
Board::Board() {
    // Create all tiles first
    Tile tile1 = Tile(Resource::Wood, 11, {Tile(Resource::Brick, 2),Tile(Resource::Wheat, 4),Tile(Resource::Ore, 5),Tile(Resource::Sea,0)});
    Tile tile2 = Tile(Resource::Brick, 2,{tile1,Tile(Resource::Ore, 5),Tile(Resource::Wood, 6),Tile(Resource::Sheep, 3),Tile(Resource::Sea,0)});
    Tile tile3 = Tile(Resource::Sheep, 3,{tile2,Tile(Resource::Ore, 5),Tile(Resource::Wood, 6),Tile(Resource::Brick, 11),Tile(Resource::Sea,0)});
    Tile tile4 = Tile(Resource::Wheat, 4,{tile1,Tile(Resource::Ore, 5),Tile(Resource::Wheat, 9),Tile(Resource::Sheep, 8)});
    Tile tile5 = Tile(Resource::Ore, 5,{tile1,tile2,tile4,Tile(Resource::Wood, 6),Tile(Resource::Wheat, 9),Tile(Resource::Desert, 7)});
    Tile tile6 = Tile(Resource::Wood, 6,{tile5,tile2,tile3,Tile(Resource::Brick, 11),Tile(Resource::Wood, 10),Tile(Resource::Desert, 7)});
    Tile tile7 = Tile(Resource::Brick, 11,{tile6,tile3,Tile(Resource::Wood, 10),Tile(Resource::Wood, 10),Tile(Resource::Sea, 0)});
    Tile tile8 = Tile(Resource::Sheep, 8,{tile4,Tile(Resource::Wheat, 9),Tile(Resource::Wheat, 3),Tile(Resource::Sea, 0)});
    Tile tile9 = Tile(Resource::Wheat, 9,{tile4,tile5,tile8,Tile(Resource::Wheat, 3),Tile(Resource::Ore, 4),Tile(Resource::Desert, 7)});
    Tile tile10 = Tile(Resource::Desert, 7,{tile9,tile5,tile6,Tile(Resource::Wood, 10),Tile(Resource::Wood, 5),Tile(Resource::Ore, 4)});
    Tile tile11 = Tile(Resource::Wood, 10,{tile6,tile7,tile10,Tile(Resource::Sheep, 12),Tile(Resource::Ore, 6),Tile(Resource::Wood, 5)});
    Tile tile12 = Tile(Resource::Sheep, 12,{tile7,tile11,Tile(Resource::Brick, 6),Tile(Resource::Sea, 0)});
    Tile tile13 = Tile(Resource::Wheat, 3,{tile8,tile9,Tile(Resource::Ore, 4),Tile(Resource::Sheep, 8),Tile(Resource::Sea, 0)});
    Tile tile14 = Tile(Resource::Ore, 4,{tile13,tile9,tile10,Tile(Resource::Wood, 5),Tile(Resource::Wheat, 9),Tile(Resource::Sheep, 8)});
    Tile tile15 = Tile(Resource::Wood, 5,{tile14,tile10,tile11,Tile(Resource::Brick, 6),Tile(Resource::Brick, 10),Tile(Resource::Wheat, 9)});
    Tile tile16 = Tile(Resource::Brick, 6,{tile15,tile11,tile12,Tile(Resource::Brick, 10),Tile(Resource::Sea, 0)});
    Tile tile17 = Tile(Resource::Sheep, 8,{tile13,tile14,Tile(Resource::Wheat, 9),Tile(Resource::Sea, 0)});
    Tile tile18 = Tile(Resource::Wheat, 9,{tile17,tile14,tile15,Tile(Resource::Brick, 10),Tile(Resource::Sea, 0)});
    Tile tile19 = Tile(Resource::Brick, 10,{tile18,tile15,tile16,Tile(Resource::Sea, 0)});
        
            // Simplified board with fixed resources and numbers
                    
            tiles = {tile1,tile2,tile3,tile4,tile5,tile6,tile7,
                tile8,tile9,tile10,tile11,tile12,tile13,
                tile14,tile15,tile16,tile17,tile18,tile19
            };

    // Create vertices
    vertices.resize(54);
    vertices[0].addAdjacentTile({&tile3});
    vertices[1].addAdjacentTile({&tile3});
    vertices[2].addAdjacentTile({&tile3, &tile2});
    vertices[3].addAdjacentTile({&tile2});
    vertices[4].addAdjacentTile({&tile2, &tile1});
    vertices[5].addAdjacentTile({&tile1});
    vertices[6].addAdjacentTile({&tile1});
    vertices[7].addAdjacentTile({&tile3, &tile7});
    vertices[8].addAdjacentTile({&tile3, &tile6, &tile7});
    vertices[9].addAdjacentTile({&tile2, &tile3, &tile6});
    vertices[10].addAdjacentTile({&tile2, &tile5, &tile6});
    vertices[11].addAdjacentTile({&tile2, &tile1, &tile5});
    vertices[12].addAdjacentTile({&tile1, &tile4, &tile5});
    vertices[13].addAdjacentTile({&tile1, &tile4});
    vertices[14].addAdjacentTile({&tile4});
    vertices[15].addAdjacentTile({&tile7});
    vertices[16].addAdjacentTile({&tile12});
    vertices[17].addAdjacentTile({&tile7, &tile12});
    vertices[18].addAdjacentTile({&tile7, &tile11, &tile12});
    vertices[19].addAdjacentTile({&tile6, &tile7, &tile11});
    vertices[20].addAdjacentTile({&tile6, &tile10, &tile11});
    vertices[21].addAdjacentTile({&tile5, &tile6, &tile10});
    vertices[22].addAdjacentTile({&tile5, &tile9, &tile10});
    vertices[23].addAdjacentTile({&tile4, &tile5, &tile9});
    vertices[24].addAdjacentTile({&tile4, &tile8, &tile9});
    vertices[25].addAdjacentTile({&tile4, &tile8});
    vertices[26].addAdjacentTile({&tile8});
    vertices[27].addAdjacentTile({&tile8});
    vertices[28].addAdjacentTile({&tile8, &tile13});
    vertices[29].addAdjacentTile({&tile8, &tile9, &tile13});
    vertices[30].addAdjacentTile({&tile9, &tile13, &tile14});
    vertices[31].addAdjacentTile({&tile9, &tile10, &tile14});
    vertices[32].addAdjacentTile({&tile10, &tile14, &tile15});
    vertices[33].addAdjacentTile({&tile10, &tile11, &tile15});
    vertices[34].addAdjacentTile({&tile11, &tile15, &tile16});
    vertices[35].addAdjacentTile({&tile11, &tile12, &tile16});
    vertices[36].addAdjacentTile({&tile12, &tile16});
    vertices[37].addAdjacentTile({&tile12});
    vertices[38].addAdjacentTile({&tile16});
    vertices[39].addAdjacentTile({&tile16, &tile19});
    vertices[40].addAdjacentTile({&tile15, &tile16, &tile19});
    vertices[41].addAdjacentTile({&tile15, &tile18, &tile19});
    vertices[42].addAdjacentTile({&tile14, &tile15, &tile18});
    vertices[43].addAdjacentTile({&tile14, &tile18, &tile17});
    vertices[44].addAdjacentTile({&tile13, &tile14, &tile17});
    vertices[45].addAdjacentTile({&tile13, &tile17});
    vertices[46].addAdjacentTile({&tile13});
    vertices[47].addAdjacentTile({&tile17});
    vertices[48].addAdjacentTile({&tile17});
    vertices[49].addAdjacentTile({&tile17, &tile18});
    vertices[50].addAdjacentTile({&tile18});
    vertices[51].addAdjacentTile({&tile18, &tile19});
    vertices[52].addAdjacentTile({&tile19});
    vertices[53].addAdjacentTile({&tile19});
}

Board::Board(const Board& other) {
    this->tiles = other.tiles;
    this->vertices = other.vertices;
}