#include "Commander.h"

vector<SkillComponent> parseSkill(json data, string skill_name, int skill_lvl, map<string, double> *buffs) {
    vector<SkillComponent> skill;
        
    for (auto comp_iter : data[skill_name]) {
        SkillComponent comp = SkillComponent();

        comp.setType(comp_iter["type"].get<string>());
        comp.setTroopType(strToTrp(comp_iter["trp_type"].get<string>().c_str()));
        comp.setTurnDuration(comp_iter["turn_dur"].get<double>());
        comp.setTurnInterval(comp_iter["turn_int"].get<double>());
        comp.setValue(comp_iter["value"][skill_lvl-1].get<double>());

        skill.push_back(comp);

        if (comp.getTurnDuration() == 0) {
            (*buffs)[comp.getType()] += comp.getValue();
        }
    }
    return skill;
}

Commander::Commander(string name, int skill_lvls[4]) {
    std::ifstream f("../data/" + name + ".json");
    json data = json::parse(f);
    map<string, double> buffs = map<string, double>();

    buffs["atk_bonus"] = 0;
    buffs["def_bonus"] = 0;
    buffs["hp_bonus"] = 0;
    buffs["counter_dmg_bonus"] = 0;
    buffs["normal_dmg_bonus"] = 0;
    buffs["skill_dmg_bonus"] = 0;
    buffs["all_dmg_bonus"] = 0;
    buffs["dmg_reduction"] = 0;
    buffs["counter_dmg_reduction"] = 0;
    buffs["normal_dmg_reduction"] = 0;
    buffs["skill_dmg_reduction"] = 0;

    this->name = name;
    this->rage_req = data["rage_req"];
    this->active_skill = parseSkill(data, "active", skill_lvls[0], &buffs);
    this->p1_skill = parseSkill(data, "passive_1", skill_lvls[1], &buffs);
    this->p2_skill = parseSkill(data, "passive_2", skill_lvls[2], &buffs);
    this->p3_skill = parseSkill(data, "passive_3", skill_lvls[3], &buffs);

    this->buffs = Buffs(buffs);
}

double Commander::getDirectDmgFac() {
    double dmg_factor = 0;

    for (auto comp : this->active_skill) {
        if (comp.getType() == "ddf") {
            dmg_factor += comp.getValue();
        }
    }

    return dmg_factor;
}
