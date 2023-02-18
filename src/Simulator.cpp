#include "Troop.h"
#include "Buffs.h"
#include "March.h"
#include "Battle.h"
#include "Commander.h"
#include "TroopType.h"

#include <fstream>
#include "value.h"
#include "json.h"

using namespace std;

int main(int argc, char **argv) {
    //Troop troop = Troop(128, 125, 125, TroopType::Infantry);
    //Commander comm1 = Commander("Comm1", 60);
    //Commander comm2 = Commander("Comm2", 70);
    //Commander empty_comm = Commander("EmptyCommSlot", 0.0);
    //BuffSet buff_set_1 = BuffSet(8.5, 1, 1.5, 0, 0, 0, 0, 0);
    //BuffSet buff_set_2 = BuffSet(5.5, 1, 3.5, 0, 0, 0, 0, 0);
    //DebuffSet debuff_set = DebuffSet(0, 0, 0, 0, 0, 0, 0);
    //March march_1 = March("Markswoman", 100000, 0, &troop, &buff_set_1, &debuff_set, &comm1, &empty_comm);
    //March march_2 = March("Markswoman", 100000, 0, &troop, &buff_set_2, &debuff_set, &comm2, &empty_comm);

    //Battle battle = Battle(&march_1, &march_2);

    //battle.run();

    //battle.printLog();
    //battle.exportLog();

    ifstream file("data/commanders.json");
    Json::Value commanders;
    Json::Reader reader;

    reader.parse(file, commanders);
    cout << "Total commanders data:\n" << commanders << endl;

    cout << commanders["city_keeper"]["passive_1"]["a"]["lvl_val"][0] << endl;
    return 0;
}
