#ifndef TROOP_H_
#define TROOP_H_

using namespace std;

class Troop {
    public:
        Troop() {};
        ~Troop() {};
        Troop(double base_atk, double base_def, double base_hp);
        double getAtk();
        double getDef();
        double getHp();
    private:
        double base_atk;
        double base_def;
        double base_hp;
};

#endif 
