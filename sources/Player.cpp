#include "City.hpp"
#include "Color.hpp"
#include "Board.hpp"
#include "Player.hpp"
#include <list>
#include <algorithm>
#include <iostream>

using namespace pandemic;

    Player::Player(Board& b , City c):cards(),roleOfPlayer(),cty(c),brd(b){
        Player::setRole("Player");  
    }

    Player& Player::take_card(City c){
        std::list<City>::iterator it;
        it = std::find(this->cards.begin() , this->cards.end() , c);
        if(it == this->cards.end()){
            this->cards.push_back(c);
        }
        return *this;
    }
    Player& Player::drive(City c){
        std::string str = this->getBoard().convertCitiesToString(c);
        bool flag = this->brd.existsConnection(c , this->cty,this->brd);
        if(flag == true){
            this->cty = c;
        }else{
            throw "Illigal transportation , there is no connection to this city";
        }
        return *this;
    }
    Player& Player::fly_direct(City c){
        if(this->cty == c){
            throw "you cannot fly from this city to itself";
        }else{
            std::list<City>::iterator it;
            it = std::find(this->cards.begin(),this->cards.end() , c);
            if(it != this->cards.end()){
                this->cards.remove(c);
                this->cty = c;
                this->brd.addCard(c,this->brd);
            }else{
                throw "You dont have this card in your hands";
            }
        }
        return *this;
    }
    Player& Player::fly_charter(City c){
        std::list<City>::iterator it;
        it = std::find(this->cards.begin(),this->cards.end() , this->cty);
        if(it != this->cards.end()){
            this->cards.remove(this->cty);
            this->cty = c;
            this->brd.addCard(this->cty,this->brd);
        }else{
            throw "You dont have this card in your hands";
        }
        return *this;
    }
    Player& Player::fly_shuttle(City c){
        if(this->cty == c){
            throw "same city";
        }else{
            bool flag1 = this->brd.existsSearchStation(this->cty,this->brd );
            bool flag2 = this->brd.existsSearchStation(c , this->brd) ;
            if(flag1 == true && flag2 == true){
                this->cty = c;
            }else{
                throw "There is no Search Station";
            }
        }
        return *this;
    }
    Player& Player::build(){
        bool flag = false;
        std::list<City> currCards = {};
        currCards = this->getCards();
        std::list<City>::iterator it;
        it = std::find(currCards.begin() , currCards.end(),this->cty);
        if(it != currCards.end()){
            this->brd.buildStation(this->cty , this->brd);
            this->cards.remove(this->cty);
        }else{
            throw "You dont have that card in your hand srry";
        }
        return *this;
    }

    Player& Player::discover_cure(Color c){

        std::list<City> tmp = {};
        if(this->brd.existsCure(c,this->brd) == true) return *this;
        if(this->brd.existsSearchStation(this->cty,this->brd) == true){
            int counter = 0; // will count the number of cards with the same COLOR
            for(int i=0;i<this->cards.size();i++){
                auto it1 = std::next(this->cards.begin(),i);
                std::string s = this->brd.getColor(*it1 , this->brd);
                Color curCtyCol = this->brd.convertColor(s);
                if(curCtyCol == c){
                    counter++;
                    tmp.push_back(*it1);
                }
            }
            if(counter == 5){
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

    Player& Player::treat(City c){
        if(this->brd.getDiseaseLvl(c) == 0){
            throw "no disease";
        }else{
            bool ans = this->brd.gotCure(c , this->brd);
            if(ans == true){
                this->brd.decreaseDiseaseLevelToZero(c , this->brd);
            }else{
                this->brd.decreaseDiseaseLevelByOne(c , this->brd);
            }
        }
        return *this;
    }
    std::string Player::role(){
        return this->roleOfPlayer;
    }
    Player& Player::remove_cards(){
        Player::cards.clear();
        return *this;
    }
    void Player::setRole(std::string str){
        Player::roleOfPlayer = str;
    }
    Board& Player::getBoard(){
        return this->brd;
    }
    void Player::setCity(City c){
        this->cty = c;
    }
    City Player::getCity(){
        return this->cty;
    }
    std::list<City>& Player::getCards(){
        return this->cards;
    }
    std::list<std::string> Player::numberOfCrds(){
        std::list<std::string> ss = {};
        for(auto it = this->cards.begin();it!=this->cards.end();it++){
            std::string ir = this->brd.convertCitiesToString(*it);
            ss.push_back(ir);
        }
        return ss;
    }
    