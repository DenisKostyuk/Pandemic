#include "City.hpp"
#include <ostream>
#include <map>
#include <list>
#include "Color.hpp"
#pragma once
using namespace std;
/**
* myMap ---> contains the City "KEY" and Color "KEY" and City value which represents all the cities and the colors
* DiseaseLevel ----> contains City "KEY" and the level of the disease "VALUE"
* discoveredCures ---> contains which color of cure is discovered
* numberOfResearchStations ---> number of stations in the map
* titalCard ---> contains the 48 cards which each card has the CITY name 
 */ 
namespace pandemic{
    class Board{
        private:
            std::map <City , std::map <Color ,  std::list<City> >> myMap; 
            std::map <City, int> DiseaseLevel;
            std::map<Color , bool> discoveredCures;//(1 -> 0 , 2 -> 1 , 3 -> 2 , 4 -> 3)
            int numberOfResearchStations;            
            std::list<City> totalCard;
            std::map <City , bool > searchStation;
        public:    
            Board():myMap() , DiseaseLevel() , discoveredCures() , numberOfResearchStations() , totalCard(),
            searchStation()
            {
                this->helperForInitGameMap();
            }
            bool is_clean();
            void remove_cures();
            int& operator[](City c) ;
            friend std::ostream& operator <<(std::ostream& os ,const Board b);
            void helperForInitGameMap();
            void  initGameMap(std::ifstream &units_file);
            City convertCities(std::string& str);
            Color convertColor(std::string& str);
            std::string convertCitiesToString(City c);
            std::string convertColorToString(Color str);
            void deleteCard(City c , Board& b);
            void addCard(City c , Board& b);
            bool existsConnection(City c ,City curr, Board& b);
            bool existsSearchStation(City c , Board& b);
            void buildStation(City c , Board& b);
            bool checkColorOfCity(City c , Board& b , Color clr);
            void updateCure(Color c , Board& b);
            bool existsCure(Color c , Board& b);
            void decreaseDiseaseLevelByOne(City c , Board& b);
            void decreaseDiseaseLevelToZero(City c , Board& b);
            bool gotCure(City c , Board& b);
            std::string getColor(City c , Board& b);
            int getDiseaseLvl(City c);
            void setSearchStation(City c);

    };
}