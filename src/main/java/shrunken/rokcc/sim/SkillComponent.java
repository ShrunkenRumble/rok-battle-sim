package shrunken.rokcc.sim;

import java.util.List;

public class SkillComponent {
    private String type;
    private TroopType troopType;
    private int turnDuration;
    private int turnInterval;
    private List<Double> value;

    public SkillComponent() {}
    
    public String getType() {return this.type;}
    public TroopType getTroopType() {return this.troopType;}
    public int getTurnDuration() {return this.turnDuration;}
    public int getTurnInterval() {return this.turnInterval;}
    public List<Double> getValue() {return this.value;}

}
