#include "Battle.h"

void applyTroopAdvantage(March march_1, March march_2, map<string, double> *turn_log) {
    if (march_1.getTroopType() != march_2.getTroopType()) {                     // Check if same type
        if ((march_1.getTroopType() == 0 && march_1.getTroopType() == 1)        // If not then check if M1 has advantage
            || (march_1.getTroopType() == 1 && march_1.getTroopType() == 2)     
            || (march_1.getTroopType() == 2 && march_1.getTroopType() == 0)) {  
            (*turn_log)["m1 attack"] *= 1.05;
            (*turn_log)["m1 counter"] *= 1.05;
            (*turn_log)["m1 skill dmg"] *= 1.05;
            (*turn_log)["m2 attack"] *= 0.95;
            (*turn_log)["m2 counter"] *= 0.95;
            (*turn_log)["m2 skill dmg"] *= 0.95;
        } else {                                                                // If M1 doesn't then M2 does
            (*turn_log)["m2 attack"] *= 1.05;
            (*turn_log)["m2 counter"] *= 1.05;
            (*turn_log)["m2 skill dmg"] *= 1.05;
            (*turn_log)["m1 attack"] *= 0.95;
            (*turn_log)["m1 counter"] *= 0.95;
            (*turn_log)["m1 skill dmg"] *= 0.95;
        }
    }
}

void Battle::run() {
    while (this->march_1->getTroopCnt() > 0 && this->march_2->getTroopCnt() > 0) {
        map<string, double> turn_log {{"m1 attack", 0}, {"m1 counter", 0}, {"m1 skill dmg", 0},
                                      {"m2 attack", 0}, {"m2 counter", 0}, {"m2 skill dmg", 0},
                                      {"m1 rage", 0}, {"m2 rage", 0}, 
                                      {"m1 troop cnt", 0}, {"m2 troop cnt", 0}};
        bool m1_skill_fired = false, m2_skill_fired = false;

        // Add base rage generated from this turn
        this->march_1->addRage(102);
        this->march_2->addRage(102);

        // Calculate attacks and counters
        turn_log["m1 attack"] = this->march_1->getAttack() / this->march_2->getDefense();          // m2 losses
        turn_log["m2 counter"] = this->march_2->getCounterAttack() / this->march_1->getDefense();  // m1 losses 
        turn_log["m2 attack"] = this->march_2->getAttack() / this->march_1->getDefense();          // m1 losses
        turn_log["m1 counter"] = this->march_1->getCounterAttack() / this->march_2->getDefense();  // m2 losses

        // Calculate skill damage
        if (this->march_1->getRage() >= 1000) {
            turn_log["m1 skill dmg"] = this->march_1->getSkillDmg() / this->march_2->getDefense();  // m2 losses
            this->march_1->addRage(this->march_1->getRage()*-1);                                    // reset m1's rage       
        }
        if (this->march_2->getRage() >= 1000) {
            turn_log["m2 skill dmg"] = this->march_2->getSkillDmg() / this->march_1->getDefense();  // m1 losses
            this->march_2->addRage(this->march_2->getRage()*-1);                                    // reset m2's rage
        }

        // Apply dmg reductions (From march *buffs*, not enemy debuffs)
        turn_log["m1 attack"] = this->march_2->applyAtkDmgReduction(turn_log["m1 attack"]);
        turn_log["m2 attack"] = this->march_2->applyAtkDmgReduction(turn_log["m2 attack"]);
        turn_log["m2 counter"] = this->march_2->applyCntDmgReduction(turn_log["m2 counter"]);
        turn_log["m1 counter"] = this->march_2->applyCntDmgReduction(turn_log["m1 counter"]);
        turn_log["m1 skill dmg"] = this->march_2->applySkillDmgReduction(turn_log["m1 skill dmg"]);
        turn_log["m2 skill dmg"] = this->march_2->applySkillDmgReduction(turn_log["m2 skill dmg"]);

        // Apply troop advantage bonus
        applyTroopAdvantage(*(this->march_1), *(this->march_2), &turn_log);

        // Apply rage compensation
        if (turn_log["m1 attack"]  < turn_log["m2 counter"] ) { this->march_1->addRage(10); }
        else { this->march_2->addRage(10); } 
        if (turn_log["m2 attack"]  < turn_log["m1 counter"] ) { this->march_2->addRage(10); }
        else { this->march_1->addRage(10); }

        // Apply temporary buffs/debuffs for next turn
        

        // Apply ceiling function to every value
        for (auto e : turn_log) {turn_log[e.first] = ceil(turn_log[e.first]);}

        // Apply losses to each march
        this->march_1->applyLoss(turn_log["m2 attack"] + turn_log["m2 counter"] + turn_log["m2 skill dmg"]);
        this->march_2->applyLoss(turn_log["m1 attack"] + turn_log["m1 counter"] + turn_log["m1 skill dmg"]);

        // Log cummulative rage generated
        turn_log["m1 rage"] = this->march_1->getRage();
        turn_log["m2 rage"] = this->march_2->getRage();

        // Add turn log to battle log
        this->log.push_back(turn_log);
    }
}

void Battle::printLog() {
    printf("#=====================================================================================#\n");
    printf("|                                        START                                        |\n");
    for (int turn = 0; turn < static_cast<int>(log.size()); turn++) {
        printf("#=====================================================================================#\n");
        printf("Turn %d \t\t\t\t\tUnits\t\tUnit Change\n",turn+1);
        printf("[Our Side]\t\t\t\t%d\t\t\t-%d\n", static_cast<int>(this->log.at(turn)["m1 troop cnt"]),                                   
                                                  static_cast<int>(this->log.at(turn)["m2 attack"]+this->log.at(turn)["m2 counter"]));         
        printf("[Enemy]\t\t\t\t\t%d\t\t\t-%d\n", static_cast<int>(this->log.at(turn)["m2 troop cnt"]),                                    
                                                 static_cast<int>(this->log.at(turn)["m1 attack"]+this->log.at(turn)["m1 counter"]));          
        printf("[%s] (%d) attacked [%s], [%s] lost %d units\n", this->march_1->getName().c_str(),                 
                                                                static_cast<int>(this->log.at(turn)["m1 troop cnt"]),
                                                                this->march_2->getName().c_str(),
                                                                this->march_2->getName().c_str(),
                                                                static_cast<int>(this->log.at(turn)["m1 attack"]));
        printf("\t[%s] launched a counterattack, [%s] lost %d units\n", this->march_2->getName().c_str(),
                                                                        this->march_1->getName().c_str(),
                                                                        static_cast<int>(this->log.at(turn)["m2 counter"]));
        printf("[%s] (%d) attacked [%s], [%s] lost %d units\n", this->march_2->getName().c_str(),                 
                                                                static_cast<int>(this->log.at(turn)["m2 troop cnt"]),
                                                                this->march_1->getName().c_str(),
                                                                this->march_1->getName().c_str(),
                                                                static_cast<int>(this->log.at(turn)["m2 attack"]));
        printf("\t[%s] launched a counterattack, [%s] lost %d units\n", this->march_1->getName().c_str(),
                                                                        this->march_2->getName().c_str(),
                                                                        static_cast<int>(this->log.at(turn)["m1 counter"]));
        printf("#=====================================================================================#\n");
    }
    printf("|                                         END                                         |\n");
    printf("#=====================================================================================#\n");
}

int Battle::exportLog() {
    auto now = std::chrono::system_clock::now();
    std::time_t time = std::chrono::system_clock::to_time_t(now);

    char *fname = static_cast<char*>(malloc(this->march_1->getName().size()
                                            +this->march_2->getName().size()
                                            +strlen(std::ctime(&time))
                                            +14));
    // If running ROKC in main directory then this works. If running from inside build then need ../ instead of ./
    sprintf(fname, "./log/%s_%s_%s.csv", this->march_1->getName().c_str(), 
                                   this->march_2->getName().c_str(), 
                                   std::ctime(&time));
    FILE *fp;
    if((fp = fopen(fname, "w")) == NULL){
        printf ("ERROR: Fail to open %s\n", fname);
        return -1;
    }
    
    fprintf(fp, "M1_Troop_Cnt,Loss_1,Loss_2,Skill_Loss,Turn_Rage,Tot_Rage,M2_Troop_Cnt,Loss_1,Loss_2,Skill_Loss,Turn_Rage,Tot_Rage\n");
    for(int turn = 0; turn < static_cast<int>(this->log.size()); turn++) {
        fprintf(fp, "%d,%d,%d,%d,%d,%d,%d,%d,%d,%d\n", static_cast<int>(this->log.at(turn)["m1 troop cnt"]),
                                                             static_cast<int>(this->log.at(turn)["m2 attack"]),
                                                             static_cast<int>(this->log.at(turn)["m2 counter"]),
                                                             static_cast<int>(this->log.at(turn)["m2 skill dmg"]),
                                                             static_cast<int>(this->log.at(turn)["m1 rage"]),
                                                             static_cast<int>(this->log.at(turn)["m2 troop cnt"]),
                                                             static_cast<int>(this->log.at(turn)["m1 attack"]),
                                                             static_cast<int>(this->log.at(turn)["m1 counter"]),
                                                             static_cast<int>(this->log.at(turn)["m1 skill dmg"]),
                                                             static_cast<int>(this->log.at(turn)["m2 rage"]));
    } 
    fclose(fp);
    free(fname);
    return 0;
}
