#ifndef MARCH_H_
#define MARCH_H_

#include <math.h>
#include <string.h>
#include <string>
#include <tuple>
#include "Troop.h"
#include "Buffs.h"
#include "Commander.h"

using namespace std;

class March {
    public:
        March() {};
        ~March() {};
        March(string name, double troop_cnt, double advantage, Troop *troop, Buffs *buffs, Commander *prim_comm, Commander *sec_comm);
        
        string getName();
        double getTroopCnt();
        double getAttack();
        double getRage();
        tuple<double, double> getSkillDmgFac();
        double getCounterAttack();
        double getDefense();

        void updateRage(double rage_chg);
        
        void updateTroopCnt(int turn, double loss);
    private:
        double troop_cnt;
        double advantage;
        string name;
        Troop *troop;
        Buffs *buffs;
        double rage;
        Commander *prim_comm;
        Commander *sec_comm;
};

#endif 
