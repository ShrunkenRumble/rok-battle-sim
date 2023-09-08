package shrunken.rokcc.sim;

import java.util.ArrayList;
import java.util.HashMap;
import joinery.DataFrame;

import shrunken.rokcc.sim.troop.TroopType;

public class Battle {
    private March march1;
    private March march2;
    private ArrayList<HashMap<String, Double>> log;
    
    public Battle(March march1, March march2) {
        this.march1 = march1;
        this.march2 = march2;
        this.log = new ArrayList<>();
    }

    public ArrayList<HashMap<String, Double>> getLog() {return this.log;}

    public void run() {
        while (march1.getTroopCnt() > 0 && march2.getTroopCnt() > 0) {
            boolean m1SkillFired = false, m2SkillFired = false;
            HashMap<String, Double> turnLog = new HashMap<>(0, 0);

            // Initialize turn values
            turnLog.put("m1-attack", 0.0);
            turnLog.put("m1-counter", 0.0);
            turnLog.put("m1-skill-dmg", 0.0);
            turnLog.put("m2-attack", 0.0);
            turnLog.put("m2-counter", 0.0);
            turnLog.put("m2-skill-dmg", 0.0);
            turnLog.put("m1-rage",0.0);
            turnLog.put("m2-rage",0.0);
            turnLog.put("m1-troop-cnt", march1.getTroopCnt());
            turnLog.put("m2-troop-cnt", march2.getTroopCnt());
            
            // Add base rage generated from this turn
            march1.addRage(102);
            march2.addRage(102);

            // Calculate attacks and counters
            turnLog.put("m1-attack", march1.calcAttack() / march2.calcDefense());
            turnLog.put("m2-counter", march2.calcCounterAtk() / march1.calcDefense());
            turnLog.put("m2-attack", march2.calcAttack() / march1.calcDefense());
            turnLog.put("m1-counter", march1.calcCounterAtk() / march2.calcDefense());
            
            // Check for active skill activation
            if (march1.getRage() >= 1000) {
                turnLog.put("m1-skill-dmg", march1.calcPrimDirectDmg() / march2.calcDefense());
                march1.setRage(0);
            }
            if (march2.getRage() >= 1000) {
                turnLog.put("m1-skill-dmg", march2.calcPrimDirectDmg() / march1.calcDefense());
                march2.setRage(0);
            }

            // Apply dmg reductions 
            turnLog.put("m1-counter", march2.applyCntrDmgReduction(turnLog.get("m1-counter")));
            turnLog.put("m2-counter", march1.applyCntrDmgReduction(turnLog.get("m2-counter")));
            turnLog.put("m1-skill-dmg", march2.applySkillDmgReduction(turnLog.get("m1-attack")));
            turnLog.put("m2-skill-dmg", march1.applySkillDmgReduction(turnLog.get("m2-attack")));
            
            // Apply troop advantage bonus 
            if (march1.getTroop().getTroopType() != march2.getTroop().getTroopType()) {
                if((march1.getTroop().getTroopType() == TroopType.INF && march2.getTroop().getTroopType() == TroopType.CAV)
                    || (march1.getTroop().getTroopType() == TroopType.CAV && march2.getTroop().getTroopType() == TroopType.ARCH)
                    || (march1.getTroop().getTroopType() == TroopType.ARCH && march2.getTroop().getTroopType() == TroopType.INF)) {
                    
                    turnLog.put("m1-attack", turnLog.get("m1-attack")*1.05);
                    turnLog.put("m1-counter", turnLog.get("m1-counter")*1.05);
                    turnLog.put("m1-skill-dmg", turnLog.get("m1-skill-dmg")*1.05);
                    turnLog.put("m2-attack", turnLog.get("m2-attack")*0.95);
                    turnLog.put("m2-counter", turnLog.get("m2-counter")*0.95);
                    turnLog.put("m2-skill-dmg", turnLog.get("m2-skill-dmg")*0.95);
                } else {
                    turnLog.put("m2-attack", turnLog.get("m2-attack")*1.05);
                    turnLog.put("m2-counter", turnLog.get("m2-counter")*1.05);
                    turnLog.put("m2-skill-dmg", turnLog.get("m2-skill-dmg")*1.05);
                    turnLog.put("m1-attack", turnLog.get("m1-attack")*0.95);
                    turnLog.put("m1-counter", turnLog.get("m1-counter")*0.95);
                    turnLog.put("m1-skill-dmg", turnLog.get("m1-skill-dmg")*0.95);
                }
            }

            // Apply rage compensation
            if (turnLog.get("m1-attack") < turnLog.get("m2-counter")) {march1.addRage(10);}
            if (turnLog.get("m2-attack") < turnLog.get("m1-counter")) {march2.addRage(10);}

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

            // Add turn to battle log
            log.add(turnLog);
        }
    }


}
