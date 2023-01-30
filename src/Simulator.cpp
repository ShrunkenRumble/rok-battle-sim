#include "Troop.h"
#include "Buffs.h"
#include "March.h"
#include "Battle.h"
#include "Commander.h"

using namespace std;

int main(int argc, char **argv) {
    Troop troop = Troop(128, 125, 125);
    Commander comm1 = Commander("Comm1", 60);
    Commander comm2 = Commander("Comm2", 70);
    Commander empty_comm = Commander("EmptyCommSlot", 0.0);
    Buffs buffs_1 = Buffs(8.5, 1, 1.5, 0);
    Buffs buffs_2 = Buffs(5.5, 1, 3.5, 0);
    March march_1 = March("Markswoman", 100000, 0, &troop, &buffs_1, &comm1, &empty_comm);
    March march_2 = March("Markswoman", 100000, 0, &troop, &buffs_2, &comm2, &empty_comm);

    Battle battle = Battle(&march_1, &march_2);

    battle.run();

    //battle.printLog();
    battle.exportLog();
    return 0;
}
