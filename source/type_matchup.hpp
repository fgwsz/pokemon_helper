#pragma once

#include<vector>

#include"type.hpp"

namespace pokemon{

struct TypeMatchup{
    Type attack_type;
    std::vector<Type> defense_type;
    float multiplier;
};

}//namespace pokemon
