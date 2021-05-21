#include "GeneSplicer.hpp"
#include <iostream>
using namespace std;
#include <list>
namespace pandemic{
    Player& GeneSplicer::discover_cure(Color c){
        if(this->brd.existsCure(c,this->brd) == true) return *this;
        if(this->brd.existsSearchStation(this->cty , this->brd) == true){
            std::list<City> tmp = {};
            if(this->getBoard().existsCure(c,this->brd) == true) return *this;
            if(this->getCards().size() >= 5){
                for(int j=0;j<this->cards.size();j++){
                    auto it = std::next(this->cards.begin(),j);
                    this->cards.remove(*it);
                }
                this->brd.updateCure(c,this->brd);
            }else{
                std::cout<<"Number of cards : "<<this->cards.size()<<endl;
                throw "no enough cards";
            }
        }else{
            throw "No research station";
        }    
        return *this;
    }
}