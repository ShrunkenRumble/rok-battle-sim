package shrunken.rokcc.sim;

public class Troop {
    private double atk;
    private double def;
    private double hp;
    private TroopType troopType;

    public Troop(double atk, double def, double hp, TroopType troopType) {
        this.atk = atk;
        this.def = def;
        this.hp = hp;
        this.troopType = troopType;
    }

    public double getAtk() {return this.atk;}
    public double getDef() {return this.def;}
    public double getHp() {return this.hp;}
    public TroopType getTroopType() {return this.troopType;}
}
