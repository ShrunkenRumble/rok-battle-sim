#include "Troop.h"
#include "Buffs.h"
#include "March.h"
#include "Battle.h"

using namespace std;

int main(int argc, char **argv) {
    Troop *troop = new Troop(128, 125, 125);
    Buffs *buffs_1 = new Buffs(8.5, 1, 1.5, 0);
    Buffs *buffs_2 = new Buffs(5.5, 1, 3.5, 0);
    March *march_1 = new March("Dragon Lancer", 15000, 0, troop, buffs_1);
    March *march_2 = new March("Markswoman", 15000, 0, troop, buffs_2);

    Battle *battle = new Battle(march_1, march_2);

    battle->start();
    battle->printLog();
    return 0;
}