#ifndef DEBUFFSET_H_
#define DEBUFFSET_H_

using namespace std;

class DebuffSet {
    public:
        DebuffSet() {};
        ~DebuffSet() {};
        DebuffSet(double atk_reduction, double def_reduction, double hp_reduction, double dmg_reduction) {
            this->atk_reduction = atk_reduction/100;
            this->def_reduction = def_reduction/100;
            this->hp_reduction = hp_reduction/100;
            this->dmg_reduction = dmg_reduction/100;
        };

        double getAtkReduction() {return this->atk_reduction;};
        double getDefReduction() {return this->def_reduction;};
        double getHpReduction() {return this->hp_reduction;};
        double getDmgReduction() {return this->dmg_reduction;};

    private:
        double atk_reduction;
        double def_reduction;
        double hp_reduction;
        double dmg_reduction;
};

#endif 
