#include "Player.hpp"
#include "OperationsExpert.hpp"
#include "City.hpp"
#include "Color.hpp"
#include "Board.hpp"


namespace pandemic{

    Player& OperationsExpert::build(){
        this->getBoard().setSearchStation(this->getCity());
        return *this;
    }

};