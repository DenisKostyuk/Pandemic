#include "City.hpp"
#pragma once
#include "Color.hpp"
#include "Board.hpp"
#include <list>
#pragma once
using namespace std;
namespace pandemic{
    class Player{
        protected:
            std::list<City> cards;
            Board& brd;
            City cty;
            std::string roleOfPlayer;
            
        public:
            Player(Board& b , City c);
            virtual Player& take_card(City c);//City::__
            virtual Player& build();
            virtual Player& drive(City c);//City::__
            virtual Player& fly_direct(City c);//City::__
            virtual Player& treat(City c);//City::__
            virtual Player& fly_charter(City c);//City::__
            virtual Player& fly_shuttle(City c);//City::__
            virtual Player& discover_cure(Color col);//Color::__
            std::string role();
            virtual Player& remove_cards();
            void setRole(std::string str);
            Board& getBoard();
            void setCity(City c);
            City getCity();
            std::list<City>& getCards();
            std::list<std::string> numberOfCrds();
            

    };
}