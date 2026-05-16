#pragma once

#include<set>

#include"type.hpp"

namespace pokemon{

struct TypeMatchup{
    Type attack_type;
    std::set<Type> defense_type;
    float multiplier;
};

}//namespace pokemon
