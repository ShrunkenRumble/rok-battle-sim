#ifndef TROOPTYPE_H_
#define TROOPTYPE_H_

#include <map>

enum TroopType {Infantry, Cavalry, Archers, None};

static TroopType strToTrp(const char *troop_type) {
    std::map<std::string,TroopType> const str_to_trp_table = {{"Infantry",TroopType::Infantry}, 
                                                                {"Cavalry",TroopType::Cavalry}, 
                                                                {"Archers",TroopType::Archers},
                                                                {"None",TroopType::None}};
    auto it = str_to_trp_table.find(troop_type);
    if (it != str_to_trp_table.end()) {
        return it->second;
    } else {
        return None;
    }
};

#endif