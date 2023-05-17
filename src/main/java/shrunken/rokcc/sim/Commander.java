package shrunken.rokcc.sim;

import java.util.ArrayList;
import org.json.simple.JSONArray;
import org.json.simple.JSONObject;
import org.json.simple.parser.JSONParser;
import org.json.simple.parser.ParseException;
import java.io.FileReader;
import java.io.IOException;
import java.io.Reader;
import java.util.Iterator;

public class Commander {
    private String name;
    private double rageRequirement;
    private ArrayList<ArrayList<SkillComponent>> skills;
    private Buffs buffs;
    private int[] skillLevels;

    public Commander(String name, int[] skillLevels) {
        this.name = name;
        this.skillLevels = skillLevels;

        JSONParser parser = new JSONParser();
        String jsonFileName = "~/rokcc/data/" + name + ".json";
        /* 
        try (Reader reader = new FileReader(jsonFileName)) {
            
            JSONObject jsonObject = (JSONObject) parser.parse(reader);
            System.out.println(jsonObject);
    
            String name = (String) jsonObject.get("name");
            System.out.println(name);
    
            long age = (Long) jsonObject.get("age");
            System.out.println(age);
    
            // loop array
            JSONArray msg = (JSONArray) jsonObject.get("messages");
            Iterator<String> iterator = msg.iterator();
            while (iterator.hasNext()) {
                System.out.println(iterator.next());
            }
    
        } catch (IOException e) {
            e.printStackTrace();
        } catch (ParseException e) {
            e.printStackTrace();
        }
        */
    }

    public String getName() {return this.name;}
    public double getRageReq() {return this.rageRequirement;}
    public Buffs getBuffs() {return this.buffs;}
}
