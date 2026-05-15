#pragma once

#include<vector>

#include"enum_value.hpp"
#include"gen.hpp"
#include"type.hpp"
#include"type_count.hpp"
#include"type_chart.hpp"
#include"type_matchup.hpp"

namespace pokemon{

std::vector<TypeMatchup> get_weaknesses(Gen gen,Type type){
    std::vector<TypeMatchup> ret={};
    TypeMatchup matchup={};
    for(
        unsigned char index=0;
        index<enum_value(gen_to_type_count(gen));
        ++index
    ){
        matchup.attack_type=static_cast<Type>(index);
        matchup.defense_type={{type}};
        matchup.multiplier=type_chart::at(
            gen,
            matchup.attack_type,
            matchup.defense_type[0]
        );
        if(matchup.multiplier>1){
            ret.emplace_back(matchup);
        }
    }
    return ret;
}

std::vector<TypeMatchup> get_weaknesses(Gen gen,Type type_1,Type type_2){
    if(type_1==type_2){
        return get_weaknesses(gen,type_1);
    }
    std::vector<TypeMatchup> ret={};
    TypeMatchup matchup={};
    for(
        unsigned char index=0;
        index<enum_value(gen_to_type_count(gen));
        ++index
    ){
        matchup.attack_type=static_cast<Type>(index);
        matchup.defense_type={{type_1,type_2}};
        matchup.multiplier=
            type_chart::at(gen,matchup.attack_type,type_1)
            *type_chart::at(gen,matchup.attack_type,type_2)
        ;
        if(matchup.multiplier>1){
            ret.emplace_back(matchup);
        }
    }
    return ret;
}

}//namespace pokemon
