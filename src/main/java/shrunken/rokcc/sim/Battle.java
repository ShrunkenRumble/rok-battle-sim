package shrunken.rokcc.sim;

import java.util.ArrayList;
import java.util.HashMap;

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
            turnLog.put("m1-attack", 0.0);
            turnLog.put("m1-counter", 0.0);
            turnLog.put("m1-skill dmg", 0.0);
            turnLog.put("m2-attack", 0.0);
            turnLog.put("m2-counter", 0.0);
            turnLog.put("m2-skill-dmg", 0.0);
            turnLog.put("m1-rage",0.0);
            turnLog.put("m2-rage",0.0);
            turnLog.put("m1-troop-cnt",0.0);
            turnLog.put("m2-troop-cnt",0.0);
            
            march1.addRage(102);
            march2.addRage(102);

            turnLog.put("m1-attack", march1.calcAttack() / march2.calcDefense());
            turnLog.put("m2-counter", march2.calcCounterAtk() / march1.calcDefense());
            turnLog.put("m2-attack", march2.calcAttack() / march1.calcDefense());
            turnLog.put("m1-counter", march1.calcCounterAtk() / march2.calcDefense());
            
            if (march1.getRage() >= 1000) {
                turnLog.put("m1-skill-dmg", march1.calcPrimDirectDmg() / march2.calcDefense());
                march1.setRage(0);
            }
            if (march2.getRage() >= 1000) {
                turnLog.put("m1-skill-dmg", march2.calcPrimDirectDmg() / march1.calcDefense());
                march2.setRage(0);
            }

            
        }
    }


}
