#ifndef SKILL_H_
#define SKILL_H_

#include <string>
#include <vector>
#include "TroopType.h"

using namespace std;

class Skill {

    public:
        Skill() {};
        ~Skill() {};
        Skill(string bonus_type, TroopType troop_type, 
              double turn_duration, double turn_interval,
              vector<double> lvl_values) {
            
            this->bonus_type = bonus_type;
            this->troop_type = troop_type;
            this->turn_duration = turn_duration;
            this->turn_interval = turn_interval;
            this->lvl_values = lvl_values;
        };

    private:
        string bonus_type;
        TroopType troop_type;
        double turn_duration;
        double turn_interval;
        vector<double> lvl_values; 

};

#endif 
