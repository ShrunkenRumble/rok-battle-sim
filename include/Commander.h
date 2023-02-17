#ifndef COMMANDER_H_
#define COMMANDER_H_

#include <math.h>
#include <string.h>
#include <string>
#include "Debuffs.h"
#include "Buffs.h"

using namespace std;

class Commander {
    public:
        Commander() {};
        ~Commander() {};
        Commander(string name, double skillDmgFactor, Buffs buffs, Debuffs debuffs) {
            this->name = name;
            this->skill_dmg_factor = skill_dmg_factor;
            this->debuffs = debuffs;
            this->buffs = buffs;
        };

        string getName() {return this->name;};
        double getSkillDmgFac() {return this->skill_dmg_factor;};
        Debuffs getDebuffs() {return this->debuffs;};
        
    private:
        string name;
        double skill_dmg_factor;
        Debuffs debuffs;
        Buffs buffs;
};

#endif 
