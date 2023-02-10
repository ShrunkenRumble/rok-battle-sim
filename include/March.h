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

// Constants found in combat equation
#define EQ_CONST_1 10000
#define EQ_CONST_2 2
#define EQ_CONST_3 333333

using namespace std;

class March {
    public:
        March() {};
        ~March() {};
        March(string name, double troop_cnt, double advantage, Troop *troop, BuffSet *buff_set, 
              Commander *prim_comm, Commander *sec_comm) {
            this->name = name; 
            this->troop = troop;
            this->buff_set = buff_set; 
            this->troop_cnt = troop_cnt; 
            this->advantage = advantage; 
            this->prim_comm = prim_comm; 
            this->sec_comm = sec_comm; 
            this->rage = 0;
        };
        
        string getName() {return this->name;};
        double getRage() {return this->rage;};
        double getTroopCnt() {return this->troop_cnt;};
        TroopType getTroopType() {return this->troop->getType();};

        void addRage(double rage_chg) {this->rage += rage_chg;};
        void applyLoss(double loss) {this->troop_cnt -= loss;};

        double applyAtkDmgReduction(double losses);
        double applyCntDmgReduction(double losses);
        double applySkillDmgReduction(double losses);

        double getAttack();
        double getSkillDmg();
        double getCounterAttack();
        double getDefense();
    
    private:
        double troop_cnt;
        double advantage;
        double rage;
        string name;
        Troop *troop;
        BuffSet *buff_set;
        Commander *prim_comm;
        Commander *sec_comm;
};

#endif 
