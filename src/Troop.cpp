#include "Troop.h"

Troop::Troop(double base_atk, double base_def, double base_hp) {
    this->base_atk = base_atk;
    this->base_def = base_def;
    this->base_hp = base_hp;
}

double Troop::getAtk() { return this->base_atk; }
double Troop::getDef() { return this->base_def; }
double Troop::getHp() { return this->base_hp; }