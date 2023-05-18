package shrunken.rokcc.sim;

import java.io.File;
import java.io.IOException;
import java.util.List;

import com.fasterxml.jackson.databind.ObjectMapper;

public class Commander {
    private int rageRequirement;
    private List<SkillComponent> active;
    private List<SkillComponent> passive1;
    private List<SkillComponent> passive2;
    private List<SkillComponent> passive3;
    private List<SkillComponent> expertise;

    private Buffs buffs;
    private String name;
    private int[] skillLevels;

    public static Commander loadFromJson(String name, int[] skillLevels) {
        ObjectMapper mapper = new ObjectMapper();
        String path = "~/rokcc/data/" + name + ".json";
        try {
            return mapper.readValue(new File(path), Commander.class);
        } catch (IOException e) {
            e.printStackTrace();
            return null;
        }
    }

    public String getName() {return this.name;}
    public double getRageReq() {return this.rageRequirement;}
    public Buffs getBuffs() {return this.buffs;}
}
