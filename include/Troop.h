#ifndef TROOP_H_
#define TROOP_H_

#include <string>
#include "TroopType.h"

using namespace std;

class Troop {
    public:
        Troop() {};
        ~Troop() {};
        Troop(double base_atk, double base_def, double base_hp, TroopType type) {
            this->base_atk = base_atk;
            this->base_def = base_def;
            this->base_hp = base_hp;
            this->type = type;
        };

        double getAtk() {return this->base_atk;};
        double getDef() {return this->base_def;};
        double getHp() {return this->base_hp;};
        TroopType getType() {return this->type;};

    private:
        double base_atk;
        double base_def;
        double base_hp;
        TroopType type;
};

#endif 
