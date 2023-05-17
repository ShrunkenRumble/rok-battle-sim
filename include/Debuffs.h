#ifndef DEBUFFS_H_
#define DEBUFFS_H_

using namespace std;

class Debuffs {
    public:
        Debuffs() {};
        ~Debuffs() {};
        Debuffs(double atk_reduction, double def_reduction, double hp_reduction, 
                double dmg_reduction) {
            this->atk_reduction = atk_reduction;
            this->def_reduction = def_reduction;
            this->hp_reduction = hp_reduction;
            this->dmg_reduction = dmg_reduction;
        };

        Debuffs operator + (Debuffs const &other) {
            return Debuffs(this->atk_reduction + other.atk_reduction,
                           this->def_reduction + other.def_reduction,
                           this->hp_reduction + other.hp_reduction,
                           this->dmg_reduction + other.dmg_reduction);
        };
        Debuffs operator - (Debuffs const &other) {
            return Debuffs(this->atk_reduction - other.atk_reduction,
                           this->def_reduction - other.def_reduction,
                           this->hp_reduction - other.hp_reduction,
                           this->dmg_reduction - other.dmg_reduction);
        };

        double getAtkReduction() {return this->atk_reduction;};
        double getDefReduction() {return this->def_reduction;};
        double getHpReduction() {return this->hp_reduction;};
        double getDmgReduction() {return this->dmg_reduction;};

        void addAtkReduction(double atk_reduction) {this->atk_reduction += atk_reduction;};
        void addDefReduction(double def_reduction) {this->def_reduction += def_reduction;};
        void addHpReduction(double hp_reduction) {this->hp_reduction += hp_reduction;};
        void addDmgReduction(double dmg_reduction) {this->dmg_reduction += dmg_reduction;};

        void subtractAtkReduction(double atk_reduction) {this->atk_reduction -= atk_reduction;};
        void subtractDefReduction(double def_reduction) {this->def_reduction -= def_reduction;};
        void subtractHpReduction(double hp_reduction) {this->hp_reduction -= hp_reduction;};
        void subtractDmgReduction(double dmg_reduction) {this->dmg_reduction -= dmg_reduction;};

    private:
        double atk_reduction;
        double def_reduction;
        double hp_reduction;
        double dmg_reduction;
};

#endif 
