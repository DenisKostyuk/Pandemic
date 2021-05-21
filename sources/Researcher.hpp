#pragma once
#include "Player.hpp"
namespace pandemic{
    class Researcher : public Player{

        public:
            Researcher(Board& b , City c):Player(b,c){
                Player::setRole("Researcher");
            }
            Player& discover_cure(Color c) override;

    };
}