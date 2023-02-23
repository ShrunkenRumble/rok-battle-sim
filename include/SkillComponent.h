#ifndef SKILLCOMPONENT_H_
#define SKILLCOMPONENT_H_

#include <string>
#include <vector>
#include "TroopType.h"

using namespace std;

class SkillComponent {

    public:
        SkillComponent() {};
        ~SkillComponent() {};

        string getType() {return this->type;};
        TroopType getTroopType() {return this->troop_type;};
        double getTurnDuration() {return this->turn_duration;};
        double getTurnInterval() {return this->turn_interval;};
        double getValue() {return this->value;};

        void setType(string type) {this->type = type;};
        void setTroopType(TroopType troop_type) {this->troop_type = troop_type;};
        void setTurnDuration(double turn_duration) {this->turn_duration = turn_duration;};
        void setTurnInterval(double turn_interval) {this->turn_interval = turn_interval;};
        void setValue(double value) {this->value = value;};

    private:
        string type;
        TroopType troop_type;
        double turn_duration;
        double turn_interval;
        double value; 

};

#endif 
