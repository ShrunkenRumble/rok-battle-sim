#include "Troop.h"

Troop::Troop(double base_atk, double base_def, double base_hp, TroopType type) {
    this->base_atk = base_atk;
    this->base_def = base_def;
    this->base_hp = base_hp;
    this->type = type;
}

double Troop::getAtk() { return this->base_atk; }
double Troop::getDef() { return this->base_def; }
double Troop::getHp() { return this->base_hp; }
TroopType Troop::getType() { return this->type; }