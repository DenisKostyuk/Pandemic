#include "Player.hpp"
namespace pandemic{
    class Medic : public Player{
        
        public:
            Medic(Board& b , City c):Player(b,c){
                Player::setRole("Medic");
            }
            Player& treat(City c) override;
            Player& drive(City c) override;
            Player& fly_direct(City c) override;
            Player& fly_shuttle(City c) override;
            Player& fly_charter(City c) override;

    };
}