package shrunken.rokcc.sim.buff;

import java.util.ArrayList;
import shrunken.rokcc.sim.troop.TroopType;

public class BuffSet {
    private ArrayList<Buff> buffs;

    public BuffSet() {
        this.buffs = new ArrayList<>();
    }

    public BuffSet(ArrayList<Buff> buffs) {
        this.buffs = buffs;
    }

    @Override
    public BuffSet clone() {
        return new BuffSet(this.getBuffs());
    }

    public void addBuff(Buff buff) {
        if (!(this.buffs.contains(buff))) {
            this.buffs.add(buff);
        } else {
            this.buffs.get(buffs.indexOf(buff)).plus(buff);
        }
    }

    public void removeBuff(Buff buff) {
        if (this.buffs.contains(buff)) {
            this.buffs.get(buffs.indexOf(buff)).minus(buff);
        } 
    }

    public ArrayList<Buff> getBuffs() {
        ArrayList<Buff> clone = new ArrayList<Buff>(this.buffs.size());
        for (Buff buff : this.buffs) clone.add(buff.clone());
        return clone;
    }

    public Buff getBuff(BuffType buffType, TroopType troopType) {
        Buff result = new Buff(buffType, troopType, false);
        int index = this.buffs.indexOf(result);
        if (index != -1) {
            double value = this.buffs.get(this.buffs.indexOf(result)).getValue();
            boolean isDebuff = this.buffs.get(this.buffs.indexOf(result)).getIsDebuff();
            result.setValue(value);
            result.setIsDebuff(isDebuff);
        }
        return result;
    }   

    public void plus(BuffSet buffSet2) {
        for (Buff buff2 : buffSet2.getBuffs()) {
            this.addBuff(buff2);
        }
    }

    public static BuffSet add(BuffSet buffSet1, BuffSet buffSet2) {
        BuffSet sum = buffSet1.clone();
        for (Buff buff2 : buffSet2.getBuffs()) {
            sum.addBuff(buff2);
        }
        return sum;
    }
}
