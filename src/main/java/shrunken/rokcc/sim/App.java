package shrunken.rokcc.sim;

import shrunken.rokcc.sim.buff.BuffType;
import shrunken.rokcc.sim.troop.TroopType;

public class App {

    public static void main(String[] args) {
        System.out.println("Hello World!");

        Commander comm = Commander.loadFromJson("city_keeper", new int[]{5, 5, 1, 1});

        System.out.println(comm.getRageRequirement());
        System.out.println(comm.getActive().get(0).getBuffType());
        System.out.println(comm.getBuffSet().getBuff(BuffType.HP, TroopType.INF).getValue());
    }
}
