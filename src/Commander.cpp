#include "Commander.h"

void Commander::loadCmdrData(string name) {
    ifstream file("data/commanders.json");
    Json::Value commanders;
    Json::Reader reader;

    reader.parse(file, commanders);

}