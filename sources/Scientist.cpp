#include "Scientist.hpp"
#include <iostream>
#include <list>
using namespace std;

namespace pandemic{
    Player& Scientist::discover_cure(Color c){
        return Scientist::discover_cure_helper(c , this->numberOfCards);
    }
    Player& Scientist::discover_cure_helper(Color c , int numberOfCards){
        if(this->getBoard().existsCure(c,this->getBoard()) == true) return *this;
        std::list<City> tmp = {};
        if(this->getBoard().existsSearchStation(this->cty , this->brd)==true){
            std::list<City> pCards = this->cards;
            int counter = 0;
            for(int i=0;i<pCards.size() && counter != this->numberOfCards ;i++){
                auto it1 = std::next(this->cards.begin(),i);
                std::string s = this->brd.getColor(*it1 , this->brd);
                Color curCtyCol = this->brd.convertColor(s);
                if(curCtyCol == c){
                    counter++;
                    tmp.push_back(*it1);
                }
            }
            if(counter == this->numberOfCards){
                
                for(int j = 0 ; j<tmp.size();j++){
                    auto it2 = std::next(tmp.begin(),j);
                    this->cards.remove(*it2);
                }
                this->brd.updateCure(c , this->brd);
            }else{
                throw "no enought cards";
            }
        }else{
            throw "No researche station";
        }
        return *this;
    }
    int Scientist::getNOC(){
        return this->numberOfCards;
    }
}