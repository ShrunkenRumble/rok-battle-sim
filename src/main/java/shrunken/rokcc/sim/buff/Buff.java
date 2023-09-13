package shrunken.rokcc.sim.buff;

import com.fasterxml.jackson.annotation.JsonIgnore;

import shrunken.rokcc.sim.troop.TroopType;

public class Buff {
    private BuffType buffType;
    private TroopType troopType;
    private boolean isDebuff;
    @JsonIgnore
    private double value;

    public Buff(BuffType buffType, TroopType troopType, boolean isDebuff, double value) {
        this.buffType = buffType;
        this.troopType = troopType;
        this.isDebuff = isDebuff;
        this.value = value;
    }

    public Buff(BuffType buffType, TroopType troopType, boolean isDebuff) {
        this.buffType = buffType;
        this.troopType = troopType;
        this.isDebuff = isDebuff;
        this.value = 0;
    }

    public Buff() {}

    @Override
    public Buff clone() {
        return new Buff(this.buffType, this.troopType, this.isDebuff, this.value);
    }

    // Getters
    public BuffType getBuffType() {return this.buffType;}
    public TroopType getTroopType() {return this.troopType;}
    public boolean getIsDebuff() {return this.isDebuff;}
    public double getValue() {return this.value;}

    // Setters
    public void setBuffType(BuffType buffType) {this.buffType = buffType;}
    public void setTroopType(TroopType troopType) {this.troopType = troopType;}
    public void setIsDebuff(boolean isDebuff) {this.isDebuff = isDebuff;}
    public void setValue(double value) {this.value = value;}

    /*
     * Can be used on TemporaryBuffs or SkillComponents so long as they are being added 
     * onto a permanent buff (i.e. the permanent buff calls .add(tempbuff))
     */
    public void plus(Buff buff2) {
        if (!(this instanceof TemporaryBuff) && !(this instanceof SkillComponent)) {
            if (this.equals(buff2)) {
                this.value += buff2.getValue();
            }
        }
    }
    /*
     * Is not mean't to be used on TemporaryBuffs or SkillComponents.
     */
    public static Buff add(Buff buff1, Buff buff2) {
        Buff result = new Buff();
        if (!(buff2 instanceof TemporaryBuff) && !(buff2 instanceof SkillComponent)) {
            if (!(buff1 instanceof TemporaryBuff) && !(buff1 instanceof SkillComponent)) {
                if (buff1.equals(buff2)) {
                    result.setBuffType(buff1.getBuffType());
                    result.setTroopType(buff1.getTroopType());
                    result.setValue(buff1.getValue() + buff2.getValue());
                }
            }
        }
        return result;
    }

    /*
     * Can be used on TemporaryBuffs or SkillComponents so long as they are being subtracted 
     * from a permanent buff (i.e. the permanent buff calls .minus(tempbuff))
     */
    public void minus(Buff buff2) {
        if (!(this instanceof TemporaryBuff) && !(this instanceof SkillComponent)) {
            if (this.equals(buff2)) {
                if (this.value - buff2.getValue() >= 0.0) {
                    this.value -= buff2.getValue();
                } else {
                    // A buff value should never be negative.
                    this.value = 0;
                }
            }
        }
    }
    /*
     * Is not mean't to be used on TemporaryBuffs or SkillComponents.
     */
    public static Buff subtract(Buff buff1, Buff buff2) {
        Buff result = new Buff();
        if (!(buff2 instanceof TemporaryBuff) && !(buff2 instanceof SkillComponent)) {
            if (!(buff1 instanceof TemporaryBuff) && !(buff1 instanceof SkillComponent)) {
                if (buff1.equals(buff2)) {
                    result.setBuffType(buff1.getBuffType());
                    result.setTroopType(buff1.getTroopType());
                    if (buff1.getValue() - buff2.getValue() >= 0.0) {
                        result.setValue(buff1.getValue() + buff2.getValue());
                    } else {
                        result.setValue(0);
                    }
                }
            }
        }
        return result;
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
