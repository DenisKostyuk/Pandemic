#include "Board.hpp"
#include <iostream>
#include "City.hpp"
#include <map>
#include <fstream>
#include "Color.hpp"
#include <algorithm>
using namespace std;
const int ZERO = 0;
const int ONE = 1;
const int TEN = 10;

//using namespace pandemic;
    pandemic::City pandemic::Board::convertCities(std::string& str){
        if(str == "Algiers"){
            return Algiers;
        } if(str == "Atlanta"){
            return Atlanta;
        } if(str == "Baghdad"){
            return Baghdad;
        } if(str == "Bangkok"){
            return Bangkok;
        } if(str == "Beijing"){
            return Beijing;
        } if(str == "Bogota"){
            return Bogota;
        } if(str == "BuenosAires"){
            return BuenosAires;
        } if(str == "Cairo"){
            return Cairo;
        } if(str == "Chennai"){
            return Chennai;
        } if(str == "Chicago"){
            return Chicago;
        } if(str == "Delhi"){
            return Delhi;
        } if(str == "Essen"){
            return Essen;
        } if(str == "HoChiMinhCity"){
            return HoChiMinhCity;
        } if(str == "HongKong"){
            return HongKong;
        } if(str == "Istanbul"){
            return Istanbul;
        } if(str == "Jakarta"){
            return Jakarta;
        } if(str == "Johannesburg"){
            return Johannesburg;
        } if(str == "Karachi"){
            return Karachi;
        } if(str == "Khartoum"){
            return Khartoum;
        } if(str == "Kinshasa"){
            return Kinshasa;
        } if(str == "Kolkata"){
            return Kolkata;
        } if(str == "Lagos"){
            return Lagos;
        } if(str == "Lima"){
            return Lima;
        } if(str == "London"){
            return London;
        } if(str == "LosAngeles"){
            return LosAngeles;
        } if(str == "Madrid"){
            return Madrid;
        } if(str == "Manila"){
            return Manila;
        } if(str == "MexicoCity"){
            return MexicoCity;
        } if(str == "Miami"){
            return Miami;
        } if(str == "Milan"){
            return Milan;
        } if(str == "Montreal"){
            return Montreal;
        } if(str == "Moscow"){
            return Moscow;
        } if(str == "Mumbai"){
            return Mumbai;
        } if(str == "NewYork"){
            return NewYork;
        } if(str == "Osaka"){
            return Osaka;
        } if(str == "Paris"){
            return Paris;
        } if(str == "Riyadh"){
            return Riyadh;
        } if(str == "SanFrancisco"){
            return SanFrancisco;
        } if(str == "Santiago"){
            return Santiago;
        } if(str == "SaoPaulo"){
            return SaoPaulo;
        } if(str == "Seoul"){
            return Seoul;
        } if(str == "Shanghai"){
            return Shanghai;
        } if(str == "StPetersburg"){
            return StPetersburg;
        } if(str == "Sydney"){
            return Sydney;
        } if(str == "Taipei"){
            return Taipei;
        } if(str == "Tehran"){
            return Tehran;
        } if(str == "Tokyo"){
            return Tokyo;
        } if(str == "Washington"){
            return Washington; 
        }
            throw "No such City";  
        
    }
    pandemic::Color pandemic::Board::convertColor(std::string& str){
        if(str == "Blue"){
            return Blue;
        } if(str == "Yellow"){
            return Yellow;
        } if(str == "Black"){
            return Black;
        } if(str == "Red"){
            return Red;
        }
            throw "No such Color";
        
    }
    std::string pandemic::Board::convertCitiesToString(City c){
        if(c == Algiers){
            return "Algiers";
        } if(c == Atlanta){
            return "Atlanta";
        } if(c == Baghdad){
            return "Baghdad";
        } if(c == Bangkok){
            return "Bangkok";
        } if(c == Beijing){
            return "Beijing";
        } if(c == Bogota){
            return "Bogota";
        } if(c == BuenosAires){
            return "BuenosAires";
        } if(c == Cairo){
            return "Cairo";
        } if(c == Chennai){
            return "Chennai";
        } if(c == Chicago){
            return "Chicago";
        } if(c == Delhi){
            return "Delhi";
        } if(c == Essen){
            return "Essen";
        } if(c == HoChiMinhCity){
            return "HoChiMinhCity";
        } if(c == HongKong){
            return "HongKong";
        } if(c == Istanbul){
            return "Istanbul";
        } if(c == Jakarta){
            return "Jakarta";
        } if(c == Johannesburg){
            return "Johannesburg";
        } if(c == Karachi){
            return "Karachi";
        } if(c == Khartoum){
            return "Khartoum";
        } if(c == Kinshasa){
            return "Kinshasa";
        } if(c == Kolkata){
            return "Kolkata";
        } if(c == Lagos){
            return "Lagos";
        } if(c == Lima){
            return "Lima";
        } if(c == London){
            return "London";
        } if(c == LosAngeles){
            return "LosAngeles";
        } if(c == Madrid){
            return "Madrid";
        } if(c == Manila){
            return "Manila";
        } if(c == MexicoCity){
            return "MexicoCity";
        } if(c == Miami){
            return "Miami";
        } if(c == Milan){
            return "Milan";
        } if(c == Montreal){
            return "Montreal";
        } if(c == Moscow){
            return "Moscow";
        } if(c == Mumbai){
            return "Mumbai";
        } if(c == NewYork){
            return "NewYork";
        } if(c == Osaka){
            return "Osaka";
        } if(c == Paris){
            return "Paris";
        } if(c == Riyadh){
            return "Riyadh";
        } if(c == SanFrancisco){
            return "SanFrancisco";
        } if(c == Santiago){
            return "Santiago";
        } if(c == SaoPaulo){
            return "SaoPaulo";
        } if(c == Seoul){
            return "Seoul";
        } if(c == Shanghai){
            return "Shanghai";
        } if(c == StPetersburg){
            return "StPetersburg";
        } if(c == Sydney){
            return "Sydney";
        } if(c == Taipei){
            return "Taipei";
        } if(c == Tehran){
            return "Tehran";
        } if(c == Tokyo){
            return "Tokyo";
        } if(c == Washington){
            return "Washington"; 
        }
            throw "No such City"; 
        
    }
    std::string pandemic::Board::convertColorToString(Color str){
        if(str == Blue){
            return "Blue";
        } if(str == Yellow){
            return "Yellow";
        } if(str == Black){
            return "Black";
        } if(str == Red){
            return "Red";
        }
        throw "No such Color";
    }
    bool pandemic::Board::is_clean(){
        bool flag = true;
        for(auto it = Board::DiseaseLevel.rbegin() ;it != Board::DiseaseLevel.rend();++it){
            if(it->second != 0){
                flag = false;
            }
        }
        return flag;
    }
    void pandemic::Board::remove_cures(){
        Board::discoveredCures[Color::Yellow] = false;
        Board::discoveredCures[Color::Red] = false;
        Board::discoveredCures[Color::Blue] = false;
        Board::discoveredCures[Color::Black] = false;
        
    }
    void pandemic::Board::updateCure(Color c , Board& b){
        b.discoveredCures[c] = true;
    }
    int& pandemic::Board::operator[](pandemic::City c){
        return this->pandemic::Board::DiseaseLevel[c];
    }
    bool pandemic::Board::existsCure(Color c , Board& b){
        if(b.discoveredCures[c] == ONE){
            return true;
        }
        return false;
    }
    ostream& pandemic::operator<< (std::ostream& os , Board b){
        for(auto it = b.myMap.begin();it!=b.myMap.end();++it){
            std::cout<<"The first key is : "<<b.convertCitiesToString(it->first)<<" ";
            for(auto itInside = it->second.begin();itInside!=it->second.end();itInside++){
                std::cout<<"The second key is : "<<b.convertColorToString(itInside->first);
                std::cout<<endl;
                list<City>::iterator iterList;
                for(iterList = itInside->second.begin();iterList != itInside->second.end();iterList++){
                     std::cout<<b.convertCitiesToString(*iterList)<<endl;
                }
                std::cout<<endl;
                // for(auto iterList = itInside->second.begin();iterList != itInside->second.end();iterList++){
                //     City c = static_cast<City>(iterList);
                // }
            }
            
        }
    return os;    
        // std::cout<<"Level of the disease : "<<endl;
        // std::cout<<"_______________________"<<endl;
        // for(auto it = b.DiseaseLevel.rbegin() ; it != b.DiseaseLevel.rend(); it++){
        //     City cty = static_cast<City>(it->first);
        //     std::string c = Board::convertCitiesToString(cty);
        //     std::cout << c << " : " <<it->second<<endl;
        // }
        // std::cout<<"The cures that already has been discovered : "<<endl;
        // std::cout<<"_____________________________________________"<<endl;
        // // for(int i = 0 ; i<4 ; i++){
        // //     //if(b.discoveredCures[i] == 1) {
        // //     if(b.discoveredCures[i] == true){    
        // //         Color clr = static_cast<Color>(i);
        // //         std::string col = Board::convertColorToString(clr);
        // //         std::cout<<col<<endl;
        // //     }
        // // }
        // for(auto it = b.discoveredCures.rbegin();it != b.discoveredCures.rend();it++){
        //     if(it->second == true){
        //         std::cout<<Board::convertColorToString(it->first)<<endl;
        //     }
        // }
        // std::cout<<"Number of researche station that has been built : "<<endl;
        // std::cout<<"__________________________________________________"<<endl;
        // std::cout<<b.numberOfResearchStations<<endl;
        // return os;
    }  
    void pandemic::Board::initGameMap(ifstream& inFile){
        string line;
        unsigned int counterOfWords = 0;
        while(!inFile.eof()){
            std::array<std::string,TEN> str = {};
            unsigned int index = 0;
            unsigned int spot = 0;
            getline(inFile , line);
            if(!line.empty()){    
                while(index < line.length()){
                    while(index < line.length() && line.at(index) != ' '){   
                        str.at(spot)+=line.at(index);
                        index++;
                    }
                    spot++;
                    index++;
                    counterOfWords++;
                }
                City mainCityName = Board::convertCities(str[0]);
                Color cityColor = Board::convertColor(str[1]);
                this->DiseaseLevel[mainCityName] = 0;
                this->totalCard.push_back(mainCityName);
                /*updating the map of discoveredCures to false*/
                this->discoveredCures[pandemic::Yellow] = false;
                this->discoveredCures[pandemic::Black] = false;
                this->discoveredCures[pandemic::Red] = false;
                this->discoveredCures[pandemic::Blue] = false;
                for(unsigned int i=2;i<counterOfWords;i++){
                    //changed here from 
                    if(str.at(i) != ""){
                        this->myMap[mainCityName][cityColor].push_back(Board::convertCities(str[i]));
                    }
                }
                counterOfWords = 0;
            } 
        }
        inFile.close();
    }
    void pandemic::Board::helperForInitGameMap(){
        ifstream infile;
        infile.open("cities_map.txt");
        initGameMap(infile);
    }
    void pandemic::Board::deleteCard(City c , Board& b){
        b.totalCard.remove(c);
    }
    void pandemic::Board::addCard(City c , Board& b){
        b.totalCard.push_back(c);
    }
    bool pandemic::Board::existsConnection(City c ,City curr ,Board& b){
        bool flag = false;
        for(auto it = b.myMap.at(curr).begin();it!= b.myMap.at(curr).end();it++){
            std::list<City>::iterator iter;
            iter = std::find(it->second.begin() , it->second.end() , c);
            if(iter != it->second.end()){
                flag = true; 
            }
        }
        return flag;
    }
    bool pandemic::Board::existsSearchStation(City c , Board& b){
        if(b.searchStation[c] == ONE){
            return true;
        }
        return false;
    }
    void pandemic::Board::buildStation(City c , Board& b){
            b.searchStation[c] = true;
    }
    bool pandemic::Board::checkColorOfCity(City c , Board& b , Color clr){
        bool flag = false;
        for(auto it = b.myMap.at(c).rbegin();it!=b.myMap.at(c).rend();++it){
            if(it->first == clr){
                flag = true;
            }
        }
        return flag;
    }
    void pandemic::Board::decreaseDiseaseLevelByOne(City c , Board& b){
        if(b.DiseaseLevel[c] > 0 ){
            b.DiseaseLevel[c]-=1;
        }
    }
    void pandemic::Board::decreaseDiseaseLevelToZero(City c , Board& b){
        b.DiseaseLevel[c] = 0;
    }
    bool pandemic::Board::gotCure(City c , Board& b){
        bool ans = false;
        for(auto it = b.myMap.at(c).rbegin();it!=b.myMap.at(c).rend();++it){
            std::string clrr = this->convertColorToString(it->first);
            ans = b.discoveredCures.at(it->first);
        
        }
        return ans;
    }
    std::string pandemic::Board::getColor(City c, Board& b){
        std::string clr = "";
        for(auto it = b.myMap.at(c).rbegin();it!=b.myMap.at(c).rend();++it){
            clr = Board::convertColorToString(it->first);
        }
        return clr;
    
    }
    int  pandemic::Board::getDiseaseLvl(City c){
        return this->DiseaseLevel[c];
    }
    void pandemic::Board::setSearchStation(City c){
        if(this->searchStation[c] != ONE){
            this->searchStation[c] = ONE;
        }
    }
    