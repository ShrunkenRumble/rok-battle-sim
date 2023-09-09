package shrunken.rokcc.sim;

import java.util.Arrays;
import joinery.DataFrame;
import shrunken.rokcc.sim.buff.TemporaryBuff;
import shrunken.rokcc.sim.troop.TroopType;

public class Battle {
    private March march1;
    private March march2;
    private DataFrame<Double> log;
    
    public Battle(March march1, March march2) {
        this.march1 = march1;
        this.march2 = march2;
        log = new DataFrame<Double>("m1-attack", "m1-counter", "m1-skill-dmg", "m1-rage", "m1-troop-cnt", 
                                    "m2-attack", "m2-counter", "m2-skill-dmg", "m2-rage", "m2-troop-cnt");
    }

    public void run() {
        int turn = 0;
        while (march1.getTroopCnt() > 0 && march2.getTroopCnt() > 0) {
            // Initialize turn values
            double m1Attack = 0, m1Counter = 0, m1SkillDmg = 0, 
                   m2Attack = 0, m2Counter = 0, m2SkillDmg = 0;    
        
            // Add base rage generated from this turn
            march1.addRage(102);
            march2.addRage(102);

            // Calculate attacks and counters
            m1Attack = march1.calcAttack() / march2.calcDefense();
            m2Counter = march2.calcCounterAtk() / march1.calcDefense();
            m2Attack = march2.calcAttack() / march1.calcDefense();
            m1Counter = march1.calcCounterAtk() / march2.calcDefense();

            // Check for active skill activation
            if (march1.getRage() >= 1000) {
                m1SkillDmg = march1.calcDirectDmg(1) / march2.calcDefense();
                march1.setRage(0);
            }
            if (march2.getRage() >= 1000) {
                m2SkillDmg = march2.calcDirectDmg(1) / march1.calcDefense();
                march2.setRage(0);
            }

            // Apply dmg reductions 
            m1Attack = march2.applyNormDmgReduction(m1Attack);
            m2Attack = march1.applyNormDmgReduction(m2Attack);
            m1Counter = march2.applyCntrDmgReduction(m1Counter);
            m2Counter = march1.applyCntrDmgReduction(m2Counter);
            m1SkillDmg = march2.applySkillDmgReduction(m1SkillDmg);
            m2SkillDmg = march1.applySkillDmgReduction(m2SkillDmg);
            
            // Apply troop advantage bonus 
            if (march1.getTroop().getTroopType() != march2.getTroop().getTroopType()) {
                if((march1.getTroop().getTroopType() == TroopType.INF && march2.getTroop().getTroopType() == TroopType.CAV)
                    || (march1.getTroop().getTroopType() == TroopType.CAV && march2.getTroop().getTroopType() == TroopType.ARCH)
                    || (march1.getTroop().getTroopType() == TroopType.ARCH && march2.getTroop().getTroopType() == TroopType.INF)) {
                    m1Attack *= 1.05;
                    m1Counter *= 1.05;
                    m1SkillDmg *= 1.05;
                    m2Attack *= 0.95;
                    m2Counter *= 0.95;
                    m2SkillDmg *= 0.95;
                } else {
                    m1Attack *= 0.95;
                    m1Counter *= 0.95;
                    m1SkillDmg *= 0.95;
                    m2Attack *= 1.05;
                    m2Counter *= 1.05;
                    m2SkillDmg *= 1.05;
                }
            }

            // Apply rage compensation
            if (m1Attack < m2Counter) {march1.addRage(10);}
            if (m2Attack < m1Counter) {march2.addRage(10);}

            // Activate temporary buffs for next turn
            for (TemporaryBuff tempBuff : march1.getTempBuffsList()) {
                if (tempBuff.getCooldownEndTurn() < turn) {
                    if (tempBuff.getTerminationTurn() == 0) {
                        if (Math.random() <= tempBuff.getProbability()) {
                            tempBuff.setTerminationTurn(turn + tempBuff.getDuration());
                            march1.addTempBuff(tempBuff);
                        }
                    } else if (turn == tempBuff.getTerminationTurn()) {
                        tempBuff.setTerminationTurn(0);
                        tempBuff.setCooldownEndTurn(turn + tempBuff.getCooldown());
                        march1.removeTempBuff(tempBuff);
                    }
                }
            }
            for (TemporaryBuff tempBuff : march2.getTempBuffsList()) {
                if (tempBuff.getCooldownEndTurn() < turn) {
                    if (tempBuff.getTerminationTurn() == 0) {
                        if (Math.random() <= tempBuff.getProbability()) {
                            tempBuff.setTerminationTurn(turn + tempBuff.getDuration());
                            march2.addTempBuff(tempBuff);
                        }
                    } else if (turn == tempBuff.getTerminationTurn()) {
                        tempBuff.setTerminationTurn(0);
                        tempBuff.setCooldownEndTurn(turn + tempBuff.getCooldown());
                        march2.removeTempBuff(tempBuff);
                    }
                }
            }

            // Add turn results to the log
            log = log.append(Arrays.asList(Math.ceil(m1Attack), Math.ceil(m1Counter), Math.ceil(m1SkillDmg), march1.getRage(), march1.getTroopCnt(), 
                                            Math.ceil(m2Attack), Math.ceil(m2Counter), Math.ceil(m2SkillDmg), march2.getRage(), march2.getTroopCnt()));

            // Apply losses to each march
            march1.applyLoss(Math.ceil(m2Attack) + Math.ceil(m2Counter) + Math.ceil(m2SkillDmg));
            march2.applyLoss(Math.ceil(m1Attack) + Math.ceil(m1Counter) + Math.ceil(m1SkillDmg));

            turn++;
        }
    }


}
