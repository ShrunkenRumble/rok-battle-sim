#ifndef COMMANDER_H_
#define COMMANDER_H_

#include <math.h>
#include <string.h>
#include <string>
#include "DebuffSet.h"

using namespace std;

class Commander {
    public:
        Commander() {};
        ~Commander() {};
        Commander(string name, double skillDmgFactor, DebuffSet debuff_set) {
            this->name = name;
            this->skill_dmg_factor = skill_dmg_factor;
            this->debuff_set = debuff_set;
        };

        string getName() {return this->name;};
        double getSkillDmgFac() {return this->skill_dmg_factor;};
        DebuffSet getDebuffSet() {return this->debuff_set;};
        
    private:
        string name;
        double skill_dmg_factor;
        DebuffSet debuff_set;
};

#endif 
