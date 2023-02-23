#ifndef COMMANDER_H_
#define COMMANDER_H_

#include <math.h>
#include <string.h>
#include <string>
#include <fstream>
#include <nlohmann/json.hpp>
#include "SkillComponent.h"
#include "Debuffs.h"
#include "Buffs.h"

using json = nlohmann::json;

class Commander {
    public:
        Commander() {};
        ~Commander() {};

        void loadCmdrData(string name, int skill_lvls[4]);

        string getName() {return this->name;};
        double getRageReq() {return this->rage_req;};
        double getDirectDmgFac();
        Buffs getBuffs();
        Debuffs getDebuffs();

    private:
        string name;
        double rage_req;
        vector<SkillComponent> active_skill;
        vector<SkillComponent> p1_skill;
        vector<SkillComponent> p2_skill;
        vector<SkillComponent> p3_skill;
        vector<SkillComponent> expertise_skill;
        
};

#endif 
