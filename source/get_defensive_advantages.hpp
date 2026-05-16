#pragma once

#include<vector>
#include<set>
#include<tuple>

#include"what.hpp"
#include"enum_value.hpp"
#include"gen.hpp"
#include"type.hpp"
#include"type_count.hpp"
#include"type_chart.hpp"
#include"type_matchup.hpp"

namespace pokemon{

std::tuple<std::set<Type>,std::vector<TypeMatchup>>
get_defensive_advantages(Gen gen,std::set<Type>const& types){
    if(!(types.size()==1||types.size()==2)){
        throw what("unknown types");
    }
    std::set<Type> ret_types={};
    std::vector<TypeMatchup> ret_matchups={};
    TypeMatchup matchup={};
    for(
        unsigned char index=0;
        index<enum_value(gen_to_type_count(gen));
        ++index
    ){
        matchup.attack_type=static_cast<Type>(index);
        matchup.defense_type=types;
        matchup.multiplier=1;
        for(auto const& type:types){
            matchup.multiplier*=type_chart::at(gen,matchup.attack_type,type);
        }
        if(matchup.multiplier<1){
            ret_types.emplace(matchup.attack_type);
            ret_matchups.emplace_back(matchup);
        }
    }
    return {ret_types,ret_matchups};
}

}//namespace pokemon
