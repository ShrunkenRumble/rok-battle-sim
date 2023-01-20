#ifndef BUFFS_H_
#define BUFFS_H_

using namespace std;

class Buffs {
    public:
        Buffs() {};
        ~Buffs() {};
        Buffs(double atk_bonus, double def_bonus, double hp_bonus, double dmg_bonus);
        double getAtkBonus();
        double getDefBonus();
        double getHpBonus();
        double getDmgBonus();
    private:
        double atk_bonus;
        double def_bonus;
        double hp_bonus;
        double dmg_bonus;
};

#endif 
