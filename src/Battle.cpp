#include "Battle.h"

Battle::Battle(March *march_1, March *march_2) {
    this->march_1 = march_1;
    this->march_2 = march_2;
    this->log = vector<vector<double>>();
}

void Battle::start() {
    int turn = 1;

    while (this->march_1->getTroopCnt() > 0 && this->march_2->getTroopCnt() > 0) {
        vector<double> turn_log = vector<double>();

        // Log the troop cnts
        turn_log.push_back(this->march_1->getTroopCnt());
        turn_log.push_back(this->march_2->getTroopCnt());

        // m1 attack, m2 counter
        turn_log.push_back(this->march_1->getAttack() /             // m2 loss
                           this->march_2->getDefense());           
        turn_log.push_back(this->march_2->getCounterAttack() /      // m1 loss
                           this->march_1->getDefense());    

        // m2 attack, m1 counter
        turn_log.push_back(this->march_2->getAttack() /             // m1 loss
                           this->march_1->getDefense());           
        turn_log.push_back(this->march_1->getCounterAttack() /      // m2 loss
                           this->march_2->getDefense());   

        // Turn log entry -> 0: m1 troop_cnt 
        //                   1: m2 troop_cnt
        //                   2: m2 loss from m1 attack
        //                   3: m1 loss from m2 counter
        //                   4: m1 loss from m2 attack
        //                   5: m2 loss from m1 counter

        // Apply losses to each march
        this->march_1->update(turn, turn_log.at(3) + turn_log.at(4));
        this->march_2->update(turn, turn_log.at(2) + turn_log.at(5));

        // Add turn log to battle log
        this->log.push_back(turn_log);
        turn++;
    }
}

void Battle::printLog() {
    printf("#=====================================================================================#\n");
    printf("|                                        START                                        |\n");
    for (int turn = 0; turn < static_cast<int>(log.size()); turn++) {
        printf("#=====================================================================================#\n");
        printf("Turn %d \t\t\t\t\tUnits\t\tUnit Change\n",turn+1);
        printf("[Our Side]\t\t\t\t%d\t\t\t-%d\n", static_cast<int>(ceil(this->log.at(turn).at(0))),                                   // m1 count
                                                  static_cast<int>(ceil(this->log.at(turn).at(3))+ceil(this->log.at(turn).at(4))));   // m1 turn losses
        printf("[Enemy]\t\t\t\t\t%d\t\t\t-%d\n", static_cast<int>(ceil(this->log.at(turn).at(1))),                                    // m2 count
                                                 static_cast<int>(ceil(this->log.at(turn).at(2))+ceil(this->log.at(turn).at(5))));    // m2 turn losses
        printf("[%s] (%d) attacked [%s], [%s] lost %d units\n", this->march_1->getName().c_str(),                 
                                                                static_cast<int>(ceil(this->log.at(turn).at(0))),
                                                                this->march_2->getName().c_str(),
                                                                this->march_2->getName().c_str(),
                                                                static_cast<int>(ceil(this->log.at(turn).at(2))));
        printf("\t[%s] launched a counterattack, [%s] lost %d units\n", this->march_2->getName().c_str(),
                                                                        this->march_1->getName().c_str(),
                                                                        static_cast<int>(ceil(this->log.at(turn).at(3))));
        printf("[%s] (%d) attacked [%s], [%s] lost %d units\n", this->march_2->getName().c_str(),                 
                                                                static_cast<int>(ceil(this->log.at(turn).at(1))),
                                                                this->march_1->getName().c_str(),
                                                                this->march_1->getName().c_str(),
                                                                static_cast<int>(ceil(this->log.at(turn).at(4))));
        printf("\t[%s] launched a counterattack, [%s] lost %d units\n", this->march_1->getName().c_str(),
                                                                        this->march_2->getName().c_str(),
                                                                        static_cast<int>(ceil(this->log.at(turn).at(5))));
        printf("#=====================================================================================#\n");
    }
    printf("|                                         END                                         |\n");
    printf("#=====================================================================================#\n");
}

vector<vector<double>> Battle::getLog() {
    return this->log;
}