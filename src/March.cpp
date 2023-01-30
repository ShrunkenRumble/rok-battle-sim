#include "March.h"

March::March(string name, double troop_cnt, double advantage, Troop *troop, Buffs *buffs, Commander *prim_comm, Commander *sec_comm) {
    this->name = name;
    this->troop_cnt = troop_cnt;
    this->advantage = advantage;
    this->troop = troop;
    this->buffs = buffs;
    this->prim_comm = prim_comm;
    this->sec_comm = sec_comm;
    this->rage = 0;
}

string March::getName() {
    return this->name;
}

double March::getTroopCnt() {
    return this->troop_cnt;
}

double March::getAttack() {
    double attack = (this->troop_cnt
                    * this->troop->getAtk()
                    * (1 + this->buffs->getAtkBonus())
                    * (1 + this->buffs->getDmgBonus())
                    * sqrt(1 / this->troop_cnt)
                    * (2 + (this->troop_cnt/333333)));
    return attack;
}  
 
double March::getCounterAttack() {
    return this->getAttack();
}

double March::getRage() {
    return this->rage;
}

double March::getDefense() {
    double defense = (this->troop->getDef()
                     * this->troop->getHp()
                     * (1 + this->buffs->getDefBonus())
                     * (1 + this->buffs->getHpBonus()));
    return defense;
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
void March::updateRage(double rage_chg) {
    this->rage += rage_chg;
}

void March::updateTroopCnt(double loss) {
    this->troop_cnt -= loss;
}

tuple<double, double> March::getSkillDmgFac() {
    tuple<double, double> skill_dmg_factors = make_tuple(this->prim_comm->getSkillDmgFac(), this->sec_comm->getSkillDmgFac());
    return skill_dmg_factors;
}