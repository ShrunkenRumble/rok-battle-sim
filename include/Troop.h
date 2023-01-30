#ifndef TROOP_H_
#define TROOP_H_

#include <string>
#include "TroopType.h"

using namespace std;

class Troop {
    public:
        Troop() {};
        ~Troop() {};
        Troop(double base_atk, double base_def, double base_hp, TroopType type);

        double getAtk();
        double getDef();
        double getHp();
        TroopType getType();
    private:
        double base_atk;
        double base_def;
        double base_hp;
        TroopType type;
};

#endif 
