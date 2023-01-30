#ifndef MARCH_H_
#define MARCH_H_

#include <math.h>
#include <string.h>
#include <string>
#include <tuple>
#include "Troop.h"
#include "BuffSet.h"
#include "DebuffSet.h"
#include "Commander.h"
#include "TroopType.h"

using namespace std;

class March {
    public:
        March() {};
        ~March() {};
        March(string name, double troop_cnt, double advantage, Troop *troop, BuffSet *buff_set, DebuffSet *debuff_set, Commander *prim_comm, Commander *sec_comm);
        
        string getName();
        double getTroopCnt();
        double getAttack();
        double getRage();
        tuple<double, double> getSkillDmgFac();
        double getCounterAttack();
        double getDefense();
        TroopType getTroopType();

        double applyDmgReduction(double losses);
        void updateRage(double rage_chg);
        void updateTroopCnt(double loss);
    private:
        double troop_cnt;
        double advantage;
        string name;
        Troop *troop;
        BuffSet *buff_set;
        double rage;
        Commander *prim_comm;
        Commander *sec_comm;
};

#endif 
