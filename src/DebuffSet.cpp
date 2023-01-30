#include "DebuffSet.h"

DebuffSet::DebuffSet(double atk_reduction, double def_reduction, double hp_reduction, double dmg_reduction) {
    this->atk_reduction = atk_reduction/100;
    this->def_reduction = def_reduction/100;
    this->hp_reduction = hp_reduction/100;
    this->dmg_reduction = dmg_reduction/100;
}

double DebuffSet::getAtkReduction() { return this->atk_reduction; }
double DebuffSet::getDefReduction() { return this->def_reduction; }
double DebuffSet::getHpReduction() { return this->hp_reduction; }
double DebuffSet::getDmgReduction() { return this->dmg_reduction; }