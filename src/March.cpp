#include "March.h"

double March::applyAtkDmgReduction(double losses) {
    return losses * (1 - (this->buffs->getDmgReduction()
                          + this->buffs->getNormalReduction()));
}

double March::applyCntDmgReduction(double losses) {
    return losses * (1 - (this->buffs->getDmgReduction()
                          + this->buffs->getNormalReduction()
                          + this->buffs->getCounterReduction()));
}

double March::applySkillDmgReduction(double losses) {
    return losses * (1 - (this->buffs->getDmgReduction()
                          + this->buffs->getSkillReduction()));
}

double March::getDefense() {
    double defense = (this->troop->getDef()
                     * this->troop->getHp()
                     * (1 + this->buffs->getDefBonus())
                     * (1 + this->buffs->getHpBonus()));
    return defense;
}

double March::getAttack() {
    double attack = (this->troop->getAtk()
                    * (1 + this->buffs->getAtkBonus())
                    * (1 + this->buffs->getAllDmgBonus()
                         + this->buffs->getNormalDmgBonus()));
    double adj_atk = attack 
                      * this->troop_cnt 
                      * sqrt(EQ_CONST_1 / this->troop_cnt)
                      * (EQ_CONST_2 + (this->troop_cnt/EQ_CONST_3)); 
    return adj_atk;
}  

double March::getCounterAttack() { 
    double counter_attack = (this->troop->getAtk()
                            * (1 + this->buffs->getAtkBonus())
                            * (1 + this->buffs->getAllDmgBonus()
                                 + this->buffs->getNormalDmgBonus()
                                 + this->buffs->getCounterDmgBonus()));
    double adj_counter_atk = counter_attack 
                      * this->troop_cnt 
                      * sqrt(EQ_CONST_1 / this->troop_cnt)
                      * (EQ_CONST_2 + (this->troop_cnt/EQ_CONST_3)); 
    return adj_counter_atk; 
}

double March::getSkillDmg() {
    double skill_dmg_factor = (this->prim_comm->getDirectDmgFac() + this->sec_comm->getDirectDmgFac()) / 200;

    double attack = (this->troop->getAtk()
                    * (1 + this->buffs->getAtkBonus())
                    * (1 + this->buffs->getAllDmgBonus()
                         + this->buffs->getSkillDmgBonus())
                    * this->troop_cnt 
                    * sqrt(EQ_CONST_1 / this->troop_cnt)
                    * (EQ_CONST_2 + (this->troop_cnt/EQ_CONST_3)));
                    
    double skill_dmg = attack * skill_dmg_factor;
    return skill_dmg;
}
 


