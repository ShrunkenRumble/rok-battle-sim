#ifndef BUFFS_H_
#define BUFFS_H_

#include <map>
#include <string>

using namespace std;

class Buffs {
    public:
        ~Buffs() {};
        Buffs(double atk_bonus = 0, double def_bonus = 0, double hp_bonus = 0,
              double counter_dmg_bonus = 0, double normal_dmg_bonus = 0, double skill_dmg_bonus = 0, double all_dmg_bonus = 0, 
              double dmg_reduction = 0, double counter_dmg_reduction = 0, double normal_dmg_reduction = 0, double skill_dmg_reduction = 0) {
            this->atk_bonus = atk_bonus;
            this->def_bonus = def_bonus;
            this->hp_bonus = hp_bonus;
            this->counter_dmg_bonus = counter_dmg_bonus;
            this->normal_dmg_bonus = normal_dmg_bonus;
            this->skill_dmg_bonus = skill_dmg_bonus;
            this->all_dmg_bonus = all_dmg_bonus;
            this->dmg_reduction = dmg_reduction;
            this->counter_dmg_reduction = counter_dmg_reduction;
            this->normal_dmg_reduction = normal_dmg_reduction;
            this->skill_dmg_reduction = skill_dmg_reduction;
        };
        Buffs(map<string, double> buffs) {
            this->atk_bonus = buffs["atk_bonus"];
            this->def_bonus = buffs["def_bonus"];
            this->hp_bonus = buffs["hp_bonus"];
            this->counter_dmg_bonus = buffs["counter_dmg_bonus"];
            this->normal_dmg_bonus = buffs["normal_dmg_bonus"];
            this->skill_dmg_bonus = buffs["skill_dmg_bonus"];
            this->all_dmg_bonus = buffs["all_dmg_bonus"];
            this->dmg_reduction = buffs["dmg_reduction"];
            this->counter_dmg_reduction = buffs["counter_dmg_reduction"];
            this->normal_dmg_reduction = buffs["normal_dmg_reduction"];
            this->skill_dmg_reduction = buffs["skill_dmg_reduction"];
        };

        Buffs operator + (Buffs const &other) {
            return Buffs(this->atk_bonus + other.atk_bonus,
                this->def_bonus + other.def_bonus,
                this->hp_bonus + other.hp_bonus,
                this->counter_dmg_bonus + other.counter_dmg_bonus,
                this->normal_dmg_bonus + other.normal_dmg_bonus,
                this->skill_dmg_bonus + other.skill_dmg_bonus,
                this->all_dmg_bonus + other.all_dmg_bonus,
                this->dmg_reduction + other.dmg_reduction,
                this->counter_dmg_reduction + other.counter_dmg_reduction,
                this->normal_dmg_reduction + other.normal_dmg_reduction,
                this->skill_dmg_reduction + other.skill_dmg_reduction);
        };
        Buffs operator - (Buffs const &other) {
            return Buffs(this->atk_bonus - other.atk_bonus,
                this->def_bonus - other.def_bonus,
                this->hp_bonus - other.hp_bonus,
                this->counter_dmg_bonus - other.counter_dmg_bonus,
                this->normal_dmg_bonus - other.normal_dmg_bonus,
                this->skill_dmg_bonus - other.skill_dmg_bonus,
                this->all_dmg_bonus - other.all_dmg_bonus,
                this->dmg_reduction - other.dmg_reduction,
                this->counter_dmg_reduction - other.counter_dmg_reduction,
                this->normal_dmg_reduction - other.normal_dmg_reduction,
                this->skill_dmg_reduction - other.skill_dmg_reduction);
        };

        double getAtkBonus() {return this->atk_bonus;};
        double getDefBonus() {return this->def_bonus;};
        double getHpBonus() {return this->hp_bonus;};
        double getCounterDmgBonus() {return this->counter_dmg_bonus;}; 
        double getNormalDmgBonus() {return this->normal_dmg_bonus;};
        double getSkillDmgBonus() {return this->skill_dmg_bonus;};
        double getAllDmgBonus() {return this->all_dmg_bonus;};
        double getDmgReduction() {return this->dmg_reduction;};
        double getCounterReduction() {return this->counter_dmg_reduction;};
        double getNormalReduction() {return this->normal_dmg_reduction;};
        double getSkillReduction() {return this->skill_dmg_reduction;};

        void addAtkBonus(double atk_bonus) {this->atk_bonus += atk_bonus;};
        void addDefBonus(double def_bonus) {this->def_bonus += def_bonus;};
        void addHpBonus(double hp_bonus) {this->hp_bonus += hp_bonus;};
        void addCounterDmgBonus(double counter_dmg_bonus) {this->counter_dmg_bonus += counter_dmg_bonus;}; 
        void addNormalDmgBonus(double normal_dmg_bonus) {this->normal_dmg_bonus += normal_dmg_bonus;};
        void addSkillDmgBonus(double skill_dmg_bonus) {this->skill_dmg_bonus += skill_dmg_bonus;};
        void addAllDmgBonus(double all_dmg_bonus) {this->all_dmg_bonus += all_dmg_bonus;};
        void addDmgReduction(double dmg_reduction) {this->dmg_reduction += dmg_reduction;};
        void addCounterReduction(double counter_dmg_reduction) {this->counter_dmg_reduction += counter_dmg_reduction;};
        void addNormalReduction(double normal_dmg_reduction) {this->normal_dmg_reduction += normal_dmg_reduction;};
        void addSkillReduction(double skill_dmg_reduction) {this->skill_dmg_reduction += skill_dmg_reduction;};

        void subtractAtkBonus(double atk_bonus) {this->atk_bonus -= atk_bonus;};
        void subtractDefBonus(double def_bonus) {this->def_bonus -= def_bonus;};
        void subtractHpBonus(double hp_bonus) {this->hp_bonus -= hp_bonus;};
        void subtractCounterDmgBonus(double counter_dmg_bonus) {this->counter_dmg_bonus -= counter_dmg_bonus;}; 
        void subtractNormalDmgBonus(double normal_dmg_bonus) {this->normal_dmg_bonus -= normal_dmg_bonus;};
        void subtractSkillDmgBonus(double skill_dmg_bonus) {this->skill_dmg_bonus -= skill_dmg_bonus;};
        void subtractAllDmgBonus(double all_dmg_bonus) {this->all_dmg_bonus -= all_dmg_bonus;};
        void subtractDmgReduction(double dmg_reduction) {this->dmg_reduction -= dmg_reduction;};
        void subtractCounterReduction(double counter_dmg_reduction) {this->counter_dmg_reduction -= counter_dmg_reduction;};
        void subtractNormalReduction(double normal_dmg_reduction) {this->normal_dmg_reduction -= normal_dmg_reduction;};
        void subtractSkillReduction(double skill_dmg_reduction) {this->skill_dmg_reduction -= skill_dmg_reduction;};

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
