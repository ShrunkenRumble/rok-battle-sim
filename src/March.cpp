#include "March.h"

March::March(string name, double troop_cnt, double advantage, Troop *troop, Buffs *buffs) {
    this->name = name;
    this->troop_cnt = troop_cnt;
    this->advantage = advantage;
    this->troop = troop;
    this->buffs = buffs;
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
                    * sqrt(40000/this->troop_cnt));
    return attack;
}   
double March::getCounterAttack() {
    return this->getAttack();
}

double March::getDefense() {
    double defense = (this->troop->getDef()
                     * this->troop->getHp()
                     * (1 + this->buffs->getDefBonus())
                     * (1 + this->buffs->getHpBonus()));
    return defense;
}

void March::update(int turn, double loss) {
    this->troop_cnt -= loss;
}