#ifndef BUFFSET_H_
#define BUFFSET_H_

using namespace std;

class BuffSet {
    public:
        BuffSet() {};
        ~BuffSet() {};
        BuffSet(double atk_bonus, double def_bonus, double hp_bonus,
                double counter_dmg_bonus, double normal_dmg_bonus, double skill_dmg_bonus, double all_dmg_bonus, 
                double dmg_reduction, 
                double counter_dmg_reduction, double normal_dmg_reduction, double skill_dmg_reduction) {
                    
            this->atk_bonus = atk_bonus/100;
            this->counter_dmg_bonus = counter_dmg_bonus;
            this->normal_dmg_bonus = normal_dmg_bonus;
            this->skill_dmg_bonus = skill_dmg_bonus;
            this->all_dmg_bonus = all_dmg_bonus/100;
            this->def_bonus = def_bonus/100;
            this->hp_bonus = hp_bonus/100;

            this->dmg_reduction = dmg_reduction/100;
            this->counter_dmg_reduction = counter_dmg_reduction/100;
            this->normal_dmg_reduction = normal_dmg_reduction/100;
            this->skill_dmg_reduction = skill_dmg_reduction/100;
        };

        double getAtkBonus() {return this->atk_bonus;};
        double getCounterDmgBonus() {return this->counter_dmg_bonus;}; 
        double getNormalDmgBonus() {return this->normal_dmg_bonus;};
        double getSkillDmgBonus() {return this->skill_dmg_bonus;};
        double getAllDmgBonus() {return this->all_dmg_bonus;};
        double getDefBonus() {return this->def_bonus;};
        double getHpBonus() {return this->hp_bonus;};

        double getDmgReduction() {return this->dmg_reduction;};
        double getCounterReduction() {return this->counter_dmg_reduction;};
        double getNormalReduction() {return this->normal_dmg_reduction;};
        double getSkillReduction() {return this->skill_dmg_reduction;};

    private:
        double atk_bonus;
        double counter_dmg_bonus;
        double normal_dmg_bonus;
        double skill_dmg_bonus;
        double all_dmg_bonus;
        double def_bonus;
        double hp_bonus;

        double dmg_reduction;
        double counter_dmg_reduction;
        double normal_dmg_reduction;
        double skill_dmg_reduction;
};

#endif 
