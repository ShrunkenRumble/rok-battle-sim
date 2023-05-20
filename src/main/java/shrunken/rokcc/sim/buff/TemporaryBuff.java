package shrunken.rokcc.sim.buff;

import shrunken.rokcc.sim.troop.TroopType;

public class TemporaryBuff extends Buff{
    private int duration;
    private int cooldown;

    public TemporaryBuff(BuffType buffType, TroopType troopType, double value, int duration, int cooldown) {
        super(buffType, troopType, value);
        this.duration = duration;
        this.cooldown = cooldown;
    }

    public TemporaryBuff(BuffType buffType, TroopType troopType) {
        super(buffType, troopType);
        this.duration = 0;
        this.cooldown = 0;
    }

    public TemporaryBuff() {}

    // Getters
    public int getDuration() {return this.duration;}
    public int getCooldown() {return this.cooldown;}

    // Setters
    public void setDuration(int duration) {this.duration = duration;}
    public void setCooldown(int cooldown) {this.cooldown = cooldown;}

}
