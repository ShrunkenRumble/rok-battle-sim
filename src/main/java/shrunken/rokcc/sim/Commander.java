package shrunken.rokcc.sim;

import java.io.IOException;
import java.util.List;
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

    // Use to initialize Commander class
    public static Commander loadFromJson(String name, int[] skillLevels) {
        String path = "/" + name + ".json";
        ObjectMapper mapper = new ObjectMapper();
        InputStream dataStream = Commander.class.getResourceAsStream(path);
        
        try {    
            Commander commander = mapper.readValue(dataStream, Commander.class);
            if (commander != null) {
                commander.setName(name);
                commander.setSkillLevels(skillLevels);
            }
            return commander;
        } catch (IOException e) {
            e.printStackTrace();
            return null;
        }
    }
}
