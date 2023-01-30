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

string March::getName() { return this->name; }

double March::getTroopCnt() { return this->troop_cnt; }

double March::getCounterAttack() { return this->getAttack(); }

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
                    * (1 + this->buff_set->getDmgBonus()));
    double adj_atk = attack 
                      * this->troop_cnt 
                      * sqrt(10000 / this->troop_cnt)
                      * (2 + (this->troop_cnt/333333)); 
    return adj_atk;
}  
 
tuple<double, double> March::getSkillDmgFac() {
    tuple<double, double> skill_dmg_factors = make_tuple(this->prim_comm->getSkillDmgFac(), this->sec_comm->getSkillDmgFac());
    return skill_dmg_factors;
}

/*
rage cap 220 (debuffs are applied after rage reduced to 220 cap)
+86 rage for attack
+16 rage for counter (+16 for each additional march hit with counter)
    Unclear: Do you also get +10 rage comp if ur counter < their attack for each additional march???

If m1 attack < m2 counter
m1 +10 rage
If m1 counter < m2 attack
m1 +10 rage

Rage grows 10% faster when troops below 30%??
Rage gained from firing active skill??
Rage gained from passive skills that do dmg??
*/
void March::updateRage(double rage_chg) { this->rage += rage_chg; }

void March::updateTroopCnt(double loss) { this->troop_cnt -= loss; }

double March::applyDmgReduction(double losses) {
    return losses * (1 - this->buff_set->getDmgReduction());
}


