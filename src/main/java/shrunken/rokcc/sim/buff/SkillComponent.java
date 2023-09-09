package shrunken.rokcc.sim.buff;

import java.util.List;

import shrunken.rokcc.sim.troop.TroopType;

public class SkillComponent extends TemporaryBuff{
    private List<Double> values;

    public SkillComponent(BuffType buffType, TroopType troopType, List<Double> values, int duration, int cooldown, double probability) {
        super(buffType, troopType, 0, duration, cooldown, probability);
        this.values = values;
    }

    public SkillComponent(BuffType buffType, TroopType troopType) {
        super(buffType, troopType);
        this.values = null;
    }

    public SkillComponent() {}
    
    // Getters
    public List<Double> getValues() {return this.values;}

    // Setters
    public void setValues(List<Double> values) {this.values = values;}

    public TemporaryBuff toTempBuff(int skillLevel) {
        TemporaryBuff tempBuff = new TemporaryBuff(this.getBuffType(), 
                                                    this.getTroopType(), 
                                                    values.get(skillLevel), 
                                                    this.getDuration(), 
                                                    this.getCooldown(),
                                                    this.getProbability());
        return tempBuff;
    }

    public Buff toBuff(int skillLevel) {
        Buff buff = new Buff(this.getBuffType(), 
                                this.getTroopType(), 
                                values.get(skillLevel));
        return buff;
    }

}
