package shrunken.rokcc.sim;

import java.lang.Math;
import shrunken.rokcc.sim.buff.BuffSet;
import shrunken.rokcc.sim.buff.BuffType;
import shrunken.rokcc.sim.troop.Troop;

public class March {
    private static final double EQ_CONST_1 = 10000;
    private static final double EQ_CONST_2 = 2;
    private static final double EQ_CONST_3 = 333333;

    private String name;
    private double troopCnt, rage;
    private Troop troop;
    private BuffSet buffSet;
    private Commander primaryCmdr;
    private Commander secondaryCmdr;

    public March(String name, double troopCnt, Troop troop, BuffSet buffSet, 
                Commander primaryCmdr, Commander secondaryCmdr) {
        this.name = name;
        this.troopCnt = troopCnt;
        this.troop = troop;
        this.buffSet = buffSet;
        this.primaryCmdr = primaryCmdr;
        this.secondaryCmdr = secondaryCmdr;

        this.buffSet.plus(primaryCmdr.getBuffSet());
        this.buffSet.plus(secondaryCmdr.getBuffSet());
    }

    // Getters
    public String getName() {return this.name;}
    public double getTroopCnt() {return this.troopCnt;}
    public double getRage() {return this.rage;}
    public Troop getTroop() {return this.troop;}
    public BuffSet getBuffSet() {return this.buffSet;}
    public Commander getPrimaryCmdr() {return this.primaryCmdr;}
    public Commander getSecondaryCmdr() {return this.secondaryCmdr;}

    // Setters
    public void setName(String name) {this.name = name;}
    public void setTroopCnt(double troopCnt) {this.troopCnt = troopCnt;}
    public void setRage(double rage) {this.rage = rage;}
    public void setTroop(Troop troop) {this.troop = troop;}
    public void setBuffSet(BuffSet buffSet) {this.buffSet = buffSet;}
    public void setPrimaryCmdr(Commander primaryCmdr) {this.primaryCmdr = primaryCmdr;}
    public void setSecondaryCmdr(Commander secondaryCmdr) {this.secondaryCmdr = secondaryCmdr;}

    public void addRage(double rage) {this.rage += rage;}
    public void applyLoss(double loss) {this.troopCnt -= loss;}
    
    
    public double applyAtkReduction(double losses) {
        return losses;
    }
    public double applyCntDmgReduction(double losses) {
        return losses;
    }
    public double applySkillDmgReduction(double losses) {
        return losses;
    }

    public double calcAttack() {
        double attack = (this.troop.getAtk()
                            * (1 + this.buffSet.getBuff(BuffType.ATK, this.troop.getTroopType()).getValue())
                            * (1 + this.buffSet.getBuff(BuffType.ALLDMG, this.troop.getTroopType()).getValue()
                                 + this.buffSet.getBuff(BuffType.NORMALDMG, this.troop.getTroopType()).getValue()));
        double adjAttack = (attack
                                * this.troopCnt
                                * Math.sqrt(EQ_CONST_1 / this.troopCnt)
                                * (EQ_CONST_2 + (this.troopCnt / EQ_CONST_3)));
        return adjAttack;
    }

    public double calcDefense() {
        double defense = (this.troop.getDef()
                            * this.troop.getHp()
                            * (1 + this.buffSet.getBuff(BuffType.DEF, this.troop.getTroopType()).getValue())
                            * (1 + this.buffSet.getBuff(BuffType.HP, this.troop.getTroopType()).getValue()));
        return defense;
    }

    public double calcCounterAtk() {
        double counterAtk = 0;
        double adjCounterAtk = 0;
        return adjCounterAtk;
    }

    public double calcPrimDirectDmg() {
        double directDmg = 0;
        return directDmg;
    }

    public double calcSecDirectDmg() {
        double directDmg = 0;
        return directDmg;
    }
}
