#ifndef BATTLE_H_
#define BATTLE_H_

#include <math.h>
#include <string.h>
#include <string>
#include <cstring>
#include <vector>
#include "March.h"

using namespace std;

class Battle {
    public:
        Battle() {};
        ~Battle() {delete march_1;
                   delete march_2;};
        Battle(March *march_1, March *march_2);

        void start();
        void printLog();
        vector<vector<double>> getLog();

    private:
        March *march_1;
        March *march_2;
        vector<vector<double>> log;
};

#endif 
