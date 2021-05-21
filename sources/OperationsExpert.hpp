#include "Player.hpp"
#include <list>
#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"
#pragma once
namespace pandemic{
    class OperationsExpert : public Player{
        public: 
            OperationsExpert(Board& b , City c):Player(b,c){
                Player::setRole("OperationsExpert");
            }
            Player& build() override;
    };
}