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
#include "matplotlibcpp.h"

#include "March.h"

using namespace std;

class Battle {
    public:
        Battle() {};
        ~Battle() {};
        Battle(March *march_1, March *march_2);

        void run();
        void printLog();
        int exportLog();
        vector<vector<double>> getLog();

    private:
        March *march_1;
        March *march_2;
        vector<vector<double>> log;
};

#endif 
