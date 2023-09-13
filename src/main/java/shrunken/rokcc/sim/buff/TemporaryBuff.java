package shrunken.rokcc.sim.buff;

import shrunken.rokcc.sim.troop.TroopType;

public class TemporaryBuff extends Buff{
    private int duration;
    private int cooldown;
    private int terminationTurn;
    private int cooldownEndTurn;
    private double probability;

    public TemporaryBuff(BuffType buffType, TroopType troopType, boolean isDebuff, double value, int duration, int cooldown, double probability) {
        super(buffType, troopType, isDebuff, value);
        this.duration = duration;
        this.cooldown = cooldown;
        this.probability = probability;
        terminationTurn = 0;
        cooldownEndTurn = 0;
    }

    public TemporaryBuff(BuffType buffType, TroopType troopType, boolean isDebuff) {
        super(buffType, troopType, isDebuff);
        this.duration = 0;
        this.cooldown = 0;
        this.probability = 0;
        terminationTurn = 0;
        cooldownEndTurn = 0;
    }

    public TemporaryBuff() {}

    // Getters
    public int getDuration() {return this.duration;}
    public int getCooldown() {return this.cooldown;}
    public int getTerminationTurn() {return this.terminationTurn;}
    public int getCooldownEndTurn() {return this.cooldownEndTurn;}
    public double getProbability() {return this.probability;}

    // Setters
    public void setDuration(int duration) {this.duration = duration;}
    public void setCooldown(int cooldown) {this.cooldown = cooldown;}
    public void setTerminationTurn(int turn) {this.terminationTurn = turn;}
    public void setCooldownEndTurn(int turn) {this.cooldownEndTurn = turn;}
    public void setProbability(double probability) {this.probability = probability;}
}
