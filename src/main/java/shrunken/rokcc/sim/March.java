package shrunken.rokcc.sim;

import java.lang.Math;
import java.util.ArrayList;
import java.util.List;

import shrunken.rokcc.sim.buff.BuffSet;
import shrunken.rokcc.sim.buff.BuffType;
import shrunken.rokcc.sim.buff.TemporaryBuff;
import shrunken.rokcc.sim.troop.Troop;
import shrunken.rokcc.sim.troop.TroopType;

public class March {
    private static final double EQ_CONST_1 = 10000;
    private static final double EQ_CONST_2 = 2;
    private static final double EQ_CONST_3 = 333333;

    private String name;
    private double troopCnt, rage;
    private Troop troop;
    private List<TemporaryBuff> tempBuffList;
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

        tempBuffList = new ArrayList<TemporaryBuff>();
        tempBuffList.addAll(primaryCmdr.getTempBuffList());
        tempBuffList.addAll(secondaryCmdr.getTempBuffList());
    }

    // Getters
    public String getName() {return this.name;}
    public double getTroopCnt() {return this.troopCnt;}
    public double getRage() {return this.rage;}
    public Troop getTroop() {return this.troop;}
    public BuffSet getBuffSet() {return this.buffSet;}
    public Commander getPrimaryCmdr() {return this.primaryCmdr;}
    public Commander getSecondaryCmdr() {return this.secondaryCmdr;}
    public List<TemporaryBuff> getTempBuffsList() {return this.tempBuffList;}

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
    public void addTempBuff(TemporaryBuff tempBuff) {buffSet.addBuff(tempBuff);}
    public void removeTempBuff(TemporaryBuff tempBuff) {buffSet.removeBuff(tempBuff);}

    public double applyNormDmgReduction(double losses) {
        return losses * (1 - (buffSet.getBuff(BuffType.ALL_DMG_REDUCTION, TroopType.ALL).getValue()
                        + buffSet.getBuff(BuffType.NORMAL_DMG_REDUCTION, TroopType.ALL).getValue()));
    }
    
    public double applyCntrDmgReduction(double losses) {
        return losses * (1 - (buffSet.getBuff(BuffType.ALL_DMG_REDUCTION, TroopType.ALL).getValue()
                                + buffSet.getBuff(BuffType.NORMAL_DMG_REDUCTION, TroopType.ALL).getValue()
                                + buffSet.getBuff(BuffType.COUNTER_DMG_REDUCTION, TroopType.ALL).getValue()));
    }

    public double applySkillDmgReduction(double losses) {
        return losses * (1 - (buffSet.getBuff(BuffType.ALL_DMG_REDUCTION, TroopType.ALL).getValue()
                                + buffSet.getBuff(BuffType.SKILL_DMG_REDUCTION, TroopType.ALL).getValue()));
    }

    public double calcDefense() {
        double defense = (troop.getDef()
                            * troop.getHp()
                            * (1 + buffSet.getBuff(BuffType.DEF, troop.getTroopType()).getValue())
                            * (1 + buffSet.getBuff(BuffType.HP, troop.getTroopType()).getValue()));
        return defense;
    }

    public double calcAttack() {
        double attack = (troop.getAtk()
                            * (1 + buffSet.getBuff(BuffType.ATK, troop.getTroopType()).getValue())
                            * (1 + buffSet.getBuff(BuffType.ALL_DMG, TroopType.ALL).getValue()
                                 + buffSet.getBuff(BuffType.NORMAL_DMG, TroopType.ALL).getValue())
                            * troopCnt
                            * Math.sqrt(EQ_CONST_1 / troopCnt)
                            * (EQ_CONST_2 + (troopCnt / EQ_CONST_3)));
        return attack;
    }

    public double calcCounterAtk() {
        double counterAtk = (troop.getAtk()
                                * (1 + buffSet.getBuff(BuffType.ATK, troop.getTroopType()).getValue())
                                * (1 + buffSet.getBuff(BuffType.ALL_DMG, TroopType.ALL).getValue()
                                     + buffSet.getBuff(BuffType.NORMAL_DMG, TroopType.ALL).getValue()
                                     + buffSet.getBuff(BuffType.COUNTER_DMG, TroopType.ALL).getValue())
                                * troopCnt
                                * Math.sqrt(EQ_CONST_1 / troopCnt)
                                * (EQ_CONST_2 + (troopCnt / EQ_CONST_3)));
        return counterAtk;
    }

    public double calcDirectDmg(int primORsecond) {
        double directDmgFac = 0;

        if (primORsecond == 1) {
            directDmgFac = primaryCmdr.getBuffSet().getBuff(BuffType.DIRECT_DMG_FACTOR, TroopType.ALL).getValue();
        } else if (primORsecond == 2) {
            directDmgFac = secondaryCmdr.getBuffSet().getBuff(BuffType.DIRECT_DMG_FACTOR, TroopType.ALL).getValue();
        }
         
        double attack = (troop.getAtk()
                            * (1 + buffSet.getBuff(BuffType.ATK, troop.getTroopType()).getValue())
                            * (1 + buffSet.getBuff(BuffType.ALL_DMG, TroopType.ALL).getValue()
                                 + buffSet.getBuff(BuffType.SKILL_DMG, TroopType.ALL).getValue())
                            * troopCnt
                            * Math.sqrt(EQ_CONST_1 / troopCnt)
                            * (EQ_CONST_2 + (troopCnt / EQ_CONST_3)));

        return attack * (directDmgFac / 200);
    }

    public double calcHeal() {
        double healAmount = (buffSet.getBuff(BuffType.HEAL_FACTOR, TroopType.ALL).getValue() * Math.sqrt(troopCnt)) / troop.getHp();
        healAmount = healAmount * (1 + buffSet.getBuff(BuffType.HEAL_ENHANCEMENT, TroopType.ALL).getValue());
        return healAmount;
    }

    public double calcShield() {
        double shieldAmount = (buffSet.getBuff(BuffType.SHIELD_FACTOR, TroopType.ALL).getValue() * Math.sqrt(troopCnt)) / 
                                (troop.getHp() * (1 + buffSet.getBuff(BuffType.HP, troop.getTroopType()).getValue()));
        return shieldAmount;
    }

}
