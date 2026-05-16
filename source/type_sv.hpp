#pragma once

#include<string_view>

#include"type.hpp"
#include"enum_value.hpp"

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

}//namespace pokemon
