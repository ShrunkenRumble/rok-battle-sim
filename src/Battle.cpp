#include "Battle.h"

Battle::Battle(March *march_1, March *march_2) {
    this->march_1 = march_1;
    this->march_2 = march_2;
    this->log = vector<vector<double>>();
}

void Battle::run() {

    while (this->march_1->getTroopCnt() > 0 && this->march_2->getTroopCnt() > 0) {
        vector<double> turn_log = vector<double>();
        double m1_attack = 0, m2_attack = 0, m1_counter = 0, m2_counter = 0;
        double m1_skill_dmg = 0, m2_skill_dmg = 0;
        double m1_rage = 102, m2_rage = 102;

        // Add base rage generated from this turn
        this->march_1->updateRage(m1_rage);
        this->march_2->updateRage(m2_rage);

        // Calculate m1 attack, m2 counter
        m1_attack = this->march_1->getAttack() / this->march_2->getDefense();          // m2 losses
        m2_counter = this->march_2->getCounterAttack() / this->march_1->getDefense();  // m1 losses 
        // Calculate m2 attack, m1 counter
        m2_attack = this->march_2->getAttack() / this->march_1->getDefense();          // m1 losses
        m1_counter = this->march_1->getCounterAttack() / this->march_2->getDefense();  // m2 losses

        // Apply dmg reductions (From march *buffs*, not enemy debuffs)
        m1_attack = this->march_2->applyDmgReduction(m1_attack);
        m2_counter = this->march_1->applyDmgReduction(m2_counter);
        m2_attack = this->march_1->applyDmgReduction(m2_attack);
        m1_counter = this->march_2->applyDmgReduction(m1_counter);

        // Apply troop advantage bonus. 
        if ((this->march_1->getTroopType() == 0 && this->march_1->getTroopType() == 1)        // M1 Inf M2 Cav
            || (this->march_1->getTroopType() == 1 && this->march_1->getTroopType() == 2)     // M1 Cav M2 Arch
            || (this->march_1->getTroopType() == 2 && this->march_1->getTroopType() == 0)) {  // M1 Arch M2 Inf
            m1_attack *= 1.05;
            m1_counter *= 1.05;
            m2_attack *= 0.95;
            m2_counter *= 0.95;
        }
        if ((this->march_1->getTroopType() == 0 && this->march_1->getTroopType() == 2)        // M1 Inf M2 Arch
            || (this->march_1->getTroopType() == 1 && this->march_1->getTroopType() == 0)     // M1 Cav M2 Inf
            || (this->march_1->getTroopType() == 2 && this->march_1->getTroopType() == 1)) {  // M1 Arch M2 Cav
            m2_attack *= 1.05;
            m2_counter *= 1.05;
            m1_attack *= 0.95;
            m1_counter *= 0.95;
        } 

        // Calculate skill damage
        if (this->march_1->getRage() >= 1000) {
            m1_skill_dmg = this->march_1->getSkillDmg() / this->march_2->getDefense();  // m2 losses
            this->march_1->updateRage(this->march_1->getRage()*-1);       
        }
        if (this->march_2->getRage() >= 1000) {
            m2_skill_dmg = this->march_2->getSkillDmg() / this->march_1->getDefense();  // m1 losses
            this->march_2->updateRage(this->march_2->getRage()*-1);   
        }
        
        // Apply rage compensation
        if (m1_attack < m2_counter) {
            m1_rage += 10;
            this->march_1->updateRage(10);
        } else {
            m2_rage += 10;
            this->march_2->updateRage(10);
        }
        if (m2_attack < m1_counter) {
            m2_rage += 10;
            this->march_2->updateRage(10);
        } else {
            m1_rage += 10;
            this->march_1->updateRage(10);
        }
        
        // Turn log entry -> 0: m1 troop_cnt 
        //                   1: m2 troop_cnt
        //                   2: m2 loss from m1 attack
        //                   3: m1 loss from m2 counter
        //                   4: m1 loss from m2 attack
        //                   5: m2 loss from m1 counter
        //                   6: m2 loss from m1 skill dmg
        //                   7: m1 loss from m2 skill dmg
        //                   8: m1 rage generated during turn
        //                   9: m2 rage generated during turn
        //                  10: m1 cumulative rage at end of turn
        //                  11: m2 cumulative rage at end of turn
        turn_log.push_back(this->march_1->getTroopCnt());
        turn_log.push_back(this->march_2->getTroopCnt());
        turn_log.push_back(ceil(m1_attack));
        turn_log.push_back(ceil(m2_counter));
        turn_log.push_back(ceil(m2_attack));
        turn_log.push_back(ceil(m1_counter));
        turn_log.push_back(ceil(m1_skill_dmg));
        turn_log.push_back(ceil(m2_skill_dmg));
        turn_log.push_back(m1_rage);
        turn_log.push_back(m2_rage);
        turn_log.push_back(this->march_1->getRage());
        turn_log.push_back(this->march_2->getRage());

        // Apply losses to each march
        this->march_1->updateTroopCnt(turn_log.at(3) + turn_log.at(4) + turn_log.at(7));
        this->march_2->updateTroopCnt(turn_log.at(2) + turn_log.at(5) + turn_log.at(6));

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
        printf("[Our Side]\t\t\t\t%d\t\t\t-%d\n", static_cast<int>(this->log.at(turn).at(0)),                                   // m1 count
                                                  static_cast<int>(this->log.at(turn).at(3)+this->log.at(turn).at(4)));         // m1 turn losses
        printf("[Enemy]\t\t\t\t\t%d\t\t\t-%d\n", static_cast<int>(this->log.at(turn).at(1)),                                    // m2 count
                                                 static_cast<int>(this->log.at(turn).at(2)+this->log.at(turn).at(5)));          // m2 turn losses
        printf("[%s] (%d) attacked [%s], [%s] lost %d units\n", this->march_1->getName().c_str(),                 
                                                                static_cast<int>(this->log.at(turn).at(0)),
                                                                this->march_2->getName().c_str(),
                                                                this->march_2->getName().c_str(),
                                                                static_cast<int>(this->log.at(turn).at(2)));
        printf("\t[%s] launched a counterattack, [%s] lost %d units\n", this->march_2->getName().c_str(),
                                                                        this->march_1->getName().c_str(),
                                                                        static_cast<int>(this->log.at(turn).at(3)));
        printf("[%s] (%d) attacked [%s], [%s] lost %d units\n", this->march_2->getName().c_str(),                 
                                                                static_cast<int>(this->log.at(turn).at(1)),
                                                                this->march_1->getName().c_str(),
                                                                this->march_1->getName().c_str(),
                                                                static_cast<int>(this->log.at(turn).at(4)));
        printf("\t[%s] launched a counterattack, [%s] lost %d units\n", this->march_1->getName().c_str(),
                                                                        this->march_2->getName().c_str(),
                                                                        static_cast<int>(this->log.at(turn).at(5)));
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
        printf ("ERROR: Fail to open: %s\n", fname);
        return -1;
    }
    
    fprintf(fp, "M1_Troop_Cnt,Loss_1,Loss_2,Skill_Loss,Turn_Rage,Tot_Rage,M2_Troop_Cnt,Loss_1,Loss_2,Skill_Loss,Turn_Rage,Tot_Rage\n");
    for(int turn = 0; turn < static_cast<int>(this->log.size()); turn++) {
        fprintf(fp, "%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d\n", static_cast<int>(this->log.at(turn).at(0)),
                                                       static_cast<int>(this->log.at(turn).at(3)),
                                                       static_cast<int>(this->log.at(turn).at(4)),
                                                       static_cast<int>(this->log.at(turn).at(7)),
                                                       static_cast<int>(this->log.at(turn).at(8)),
                                                       static_cast<int>(this->log.at(turn).at(10)),
                                                       static_cast<int>(this->log.at(turn).at(1)),
                                                       static_cast<int>(this->log.at(turn).at(2)),
                                                       static_cast<int>(this->log.at(turn).at(5)),
                                                       static_cast<int>(this->log.at(turn).at(6)),
                                                       static_cast<int>(this->log.at(turn).at(9)),
                                                       static_cast<int>(this->log.at(turn).at(11)));
    } 
    fclose(fp);
    free(fname);
    return 0;
}

vector<vector<double>> Battle::getLog() {
    return this->log;
}