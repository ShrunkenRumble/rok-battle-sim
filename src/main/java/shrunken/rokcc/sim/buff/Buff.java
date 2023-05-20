package shrunken.rokcc.sim.buff;

import com.fasterxml.jackson.annotation.JsonIgnore;
import shrunken.rokcc.sim.TroopType;

public class Buff {
    private BuffType buffType;
    private TroopType troopType;

    @JsonIgnore
    private double value;

    public Buff(BuffType buffType, TroopType troopType, double value) {
        this.buffType = buffType;
        this.troopType = troopType;
        this.value = value;
    }

    public Buff(BuffType buffType, TroopType troopType) {
        this.buffType = buffType;
        this.troopType = troopType;
        this.value = 0;
    }

    public Buff() {}

    @Override
    public Buff clone() {
        return new Buff(this.buffType, this.troopType, this.value);
    }

    // Getters
    public BuffType getBuffType() {return this.buffType;}
    public TroopType getTroopType() {return this.troopType;}
    public double getValue() {return this.value;}

    // Setters
    public void setBuffType(BuffType buffType) {this.buffType = buffType;}
    public void setTroopType(TroopType troopType) {this.troopType = troopType;}
    public void setValue(double value) {this.value = value;}

    /*
     * Is not mean't to be used on TemporaryBuffs or SkillComponents.
     */
    public void plus(Buff buff2) {
        if (!(buff2 instanceof TemporaryBuff) && !(buff2 instanceof SkillComponent)) {
            if (!(this instanceof TemporaryBuff) && !(this instanceof SkillComponent)) {
                if (this.equals(buff2)) {
                    this.value += buff2.getValue();
                }
            }
        }
    }
    /*
     * Is not mean't to be used on TemporaryBuffs or SkillComponents.
     * Also note that a buff value should never be zero.
     */
    public void minus(Buff buff2) {
        if (!(buff2 instanceof TemporaryBuff) && !(buff2 instanceof SkillComponent)) {
            if (!(this instanceof TemporaryBuff) && !(this instanceof SkillComponent)) {
                if (this.equals(buff2)) {
                    if (this.value - buff2.getValue() >= 0.0) {
                        this.value -= buff2.getValue();
                    } else {
                        this.value = 0;
                    }
                }
            }
        }
    }

    /*
     * Override the equals to ensure that when using these objects as keys
     * only the bufftype and trooptype are relevant.
     */
    @Override
    public boolean equals(Object obj) {
        if (obj instanceof Buff) {
            if ((this.buffType.equals(((Buff) obj).buffType)) && (this.troopType.equals(((Buff) obj).troopType))) {
                return true;
            }
        }
        return false;
    }
    
    /*
     * Override the hashCode() to ensure that when using these objects 
     * as keys only the bufftype and trooptype are relevant
     */
    @Override   
    public int hashCode() {
        return this.buffType.hashCode() + this.troopType.hashCode();
    }


}
