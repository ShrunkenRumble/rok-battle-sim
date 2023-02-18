#ifndef BATTLE_H_
#define BATTLE_H_

#include <iostream>
#include <chrono>
#include <ctime> 
#include <stdio.h>
#include <string.h>
#include <cstring>
#include <vector>
#include <math.h>
#include <map>

#include "March.h"

using namespace std;

class Battle {
    public:
        Battle() {};
        ~Battle() {};
        Battle(March *march_1, March *march_2) { 
            this->march_1 = march_1; 
            this->march_2 = march_2; 
            this->log = vector<map<string, double>>();
        };

        vector<map<string, double>> getLog() {return this->log;};

        void run();
        void printLog();
        int exportLog();

    private:
        March *march_1;
        March *march_2;
        vector<map<string,double>> log;
};

#endif 
