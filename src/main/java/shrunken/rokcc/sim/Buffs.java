package shrunken.rokcc.sim;
import java.util.HashMap;

public class Buffs {
    private double atk, def, hp;
    private double counterDmg, normalDmg, skillDmg, allDmg;
    private double dmgReduction, counterDmgReduction, normalDmgReduction, skillDmgReduction;

    public Buffs(double atk, double def, double hp,
        double counterDmg, double normalDmg, double skillDmg, double allDmg, 
        double dmgReduction, double counterDmgReduction, double normalDmgReduction, double skillDmgReduction) {
        this.atk = atk;
        this.def = def;
        this.hp = hp;
        this.counterDmg = counterDmg;
        this.normalDmg = normalDmg;
        this.skillDmg = skillDmg;
        this.allDmg = allDmg;
        this.dmgReduction = dmgReduction;
        this.counterDmgReduction = counterDmgReduction;
        this.normalDmgReduction = normalDmgReduction;
        this.skillDmgReduction = skillDmgReduction;
    }

    public Buffs(HashMap<String, Double> buffs) {
        this.atk = buffs.get("atk");
        this.def = buffs.get("def");
        this.hp = buffs.get("hp");
        this.counterDmg = buffs.get("counterDmg");
        this.normalDmg = buffs.get("normalDmg");
        this.skillDmg = buffs.get("skillDmg");
        this.allDmg = buffs.get("allDmg");
        this.dmgReduction = buffs.get("dmgReduction");
        this.counterDmgReduction = buffs.get("counterDmgReduction");
        this.normalDmgReduction = buffs.get("normalDmgReduction");
        this.skillDmgReduction = buffs.get("skillDmgReduction");
    }

    public double getAtk() {return this.atk;}
    public double getDef() {return this.def;}
    public double getHp() {return this.hp;}
    public double getCounterDmg() {return this.counterDmg;}
    public double getNormalDmg() {return this.normalDmg;}
    public double getSkillDmg() {return this.skillDmg;}
    public double getAllDmg() {return this.allDmg;}
    public double getDmgReduction() {return this.dmgReduction;}
    public double getCounterDmgReduction() {return this.counterDmgReduction;}
    public double getNormalDmgReduction() {return this.normalDmgReduction;}
    public double getSkillDmgReduction() {return this.skillDmgReduction;}

    public void addAtk(double atk) {this.atk += atk;}
    public void addDef(double def) {this.def += def;}
    public void addHp(double hp) {this.hp += hp;}
    public void addCounterDmg(double counterDmg) {this.counterDmg += counterDmg;}
    public void addNormalDmg(double normalDmg) {this.normalDmg += normalDmg;}
    public void addSkillDmg(double skillDmg) {this.skillDmg += skillDmg;}
    public void addAllDmg(double allDmg) {this.allDmg += allDmg;}
    public void addDmgReduction(double dmgReduction) {this.dmgReduction += dmgReduction;}
    public void addCounterDmgReduction(double counterDmgReduction) {this.counterDmgReduction += counterDmgReduction;}
    public void addNormalDmgReduction(double normalDmgReduction) {this.normalDmgReduction += normalDmgReduction;}
    public void addSkillDmgReduction(double skillDmgReduction) {this.skillDmgReduction += skillDmgReduction;}

    public void subtractAtk(double atk) {this.atk -= atk;}
    public void subtractDef(double def) {this.def -= def;}
    public void subtractHp(double hp) {this.hp -= hp;}
    public void subtractCounterDmg(double counterDmg) {this.counterDmg -= counterDmg;}
    public void subtractNormalDmg(double normalDmg) {this.normalDmg -= normalDmg;}
    public void subtractSkillDmg(double skillDmg) {this.skillDmg -= skillDmg;}
    public void subtractAllDmg(double allDmg) {this.allDmg -= allDmg;}
    public void subtractDmgReduction(double dmgReduction) {this.dmgReduction -= dmgReduction;}
    public void subtractCounterDmgReduction(double counterDmgReduction) {this.counterDmgReduction -= counterDmgReduction;}
    public void subtractNormalDmgReduction(double normalDmgReduction) {this.normalDmgReduction -= normalDmgReduction;}
    public void subtractSkillDmgReduction(double skillDmgReduction) {this.skillDmgReduction -= skillDmgReduction;}

    public void add(Buffs other) {
        this.atk = other.getAtk();
        this.def = other.getDef();
        this.hp = other.getHp();
        this.counterDmg = other.getCounterDmg();
        this.normalDmg = other.getNormalDmg();
        this.skillDmg = other.getSkillDmg();
        this.allDmg = other.getAllDmg();
        this.dmgReduction = other.getDmgReduction();
        this.counterDmgReduction = other.getCounterDmgReduction();
        this.normalDmgReduction = other.getNormalDmgReduction();
        this.skillDmgReduction = other.getSkillDmgReduction();
    }

}
