#ifndef COMMANDER_H_
#define COMMANDER_H_

#include <math.h>
#include <string.h>
#include <string>

using namespace std;

class Commander {
    public:
        Commander() {};
        ~Commander() {};
        Commander(string name, double skillDmgFactor);

        string getName();
        double getSkillDmgFac();
    private:
        string name;
        double skill_dmg_factor;
};

#endif 
