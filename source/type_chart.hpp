#pragma once

#include"enum_value.hpp"
#include"type_count.hpp"
#include"type.hpp"
#include"what.hpp"

namespace pokemon{

namespace type_chart{
constexpr float gen_1
    [enum_value(TypeCount::gen_1)]
    [enum_value(TypeCount::gen_1)]
={
//Atk\Def   ,   Normal,Fighting,  Flying,  Poison,  Ground,    Rock,     Bug,   Ghost,    Fire,   Water,   Grass,Electric, Psychic,     Ice,  Dragon
/*Normal  */{        1,       1,       1,       1,       1,     0.5,       1,       0,       1,       1,       1,       1,       1,       1,       1},
/*Fighting*/{        2,       1,     0.5,     0.5,       1,       2,     0.5,       0,       1,       1,       1,       1,     0.5,       2,       1},
/*Flying  */{        1,       2,       1,       1,       1,     0.5,       2,       1,       1,       1,       2,     0.5,       1,       1,       1},
/*Poison  */{        1,       1,       1,     0.5,     0.5,     0.5,       2,     0.5,       1,       1,       2,       1,       1,       1,       1},
/*Ground  */{        1,       1,       0,       2,       1,       2,     0.5,       1,       2,       1,     0.5,       2,       1,       1,       1},
/*Rock    */{        1,     0.5,       2,       1,     0.5,       1,       2,       1,       2,       1,       1,       1,       1,       2,       1},
/*Bug     */{        1,     0.5,     0.5,       2,       1,       1,       1,     0.5,     0.5,       1,       2,       1,       2,       1,       1},
/*Ghost   */{        0,       1,       1,       1,       1,       1,       1,       2,       1,       1,       1,       1,       0,       1,       1},
/*Fire    */{        1,       1,       1,       1,       1,     0.5,       2,       1,     0.5,     0.5,       2,       1,       1,       2,     0.5},
/*Water   */{        1,       1,       1,       1,       2,       2,       1,       1,       2,     0.5,     0.5,       1,       1,       1,     0.5},
/*Grass   */{        1,       1,     0.5,     0.5,       2,       2,     0.5,       1,     0.5,       2,     0.5,       1,       1,       1,     0.5},
/*Electric*/{        1,       1,       2,       1,       0,       1,       1,       1,       1,       2,     0.5,     0.5,       1,       1,     0.5},
/*Psychic */{        1,       2,       1,       2,       1,       1,       1,       1,       1,       1,       1,       1,     0.5,       1,       1},
/*Ice     */{        1,       1,       2,       1,       2,       1,       1,       1,       1,     0.5,       2,       1,       1,     0.5,       2},
/*Dragon  */{        1,       1,       1,       1,       1,       1,       1,       1,       1,       1,       1,       1,       1,       1,       2}
};
constexpr float gen_2_5
    [enum_value(TypeCount::gen_2_5)]
    [enum_value(TypeCount::gen_2_5)]
={
//Atk\Def   ,   Normal,Fighting,  Flying,  Poison,  Ground,    Rock,     Bug,   Ghost,    Fire,   Water,   Grass,Electric, Psychic,     Ice,  Dragon,   Steel,    Dark
/*Normal  */{        1,       1,       1,       1,       1,     0.5,       1,       0,       1,       1,       1,       1,       1,       1,       1,     0.5,       1},
/*Fighting*/{        2,       1,     0.5,     0.5,       1,       2,     0.5,       0,       1,       1,       1,       1,     0.5,       2,       1,       2,       2},
/*Flying  */{        1,       2,       1,       1,       1,     0.5,       2,       1,       1,       1,       2,     0.5,       1,       1,       1,     0.5,       1},
/*Poison  */{        1,       1,       1,     0.5,     0.5,     0.5,       1,     0.5,       1,       1,       2,       1,       1,       1,       1,       0,       1},
/*Ground  */{        1,       1,       0,       2,       1,       2,     0.5,       1,       2,       1,     0.5,       2,       1,       1,       1,       2,       1},
/*Rock    */{        1,     0.5,       2,       1,     0.5,       1,       2,       1,       2,       1,       1,       1,       1,       2,       1,     0.5,       1},
/*Bug     */{        1,     0.5,     0.5,     0.5,       1,       1,       1,     0.5,     0.5,       1,       2,       1,       2,       1,       1,     0.5,       2},
/*Ghost   */{        0,       1,       1,       1,       1,       1,       1,       2,       1,       1,       1,       1,       2,       1,       1,     0.5,     0.5},
/*Fire    */{        1,       1,       1,       1,       1,     0.5,       2,       1,     0.5,     0.5,       2,       1,       1,       2,     0.5,       2,       1},
/*Water   */{        1,       1,       1,       1,       2,       2,       1,       1,       2,     0.5,     0.5,       1,       1,       1,     0.5,       1,       1},
/*Grass   */{        1,       1,     0.5,     0.5,       2,       2,     0.5,       1,     0.5,       2,     0.5,       1,       1,       1,     0.5,     0.5,       1},
/*Electric*/{        1,       1,       2,       1,       0,       1,       1,       1,       1,       2,     0.5,     0.5,       1,       1,     0.5,       1,       1},
/*Psychic */{        1,       2,       1,       2,       1,       1,       1,       1,       1,       1,       1,       1,     0.5,       1,       1,     0.5,       0},
/*Ice     */{        1,       1,       2,       1,       2,       1,       1,       1,     0.5,     0.5,       2,       1,       1,     0.5,       2,     0.5,       1},
/*Dragon  */{        1,       1,       1,       1,       1,       1,       1,       1,       1,       1,       1,       1,       1,       1,       2,     0.5,       1},
/*Steel   */{        1,       1,       1,       1,       1,       2,       1,       1,     0.5,     0.5,       1,     0.5,       1,       2,       1,     0.5,       1},
/*Dark    */{        1,     0.5,       1,       1,       1,       1,       1,       2,       1,       1,       1,       1,       2,       1,       1,     0.5,     0.5}
};
constexpr float gen_6
    [enum_value(TypeCount::gen_6)]
    [enum_value(TypeCount::gen_6)]
={
//Atk\Def   ,   Normal,Fighting,  Flying,  Poison,  Ground,    Rock,     Bug,   Ghost,    Fire,   Water,   Grass,Electric, Psychic,     Ice,  Dragon,   Steel,    Dark,    Fairy
/*Normal  */{        1,       1,       1,       1,       1,     0.5,       1,       0,       1,       1,       1,       1,       1,       1,       1,     0.5,       1,       1},
/*Fighting*/{        2,       1,     0.5,     0.5,       1,       2,     0.5,       0,       1,       1,       1,       1,     0.5,       2,       1,       2,       2,     0.5},
/*Flying  */{        1,       2,       1,       1,       1,     0.5,       2,       1,       1,       1,       2,     0.5,       1,       1,       1,     0.5,       1,       1},
/*Poison  */{        1,       1,       1,     0.5,     0.5,     0.5,       1,     0.5,       1,       1,       2,       1,       1,       1,       1,       0,       1,       2},
/*Ground  */{        1,       1,       0,       2,       1,       2,     0.5,       1,       2,       1,     0.5,       2,       1,       1,       1,       2,       1,       1},
/*Rock    */{        1,     0.5,       2,       1,     0.5,       1,       2,       1,       2,       1,       1,       1,       1,       2,       1,     0.5,       1,       1},
/*Bug     */{        1,     0.5,     0.5,     0.5,       1,       1,       1,     0.5,     0.5,       1,       2,       1,       2,       1,       1,     0.5,       2,     0.5},
/*Ghost   */{        0,       1,       1,       1,       1,       1,       1,       2,       1,       1,       1,       1,       2,       1,       1,     0.5,     0.5,       1},
/*Fire    */{        1,       1,       1,       1,       1,     0.5,       2,       1,     0.5,     0.5,       2,       1,       1,       2,     0.5,       2,       1,       1},
/*Water   */{        1,       1,       1,       1,       2,       2,       1,       1,       2,     0.5,     0.5,       1,       1,       1,     0.5,       1,       1,       1},
/*Grass   */{        1,       1,     0.5,     0.5,       2,       2,     0.5,       1,     0.5,       2,     0.5,       1,       1,       1,     0.5,     0.5,       1,       1},
/*Electric*/{        1,       1,       2,       1,       0,       1,       1,       1,       1,       2,     0.5,     0.5,       1,       1,     0.5,       1,       1,       1},
/*Psychic */{        1,       2,       1,       2,       1,       1,       1,       1,       1,       1,       1,       1,     0.5,       1,       1,     0.5,       0,       1},
/*Ice     */{        1,       1,       2,       1,       2,       1,       1,       1,     0.5,     0.5,       2,       1,       1,     0.5,       2,     0.5,       1,       1},
/*Dragon  */{        1,       1,       1,       1,       1,       1,       1,       1,       1,       1,       1,       1,       1,       1,       2,     0.5,       1,       0},
/*Steel   */{        1,       1,       1,       1,       1,       2,       1,       1,     0.5,     0.5,       1,     0.5,       1,       2,       1,     0.5,       1,       2},
/*Dark    */{        1,     0.5,       1,       1,       1,       1,       1,       2,       1,       1,       1,       1,       2,       1,       1,     0.5,     0.5,     0.5},
/*Fairy   */{        1,       2,       1,     0.5,       1,       1,       1,       1,     0.5,       1,       1,       1,       1,       1,       2,     0.5,       2,       1}
};

float at(Gen gen,Type atk,Type def){
    if(gen==Gen::_1){
        if(enum_value(atk)>=enum_value(TypeCount::gen_1)){
            throw what("atk type index out of range for gen 1");
        }
        if(enum_value(def)>=enum_value(TypeCount::gen_1)){
            throw what("def type index out of range for gen 1");
        }
        return gen_1[enum_value(atk)][enum_value(def)];
    }else if(gen==Gen::_2_5){
        if(enum_value(atk)>=enum_value(TypeCount::gen_2_5)){
            throw what("atk type index out of range for gen 2~5");
        }
        if(enum_value(def)>=enum_value(TypeCount::gen_2_5)){
            throw what("def type index out of range for gen 2~5");
        }
        return gen_2_5[enum_value(atk)][enum_value(def)];
    }else if(gen==Gen::_6){
        if(enum_value(atk)>=enum_value(TypeCount::gen_6)){
            throw what("atk type index out of range for gen 6");
        }
        if(enum_value(def)>=enum_value(TypeCount::gen_6)){
            throw what("def type index out of range for gen 6");
        }
        return gen_6[enum_value(atk)][enum_value(def)];
    }else{
        throw what("unknown gen");
    }
}

}//namespace type_chart

}//namespace pokemon
