#pragma once

#include<string_view>

#include"type.hpp"
#include"enum_value.hpp"
#include"what.hpp"

namespace pokemon{

constexpr std::string_view type_sv_list[]={
    "Normal"  ,
    "Fighting",
    "Flying"  ,
    "Poison"  ,
    "Ground"  ,
    "Rock"    ,
    "Bug"     ,
    "Ghost"   ,
    "Fire"    ,
    "Water"   ,
    "Grass"   ,
    "Electric",
    "Psychic" ,
    "Ice"     ,
    "Dragon"  ,
    "Steel"   ,
    "Dark"    ,
    "Fairy"
};

constexpr std::string_view type_to_type_sv(Type type)noexcept{
    return type_sv_list[enum_value(type)];
}

Type type_sv_to_type(std::string_view sv){
    unsigned char index=0;
    for(auto const& type_sv:type_sv_list){
        if(sv==type_sv){
            return static_cast<Type>(index);
        }
        ++index;
    }
    throw what("unknown type");
}

}//namespace pokemon
