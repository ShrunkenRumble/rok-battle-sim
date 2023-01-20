#include "Buffs.h"

Buffs::Buffs(double atk_bonus, double def_bonus, double hp_bonus, double dmg_bonus) {
    this->atk_bonus = atk_bonus/100;
    this->def_bonus = def_bonus/100;
    this->hp_bonus = hp_bonus/100;
    this->dmg_bonus = dmg_bonus/100;
}

double Buffs::getAtkBonus() {return this->atk_bonus;}
double Buffs::getDefBonus() {return this->def_bonus;}
double Buffs::getHpBonus() {return this->hp_bonus;}
double Buffs::getDmgBonus() {return this->dmg_bonus;}