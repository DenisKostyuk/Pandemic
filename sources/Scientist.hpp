#pragma once
#include "Player.hpp"
namespace pandemic{
    class Scientist : public Player{
            int numberOfCards;

        public:
            Scientist(Board& b , City c , int n):Player(b,c) , numberOfCards(n){
                Player::setRole("Scientist");
            }
            Player& discover_cure(Color c) override;
            int getNOC();
            Player& discover_cure_helper(Color c , int numberOfCards);

    };
}