package shrunken.rokcc.sim;

public class SkillComponent {
    private String type;
    private TroopType troopType;
    private double turnDuration;
    private double turnInterval;
    private double value;

    public SkillComponent() {}
    
    public String getType() {return this.type;}
    public TroopType getTroopType() {return this.troopType;}
    public double getTurnDuration() {return this.turnDuration;}
    public double getTurnInterval() {return this.turnInterval;}
    public double getValue() {return this.value;}

    public void setType(String type) {this.type = type;}
    public void setTroopType(TroopType troopType) {this.troopType = troopType;}
    public void setTurnDuration(double turnDuration) {this.turnDuration = turnDuration;}
    public void setTurnInterval(double turnInterval) {this.turnInterval = turnInterval;}
    public void setValue(double value) {this.value = value;}

}
