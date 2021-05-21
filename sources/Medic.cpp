#include "Medic.hpp"
#include <iostream>
using namespace std;
#include <list>
#include<algorithm>

namespace pandemic{
    Player& Medic::treat(City c){
        if(this->brd.getDiseaseLvl(c) <= 0){
            throw "No diseasessss";
        }else{
            Player::getBoard().decreaseDiseaseLevelToZero(c , Player::getBoard());
            return *this;
        }
    }
    Player& Medic::drive(City c){
        if(this->cty == c){
            throw "same city";
        }else{
            std::string str2 = this->brd.convertCitiesToString(this->cty);
            std::string str = this->brd.convertCitiesToString(c);
            //bool flag3 = this->brd.existsConnection(c , this->cty,this->brd);
            bool flag = this->brd.existsConnection(c , this->cty,this->brd);
            if(flag == true){
                 this->cty = c;
                 std::string clrStr = this->brd.getColor(c , this->brd);
                 Color clr = this->brd.convertColor(clrStr);
                 bool flag2 = this->brd.existsCure(clr , Player::getBoard());
                 if(flag2 == true && this->brd.getDiseaseLvl(c) > 0){
                     this->treat(c);
                 }
             }else{
                 throw "no connection";
             }
        }
            return *this;
    }    
        
    /*HERE IS A PROBLEM NOT UPDATING THE CURR CITY*/    
    Player& Medic::fly_charter(City c){
        std::list<City>::iterator it;
        it = std::find(this->cards.begin(),this->cards.end() , this->cty);
        if(it != this->cards.end()){
            this->cards.remove(this->cty);
            this->cty = c;
            //this->brd.addCard(this->cty,this->brd);
            std::string clrStr = Player::getBoard().getColor(c , Player::getBoard());
            Color clr = Player::getBoard().convertColor(clrStr);
            bool flag = Player::getBoard().existsCure(clr , Player::getBoard());
            if(flag == true){
            Player::getBoard().decreaseDiseaseLevelToZero(c , Player::getBoard());
        }
        }else{
            throw "You dont have this card in your hands";
        }
        return *this;
    }
    Player& Medic::fly_direct(City c){
        if(this->cty == c){
            throw "same city";
        }else{
            std::list<City> crds = this->cards;
            std::list<City>::iterator it;
            it = std::find(crds.begin() , crds.end(),c);
            if(it != crds.end()){
                this->cards.remove(c);
                this->cty = c;
                std::string clrStr = this->brd.getColor(c , this->brd);
                Color clr = this->brd.convertColor(clrStr);
                bool flag = this->brd.existsCure(clr , this->brd);
                if(flag == true && this->brd.getDiseaseLvl(c) > 0){
                    this->treat(c);
                }
            }else{
                throw "no cardddddd";
            }
        }
        return *this;
    }
    Player& Medic::fly_shuttle(City c){
        if(brd.existsSearchStation(c , this->brd) == true){
            this->cty = c;
            std::string clrStr = Player::getBoard().getColor(c , Player::getBoard());
            Color clr = Player::getBoard().convertColor(clrStr);
            bool flag = Player::getBoard().existsCure(clr ,this->brd);
            if(flag == true){
                this->brd.decreaseDiseaseLevelToZero(c , Player::getBoard());
            }
        }
        return *this;
    }
}