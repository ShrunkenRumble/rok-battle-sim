#ifndef COMMANDER_H_
#define COMMANDER_H_

#include <math.h>
#include <string.h>
#include <string>
#include <fstream>
#include "value.h"
#include "json.h"
#include "Debuffs.h"
#include "Buffs.h"
#include "Skill.h"

using namespace std;

class Commander {
    public:
        Commander() {};
        ~Commander() {};

        string getName() {return this->name;};
        double getRageReq() {return this->rage_req;};

        void loadCmdrData(string name);

    private:
        string name;
        double rage_req;
        vector<vector<Skill>> skills;
        
};

#endif 
