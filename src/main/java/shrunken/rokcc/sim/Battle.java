package shrunken.rokcc.sim;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import joinery.DataFrame;

import shrunken.rokcc.sim.troop.TroopType;

public class Battle {
    private March march1;
    private March march2;
    private DataFrame<Object> log;
    
    public Battle(March march1, March march2) {
        this.march1 = march1;
        this.march2 = march2;
        log = new DataFrame<>("m1-attack", "m1-counter", "m1-skill-dmg", "m1-rage", "m1-troop-cnt", 
                              "m2-attack", "m2-counter", "m2-skill-dmg", "m2-rage", "m2-troop-cnt");
    }

    public void run() {
        int turn = 0;
        while (march1.getTroopCnt() > 0 && march2.getTroopCnt() > 0) {
            //HashMap<String, Double> turnLog = new HashMap<>(0, 0);

            // Initialize turn values
            log = log.append(Arrays.asList(0, 0, 0, 0, march1.getTroopCnt(), 0, 0, 0, 0, march2.getTroopCnt()));
            
            // Add base rage generated from this turn
            march1.addRage(102);
            march2.addRage(102);

            // Calculate attacks and counters
            log.set(turn, "m1-attack", march1.calcAttack() / march2.calcDefense());
            log.set(turn, "m2-counter", march2.calcCounterAtk() / march1.calcDefense());
            log.set(turn, "m2-attack", march2.calcAttack() / march1.calcDefense());
            log.set(turn, "m1-counter", march1.calcCounterAtk() / march2.calcDefense());

            // Check for active skill activation
            if (march1.getRage() >= 1000) {
                log.set(turn, "m1-skill-dmg", march1.calcPrimDirectDmg() / march2.calcDefense());
                march1.setRage(0);
            }
            if (march2.getRage() >= 1000) {
                log.set(turn, "m2-skill-dmg", march2.calcPrimDirectDmg() / march1.calcDefense());
                march2.setRage(0);
            }

            // Apply dmg reductions 
            log.set(turn, "m1-counter", march2.applyCntrDmgReduction((double) log.get(turn, "m1-counter")));
            log.set(turn, "m2-counter", march1.applyCntrDmgReduction((double) log.get(turn, "m2-counter")));
            log.set(turn, "m1-skill-dmg", march2.applySkillDmgReduction((double) log.get(turn, "m1-skill-dmg")));
            log.set(turn, "m2-skill-dmg", march1.applySkillDmgReduction((double) log.get(turn, "m2-skill-dmg")));
            
            // Apply troop advantage bonus 
            if (march1.getTroop().getTroopType() != march2.getTroop().getTroopType()) {
                if((march1.getTroop().getTroopType() == TroopType.INF && march2.getTroop().getTroopType() == TroopType.CAV)
                    || (march1.getTroop().getTroopType() == TroopType.CAV && march2.getTroop().getTroopType() == TroopType.ARCH)
                    || (march1.getTroop().getTroopType() == TroopType.ARCH && march2.getTroop().getTroopType() == TroopType.INF)) {
                    
                    log.set(turn, "m1-attack", (double) log.get(turn, "m1-attack") * 1.05);
                    log.set(turn, "m1-counter", (double) log.get(turn, "m1-counter") * 1.05);
                    log.set(turn, "m1-skill-dmg", (double) log.get(turn, "m1-skill-dmg") * 1.05);
                    log.set(turn, "m2-attack", (double) log.get(turn, "m2-attack") * 0.95);
                    log.set(turn, "m2-counter", (double) log.get(turn, "m2-counter") * 0.95);
                    log.set(turn, "m2-skill-dmg", (double) log.get(turn, "m2-skill-dmg") * 0.95);
                } else {
                    log.set(turn, "m1-attack", (double) log.get(turn, "m1-attack") * 0.95);
                    log.set(turn, "m1-counter", (double) log.get(turn, "m1-counter") * 0.95);
                    log.set(turn, "m1-skill-dmg", (double) log.get(turn, "m1-skill-dmg") * 0.95);
                    log.set(turn, "m2-attack", (double) log.get(turn, "m2-attack") * 1.05);
                    log.set(turn, "m2-counter", (double) log.get(turn, "m2-counter") * 1.05);
                    log.set(turn, "m2-skill-dmg", (double) log.get(turn, "m2-skill-dmg") * 1.05);
                }
            }

            // Apply rage compensation
            if ((double) log.get(turn, "m1-attack") < (double) log.get(turn, "m2-counter")) {march1.addRage(10);}
            if ((double) log.get(turn, "m2-attack") < (double) log.get(turn, "m1-counter")) {march2.addRage(10);}

            // Apply temporary buffs for next turn

            // Apply ceiling function to every value
            turnLog.put("m1-attack", Math.ceil(turnLog.get("m1-attack")));
            turnLog.put("m1-counter", Math.ceil(turnLog.get("m1-counter")));
            turnLog.put("m1-skill-dmg", Math.ceil(turnLog.get("m1-skill-dmg")));
            turnLog.put("m2-attack", Math.ceil(turnLog.get("m2-attack")));
            turnLog.put("m2-counter", Math.ceil(turnLog.get("m2-counter")));
            turnLog.put("m2-skill-dmg", Math.ceil(turnLog.get("m2-skill-dmg")));

            // Apply losses to each march
            march1.applyLoss(turnLog.get("m2-attack") + turnLog.get("m2-counter") + turnLog.get("m2-skill-dmg"));
            march2.applyLoss(turnLog.get("m1-attack") + turnLog.get("m1-counter") + turnLog.get("m1-skill-dmg"));

            // Log total rage generated
            turnLog.put("m1-rage", march1.getRage());
            turnLog.put("m2-rage", march2.getRage());

            turn++;
        }
    }


}
