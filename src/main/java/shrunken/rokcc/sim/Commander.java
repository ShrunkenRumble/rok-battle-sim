package shrunken.rokcc.sim;

import java.io.IOException;
import java.util.List;
import java.util.stream.IntStream;
import java.io.InputStream;
import com.fasterxml.jackson.annotation.JsonIgnore;
import com.fasterxml.jackson.databind.ObjectMapper;

import shrunken.rokcc.sim.buff.BuffSet;
import shrunken.rokcc.sim.buff.SkillComponent;

public class Commander {
    @JsonIgnore
    private BuffSet buffSet;
    @JsonIgnore
    private String name;
    @JsonIgnore
    private int[] skillLevels;
    @JsonIgnore
    private boolean isExpertised;

    private int rageRequirement;
    private List<SkillComponent> active;
    private List<SkillComponent> passive1;
    private List<SkillComponent> passive2;
    private List<SkillComponent> passive3;
    private List<SkillComponent> expertise;

    // Getters
    public String getName() {return this.name;}
    public double getRageRequirement() {return this.rageRequirement;}
    public BuffSet getBuffSet() {return this.buffSet;}
    public int[] getSkillLevels() {return this.skillLevels;}
    public List<SkillComponent> getActive() {return this.active;}
    public List<SkillComponent> getPassive1() {return this.passive1;}
    public List<SkillComponent> getPassive2() {return this.passive2;}
    public List<SkillComponent> getPassive3() {return this.passive3;}
    public List<SkillComponent> getExpertise() {return this.expertise;}
    public boolean getIsExpertised() {return this.isExpertised;}

    // Setters
    public void setName(String name) {this.name = name;}
    public void setRageRequirement(int rageRequirement) {this.rageRequirement = rageRequirement;}
    public void setBuffSet(BuffSet buffSet) {this.buffSet = buffSet;}
    public void setSkillLevels(int[] skillLevels) {this.skillLevels = skillLevels;}
    public void setActive(List<SkillComponent> active) {this.active = active;}
    public void setPassive1(List<SkillComponent> passive1) {this.passive1 = passive1;}
    public void setPassive2(List<SkillComponent> passive2) {this.passive2 = passive2;}
    public void setPassive3(List<SkillComponent> passive3) {this.passive3 = passive3;}
    public void setExpertise(List<SkillComponent> expertise) {this.expertise = expertise;}
    public void setIsExpertised(boolean isExpertised) {this.isExpertised = isExpertised;}

    // Used to initialize Commander class
    public static Commander loadFromJson(String name, int[] skillLevels) {
        String path = "/" + name + ".json";
        ObjectMapper mapper = new ObjectMapper();
        InputStream dataStream = Commander.class.getResourceAsStream(path);
        
        try {    
            Commander commander = mapper.readValue(dataStream, Commander.class);
            if (commander != null) {
                commander.setName(name);
                commander.setSkillLevels(skillLevels);
                if (IntStream.of(skillLevels).sum() == 20) {
                    commander.setIsExpertised(true);
                } else {
                    commander.setIsExpertised(false);
                }
                commander.setBuffSet(createBuffset(commander));
            }
            return commander;
        } catch (IOException e) {
            e.printStackTrace();
            return null;
        }
    }

    // Used to populate buffSet with the permanent buffs from the skill components
    private static BuffSet createBuffset(Commander commander) {
        BuffSet buffSet = new BuffSet();
        if (commander.getPassive1() != null) {
            if (commander.getSkillLevels()[1] >= 1){
                for (SkillComponent comp : commander.getPassive1()) {
                    if (comp.getDuration() == 0) {
                        buffSet.addBuff(comp.toBuff(commander.skillLevels[1]-1));
                    }
                }
            }
        }
        if (commander.getPassive2() != null) {
            if (commander.getSkillLevels()[2] >= 1) {
                for (SkillComponent comp : commander.getPassive2()) {
                    if (comp.getDuration() == 0) {
                        buffSet.addBuff(comp.toBuff(commander.skillLevels[2]-1));
                    }
                }
            }
        }
        if (commander.getPassive3() != null) {
            if (commander.getSkillLevels()[3] >= 1) {
                for (SkillComponent comp : commander.getPassive3()) {
                    if (comp.getDuration() == 0) {
                        buffSet.addBuff(comp.toBuff(commander.skillLevels[3]-1));
                    }
                }
            }
        }
        if (commander.getExpertise() != null) {
            if (commander.getIsExpertised()) {
                for (SkillComponent comp : commander.getExpertise()) {
                    if (comp.getDuration() == 0) {
                        buffSet.addBuff(comp.toBuff(0));
                    }
                }
            }
        }
        return buffSet;
    }
}
