#include "March.h"

double March::applyAtkDmgReduction(double losses) {
    return losses * (1 - (this->buff_set->getDmgReduction()
                          + this->buff_set->getNormalReduction()));
}

double March::applyCntDmgReduction(double losses) {
    return losses * (1 - (this->buff_set->getDmgReduction()
                          + this->buff_set->getNormalReduction()
                          + this->buff_set->getCounterReduction()));
}

double March::applySkillDmgReduction(double losses) {
    return losses * (1 - (this->buff_set->getDmgReduction()
                          + this->buff_set->getSkillReduction()));
}

double March::getDefense() {
    double defense = (this->troop->getDef()
                     * this->troop->getHp()
                     * (1 + this->buff_set->getDefBonus())
                     * (1 + this->buff_set->getHpBonus()));
    return defense;
}

double March::getAttack() {
    double attack = (this->troop->getAtk()
                    * (1 + this->buff_set->getAtkBonus())
                    * (1 + this->buff_set->getAllDmgBonus()
                         + this->buff_set->getNormalDmgBonus()));
    double adj_atk = attack 
                      * this->troop_cnt 
                      * sqrt(EQ_CONST_1 / this->troop_cnt)
                      * (EQ_CONST_2 + (this->troop_cnt/EQ_CONST_3)); 
    return adj_atk;
}  

double March::getCounterAttack() { 
    double counter_attack = (this->troop->getAtk()
                            * (1 + this->buff_set->getAtkBonus())
                            * (1 + this->buff_set->getAllDmgBonus()
                                 + this->buff_set->getNormalDmgBonus()
                                 + this->buff_set->getCounterDmgBonus()));
    double adj_counter_atk = counter_attack 
                      * this->troop_cnt 
                      * sqrt(EQ_CONST_1 / this->troop_cnt)
                      * (EQ_CONST_2 + (this->troop_cnt/EQ_CONST_3)); 
    return adj_counter_atk; 
}

double March::getSkillDmg() {
    double skill_dmg_factor = (this->prim_comm->getSkillDmgFac() + this->sec_comm->getSkillDmgFac()) / 200;

    double attack = (this->troop->getAtk()
                    * (1 + this->buff_set->getAtkBonus())
                    * (1 + this->buff_set->getAllDmgBonus()
                         + this->buff_set->getSkillDmgBonus())
                    * this->troop_cnt 
                    * sqrt(EQ_CONST_1 / this->troop_cnt)
                    * (EQ_CONST_2 + (this->troop_cnt/EQ_CONST_3)));
                    
    double skill_dmg = attack * skill_dmg_factor;
    return skill_dmg;
}
 


