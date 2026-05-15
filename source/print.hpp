#pragma once

#include<cstddef>
#include<vector>

#include"what.hpp"
#include"gen.hpp"
#include"type.hpp"
#include"type_sv.hpp"
#include"type_matchup.hpp"

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
OutputStream& operator<<(OutputStream& os,std::vector<Type>const& types){
    if(types.size()==1){
        os<<types[0];
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

}//namespace pokemon
