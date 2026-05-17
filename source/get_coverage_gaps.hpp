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
get_coverage_gaps(Gen gen,std::set<Type>const& types){
    unsigned char type_count=enum_value(gen_to_type_count(gen));
    std::vector<unsigned char> map(type_count,0);//=0未覆盖,=1已覆盖
    for(auto const& type:types){
        for(unsigned char index=0;index<type_count;++index){
            if(
                map[index]==0
                &&type_chart::at(gen,type,make_type(index))>=1
            ){
                map[index]=1;
            }
        }
    }
    std::set<Type> ret_types={};
    std::vector<TypeMatchup> ret_matchups={};
    TypeMatchup matchup={};
    for(unsigned char index=0;index<type_count;++index){
        if(map[index]==0){
            for(auto const& type:types){
                matchup.set(gen,type,make_type(index));
                ret_types.emplace(matchup.get_first_defense_type());
                ret_matchups.emplace_back(matchup);
            }
        }
    }
    return {ret_types,ret_matchups};
}

}//namespace pokemon
