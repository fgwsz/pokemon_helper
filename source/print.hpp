#pragma once

#include<cstddef>
#include<vector>
#include<tuple>
#include<set>
#include<functional>

#include"what.hpp"
#include"gen.hpp"
#include"type.hpp"
#include"type_sv.hpp"
#include"type_matchup.hpp"
#include"get_recommend_info.hpp"

namespace pokemon{

template<typename OutputStream>
OutputStream& operator<<(OutputStream& os,Gen gen){
    if(gen==Gen::_1){
        os<<"gen 1";
    }else if(gen==Gen::_2_5){
        os<<"gen 2~5";
    }else if(gen==Gen::_6){
        os<<"gen 6^";
    }else{
        throw what("unknown gen");
    }
    return os;
}

template<typename OutputStream>
OutputStream& operator<<(OutputStream& os,Type type){
    os<<type_to_type_sv(type);
    return os;
}

template<typename OutputStream>
OutputStream& operator<<(OutputStream& os,std::set<Type>const& types){
    if(types.size()==1){
        os<<*(types.cbegin());
        return os;
    }
    os<<"[";
    std::size_t index=0;
    for(auto const& type:types){
        os<<type;
        if(index+1!=types.size()){
            os<<", ";
        }
        ++index;
    }
    os<<"]";
    return os;
}

template<typename OutputStream>
OutputStream& operator<<(OutputStream& os,TypeMatchup const& type_matchup){
    os<<"`"<<type_matchup.attack_type<<"->"<<type_matchup.defense_type<<":"
        <<type_matchup.multiplier<<"`";
    return os;
}

template<typename OutputStream>
OutputStream& operator<<(
    OutputStream& os,
    std::vector<TypeMatchup>const& type_matchups
){
    if(type_matchups.size()==1){
        os<<type_matchups[0];
        return os;
    }
    os<<"[";
    std::size_t index=0;
    for(auto const& type_matchup:type_matchups){
        os<<type_matchup;
        if(index+1!=type_matchups.size()){
            os<<", ";
        }
        ++index;
    }
    os<<"]";
    return os;
}

template<typename OutputStream>
OutputStream& operator<<(
    OutputStream& os,
    std::tuple<std::set<Type>,std::vector<TypeMatchup>>const& tuple
){
    os<<"(\n    "<<std::get<0>(tuple)<<",\n    "<<std::get<1>(tuple)<<"\n)";
    return os;
}

template<typename OutputStream>
OutputStream& operator<<(
    OutputStream& os,
    RecommendInfoEntry const& info_entry
){
    os<<info_entry.type<<": {\n"
        <<"    coverage gaps: "<<info_entry.coverage_gaps<<'\n';
    if(!info_entry.coverage_gap_super_matchups.empty()){
        os<<"    super matchups: "
            <<info_entry.coverage_gap_super_matchups<<'\n';
    }
    if(!info_entry.weaknesses.empty()){
        os<<"    weaknesses: "<<info_entry.weaknesses<<'\n';
    }
    if(!info_entry.weakness_super_matchups.empty()){
        os<<"    super matchups: "<<info_entry.weakness_super_matchups<<'\n';
    }
    os<<"}";
    return os;
}

template<typename OutputStream>
OutputStream& operator<<(
    OutputStream& os,
    std::set<RecommendInfoEntry,std::greater<RecommendInfoEntry>> const& info
){
    std::size_t rank=1;
    for(auto const& info_entry:info){
        os<<rank<<". "<<info_entry<<'\n';
        ++rank;
    }
    return os;
}

}//namespace pokemon
