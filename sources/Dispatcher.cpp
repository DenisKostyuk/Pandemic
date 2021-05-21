#include "Dispatcher.hpp"
#include <iostream>
#include "Board.hpp"
#include <algorithm>
using namespace std;

namespace pandemic{
    Dispatcher::Dispatcher(Board& b , City c):Player(b,c){
        Player::setRole("Dispatcher");
    }
    Player& Dispatcher::fly_direct(City c){
        if(this->cty == c){
            throw "you cannot flyyyyyyy";
        }else{
            bool flag2 = this->brd.existsSearchStation(this->cty,this->brd);
            if(flag2 == true){
                this->cty = c; 
            }else{
                std::list<City>::iterator it;
                it = std::find(this->cards.begin(),this->cards.end(),c);
                if(it != this->cards.end()){
                    this->cards.remove(c);
                    this->cty = c;
                    this->brd.addCard(c,this->brd);
                }else{
                    throw "You dont have this card in your hands";
                }
            }
        }
        return *this;
        //}
    }
}