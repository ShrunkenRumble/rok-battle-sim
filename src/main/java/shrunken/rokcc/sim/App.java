package shrunken.rokcc.sim;

public class App {

    public static void main(String[] args) {
        System.out.println("Hello World!");

        Commander comm = Commander.loadFromJson("city_keeper", new int[]{0, 3, 4, 5});

        System.out.println(comm.getRageRequirement());
        System.out.println(comm.getActive().get(0).getBuffType());
    }
}
