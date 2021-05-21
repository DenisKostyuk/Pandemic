#include "FieldDoctor.hpp"
using namespace std;

namespace pandemic{
    Player& FieldDoctor::treat(City c){
        if(this->brd.getDiseaseLvl(c) == 0){
            throw "no disease to treat";
        }
            bool flag = Player::getBoard().existsConnection(c , Player::getCity(),Player::getBoard());
            if(flag == true || this->cty == c){
                bool ans = this->brd.gotCure(c , this->brd);
                if(ans == true){
                    this->brd.decreaseDiseaseLevelToZero(c , this->brd);
                }else{
                    this->brd.decreaseDiseaseLevelByOne(c , this->brd);
                }
            }else{
                throw "no connection";
            }
        
        return *this;
    }
}

