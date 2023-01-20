#ifndef MARCH_H_
#define MARCH_H_

#include <math.h>
#include <string.h>
#include <string>
#include "Troop.h"
#include "Buffs.h"

using namespace std;

class March {
    public:
        March() {};
        ~March() {};
        March(string name, double troop_cnt, double advantage, Troop *troop, Buffs *buffs);
        
        string getName();
        double getTroopCnt();
        double getAttack();
        double getCounterAttack();
        double getDefense();
        void update(int turn, double loss);
    private:
        double troop_cnt;
        double advantage;
        string name;
        Troop *troop;
        Buffs *buffs;
};

#endif 
