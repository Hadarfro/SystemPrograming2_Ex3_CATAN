#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <ctime>
#include <cstdlib>
#include "board.hpp"
#include "player.hpp"
#include "catan.hpp"

using namespace std;
        Board Player::getBoard(){
            return board;
        }
        const string Player::getName() const{
            return name;
        }
        void Player::placeSettelemnt(vector<string> places,vector<int> placesNum,Board board){
            
        }

        void Player::placeRoad(vector<string> places,vector<int> placesNum,Board board){

        }

        void Player::endTurn(){

        }

        void Player::trade(Player p, string tradeCard, string givenCard, int amountTrade, int amountGiven){

        }

        void Player::buyDevelopmentCard(){

        }

        void Player::printPoints(){

        }
