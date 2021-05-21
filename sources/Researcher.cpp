#include "Researcher.hpp"
#include <iostream>
using namespace std;

namespace pandemic{
    Player& Researcher::discover_cure(Color c){
        std::list<City> tmp = {};
        if(this->brd.existsCure(c,this->brd) == true) return *this;
            int counter = 0; // will count the number of cards with the same COLOR
            for(int i=0;i<Player::getCards().size() ;i++){
                auto it1 = std::next(this->cards.begin(),i);
                std::string s = this->brd.getColor(*it1 , this->brd);
                Color curCtyCol = this->brd.convertColor(s);
                if(curCtyCol == c){
                    counter++;
                    tmp.push_back(*it1);
                }
            }
            if(counter >= 5){
                for(int j = 0 ; j<tmp.size();j++){
                    auto it2 = std::next(tmp.begin(),j);
                    Player::getCards().remove(*it2);
                }
                this->brd.updateCure(c , this->brd);
            }else{
                throw "you dont have enoguht cards";
            }
        return *this;
    }
}