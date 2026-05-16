#pragma once

#include<vector>
#include<set>
#include<tuple>

#include"enum_value.hpp"
#include"gen.hpp"
#include"type.hpp"
#include"type_count.hpp"
#include"type_chart.hpp"
#include"type_matchup.hpp"

namespace pokemon{

std::tuple<std::set<Type>,std::vector<TypeMatchup>>
get_super_effectives(Gen gen,std::set<Type>const& types){
    unsigned char type_count=enum_value(gen_to_type_count(gen));
    std::set<Type> ret_types={};
    std::vector<TypeMatchup> ret_matchups={};
    TypeMatchup matchup={};
    for(unsigned char index=0;index<type_count;++index){
        for(auto const& type:types){
            matchup.attack_type=type;
            matchup.defense_type={static_cast<Type>(index)};
            matchup.multiplier=type_chart::at(
                gen,
                matchup.attack_type,
                *(matchup.defense_type.cbegin())
            );
            if(matchup.multiplier>1){
                ret_types.emplace(*(matchup.defense_type.cbegin()));
                ret_matchups.emplace_back(matchup);
            }
        }
    }
    return {ret_types,ret_matchups};
}

}//namespace pokemon
