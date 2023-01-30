#ifndef DEBUFFSET_H_
#define DEBUFFSET_H_

using namespace std;

class DebuffSet {
    public:
        DebuffSet() {};
        ~DebuffSet() {};
        DebuffSet(double atk_reduction, double def_reduction, double hp_reduction, double dmg_reduction);
        double getAtkReduction();
        double getDefReduction();
        double getHpReduction();
        double getDmgReduction();
    private:
        double atk_reduction;
        double def_reduction;
        double hp_reduction;
        double dmg_reduction;
};

#endif 
