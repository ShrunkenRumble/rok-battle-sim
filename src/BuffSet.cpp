#include "BuffSet.h"

BuffSet::BuffSet(double atk_bonus, double def_bonus, double hp_bonus, double dmg_bonus, double dmg_reduction) {
    this->atk_bonus = atk_bonus/100;
    this->def_bonus = def_bonus/100;
    this->hp_bonus = hp_bonus/100;
    this->dmg_bonus = dmg_bonus/100;
    this->dmg_reduction = dmg_reduction/100;
}

double BuffSet::getAtkBonus() {return this->atk_bonus;}
double BuffSet::getDefBonus() {return this->def_bonus;}
double BuffSet::getHpBonus() {return this->hp_bonus;}
double BuffSet::getDmgBonus() {return this->dmg_bonus;}
double BuffSet::getDmgReduction() {return this->dmg_reduction;}