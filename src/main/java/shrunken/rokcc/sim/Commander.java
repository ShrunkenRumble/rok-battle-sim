package shrunken.rokcc.sim;

import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
import java.util.stream.IntStream;
import java.io.InputStream;
import com.fasterxml.jackson.annotation.JsonIgnore;
import com.fasterxml.jackson.databind.ObjectMapper;

import shrunken.rokcc.sim.buff.BuffSet;
import shrunken.rokcc.sim.buff.SkillComponent;
import shrunken.rokcc.sim.buff.TemporaryBuff;

public class Commander {
    @JsonIgnore
    private BuffSet buffSet;
    @JsonIgnore
    private String name;
    @JsonIgnore
    private int[] skillLevels;
    @JsonIgnore
    private boolean isExpertised;
    @JsonIgnore
    private List<TemporaryBuff> tempBuffList;

    private int rageRequirement;
    private List<SkillComponent> active;
    private List<SkillComponent> skill2;
    private List<SkillComponent> skill3;
    private List<SkillComponent> skill4;
    private List<SkillComponent> expertise;

    // Getters
    public String getName() {return this.name;}
    public double getRageRequirement() {return this.rageRequirement;}
    public BuffSet getBuffSet() {return this.buffSet;}
    public int[] getSkillLevels() {return this.skillLevels;}
    public List<SkillComponent> getActive() {return this.active;}
    public List<SkillComponent> getSkill2() {return this.skill2;}
    public List<SkillComponent> getSkill3() {return this.skill3;}
    public List<SkillComponent> getSkill4() {return this.skill4;}
    public List<SkillComponent> getExpertise() {return this.expertise;}
    public List<TemporaryBuff> getTempBuffList() {return this.tempBuffList;}
    public boolean getIsExpertised() {return this.isExpertised;}

    // Setters
    public void setName(String name) {this.name = name;}
    public void setRageRequirement(int rageRequirement) {this.rageRequirement = rageRequirement;}
    public void setBuffSet(BuffSet buffSet) {this.buffSet = buffSet;}
    public void setSkillLevels(int[] skillLevels) {this.skillLevels = skillLevels;}
    public void setActive(List<SkillComponent> active) {this.active = active;}
    public void setSkill2(List<SkillComponent> skill2) {this.skill2 = skill2;}
    public void setSkill3(List<SkillComponent> skill3) {this.skill3 = skill3;}
    public void setSkill4(List<SkillComponent> skill4) {this.skill4 = skill4;}
    public void setExpertise(List<SkillComponent> expertise) {this.expertise = expertise;}
    public void setIsExpertised(boolean isExpertised) {this.isExpertised = isExpertised;}
    public void setTempBuffList(List<TemporaryBuff> tempBuffList) {this.tempBuffList = tempBuffList;}

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
                commander.setTempBuffList(createTempBuffList(commander));
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
        if (commander.getSkill2() != null) {
            if (commander.getSkillLevels()[1] >= 1) {
                for (SkillComponent comp : commander.getSkill2()) {
                    if (comp.getDuration() == 0) {
                        buffSet.addBuff(comp.toBuff(commander.skillLevels[1]-1));
                    } 
                }
            }
        }
        if (commander.getSkill3() != null) {
            if (commander.getSkillLevels()[2] >= 1) {
                for (SkillComponent comp : commander.getSkill3()) {
                    if (comp.getDuration() == 0) {
                        buffSet.addBuff(comp.toBuff(commander.skillLevels[2]-1));
                    }
                }
            }
        }
        if (commander.getSkill4() != null) {
            if (commander.getSkillLevels()[3] >= 1) {
                for (SkillComponent comp : commander.getSkill4()) {
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

    private static List<TemporaryBuff> createTempBuffList(Commander commander) {
        List<TemporaryBuff> tempBuffList = new ArrayList<TemporaryBuff>();
        if (commander.getSkill2() != null) {
            if (commander.getSkillLevels()[1] >= 1) {
                for (SkillComponent comp : commander.getSkill2()) {
                    if (comp.getDuration() > 0) {
                        tempBuffList.add(comp.toTempBuff(commander.skillLevels[1]-1));
                    } 
                }
            }
        }
        if (commander.getSkill3() != null) {
            if (commander.getSkillLevels()[2] >= 1) {
                for (SkillComponent comp : commander.getSkill3()) {
                    if (comp.getDuration() > 0) {
                        tempBuffList.add(comp.toTempBuff(commander.skillLevels[2]-1));
                    }
                }
            }
        }
        if (commander.getSkill4() != null) {
            if (commander.getSkillLevels()[3] >= 1) {
                for (SkillComponent comp : commander.getSkill4()) {
                    if (comp.getDuration() > 0) {
                        tempBuffList.add(comp.toTempBuff(commander.skillLevels[3]-1));
                    }
                }
            }
        }
        if (commander.getExpertise() != null) {
            if (commander.getIsExpertised()) {
                for (SkillComponent comp : commander.getExpertise()) {
                    if (comp.getDuration() > 0) {
                        tempBuffList.add(comp.toTempBuff(0));
                    }
                }
            }
        }
        return tempBuffList;
    }
}
