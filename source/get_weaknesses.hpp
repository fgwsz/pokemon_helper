#pragma once

#include<vector>

#include"enum_value.hpp"
#include"gen.hpp"
#include"type.hpp"
#include"type_count.hpp"
#include"type_chart.hpp"

namespace pokemon{

std::vector<Type> get_weaknesses(Gen gen,Type type){
    std::vector<Type> ret={};
    for(
        unsigned char index=0;
        index<enum_value(gen_to_type_count(gen));
        ++index
    ){
        if(type_chart::at(gen,static_cast<Type>(index),type)>1){
            ret.emplace_back(static_cast<Type>(index));
        }
    }
    return ret;
}

std::vector<Type> get_weaknesses(Gen gen,Type type_1,Type type_2){
    if(type_1==type_2){
        return get_weaknesses(gen,type_1);
    }
    std::vector<Type> ret={};
    for(
        unsigned char index=0;
        index<enum_value(gen_to_type_count(gen));
        ++index
    ){
        if(
            type_chart::at(gen,static_cast<Type>(index),type_1)
            *type_chart::at(gen,static_cast<Type>(index),type_2)
            >1
        ){
            ret.emplace_back(static_cast<Type>(index));
        }
    }
    return ret;
}

}//namespace pokemon
