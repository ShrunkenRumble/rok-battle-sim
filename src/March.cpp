#include "March.h"

March::March(string name, double troop_cnt, double advantage, Troop *troop, BuffSet *buff_set, DebuffSet *debuff_set, Commander *prim_comm, Commander *sec_comm) {
    this->name = name;
    this->troop_cnt = troop_cnt;
    this->advantage = advantage;
    this->troop = troop;
    this->buff_set = buff_set;
    this->prim_comm = prim_comm;
    this->sec_comm = sec_comm;
    this->rage = 0;
}

void March::updateRage(double rage_chg) { this->rage += rage_chg; }
void March::updateTroopCnt(double loss) { this->troop_cnt -= loss; }
double March::applyDmgReduction(double losses) { return losses * (1 - this->buff_set->getDmgReduction()); }

string March::getName() { return this->name; }
double March::getTroopCnt() { return this->troop_cnt; }
double March::getRage() { return this->rage; }
TroopType March::getTroopType() { return this->troop->getType(); } 

double March::getDefense() {
    double defense = (this->troop->getDef()
                     * this->troop->getHp()
                     * (1 + this->buff_set->getDefBonus())
                     * (1 + this->buff_set->getHpBonus()));
    return defense;
}

double March::getAttack() {
    double attack = (this->troop->getAtk()
                    * (1 + this->buff_set->getAtkBonus())
                    * (1 + this->buff_set->getDmgBonus()
                         + this->buff_set->getNormalDmgBonus()));
    double adj_atk = attack 
                      * this->troop_cnt 
                      * sqrt(10000 / this->troop_cnt)
                      * (2 + (this->troop_cnt/333333)); 
    return adj_atk;
}  

double March::getCounterAttack() { 
    double counter_attack = (this->troop->getAtk()
                            * (1 + this->buff_set->getAtkBonus())
                            * (1 + this->buff_set->getDmgBonus()
                                 + this->buff_set->getNormalDmgBonus()
                                 + this->buff_set->getCounterDmgBonus()));
    double adj_counter_atk = counter_attack 
                      * this->troop_cnt 
                      * sqrt(10000 / this->troop_cnt)
                      * (2 + (this->troop_cnt/333333)); 

    return adj_counter_atk; 
}

double March::getSkillDmg() {
    double prim_skill_dmg_fac = (this->prim_comm->getSkillDmgFac() / 200);
    double sec_skill_dmg_fac = (this->sec_comm->getSkillDmgFac() / 200);

    double attack = (this->troop->getAtk()
                    * (1 + this->buff_set->getAtkBonus())
                    * (1 + this->buff_set->getDmgBonus())
                    * this->troop_cnt 
                    * sqrt(10000 / this->troop_cnt)
                    * (2 + (this->troop_cnt/333333)));
                    
    double skill_dmg = (attack * prim_skill_dmg_fac) + (attack * sec_skill_dmg_fac);
    return skill_dmg;
}
 


