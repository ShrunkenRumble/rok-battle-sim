#include "Commander.h"

Commander::Commander(string name, double skill_dmg_factor) {
    this->name = name;
    this->skill_dmg_factor = skill_dmg_factor;
}

string Commander::getName() {
    return this->name;
}

double Commander::getSkillDmgFac() {
    return this->skill_dmg_factor;
}