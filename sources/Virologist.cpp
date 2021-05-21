#include "Virologist.hpp"
#include <iostream>
#include <algorithm>
using namespace std;
#include <list>
namespace pandemic{
    Player& Virologist::treat(City c){
        if(this->brd.getDiseaseLvl(c) == 0){
            throw "no disease";
        }else{
            if(this->cty == c){
                bool ans = this->brd.gotCure(c,this->brd);
                if(ans == true){
                    this->brd.decreaseDiseaseLevelToZero(c,this->brd);
                }else{
                    this->brd.decreaseDiseaseLevelByOne(c,this->brd);
                }
            }else{
                std::list<City> handCards = Player::getCards();
                std::list<City>::iterator it;
                it = std::find(handCards.begin(), handCards.end(), c);
                if(it != handCards.end()){
                    bool ans = this->brd.gotCure(*it,this->brd);
                    if(ans == true){
                        this->brd.decreaseDiseaseLevelToZero(c,this->brd);
                    }else{
                        this->brd.decreaseDiseaseLevelByOne(c,this->brd);
                    }
                }else{
                    throw "No such card in your hands";
                }
            }
        }
        return *this;
    }
}