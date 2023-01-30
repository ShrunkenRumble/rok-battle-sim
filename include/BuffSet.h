#ifndef BUFFSET_H_
#define BUFFSET_H_

using namespace std;

class BuffSet {
    public:
        BuffSet() {};
        ~BuffSet() {};
        BuffSet(double atk_bonus, double def_bonus, double hp_bonus, double dmg_bonus, double dmg_reduction);
        double getAtkBonus();
        double getDefBonus();
        double getHpBonus();
        double getDmgBonus();
        double getDmgReduction();
    private:
        double atk_bonus;
        double def_bonus;
        double hp_bonus;
        double dmg_bonus;
        double dmg_reduction;
};

#endif 
