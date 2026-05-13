#pragma once

#include<array>
#include<string_view>

namespace pokemon{
namespace attr{
//gen 1
constexpr unsigned char Normal  =0 ;//一般
constexpr unsigned char Fighting=1 ;//格斗
constexpr unsigned char Flying  =2 ;//飞行
constexpr unsigned char Poison  =3 ;//毒
constexpr unsigned char Ground  =4 ;//地面
constexpr unsigned char Rock    =5 ;//岩石
constexpr unsigned char Bug     =6 ;//虫
constexpr unsigned char Ghost   =7 ;//幽灵
constexpr unsigned char Fire    =8 ;//火
constexpr unsigned char Water   =9 ;//水
constexpr unsigned char Grass   =10;//草
constexpr unsigned char Electric=11;//电
constexpr unsigned char Psychic =12;//超能力
constexpr unsigned char Ice     =13;//冰
constexpr unsigned char Dragon  =14;//龙
//gen 2~5
constexpr unsigned char Steel   =15;//钢
constexpr unsigned char Dark    =16;//恶
//gen 6^
constexpr unsigned char Fairy   =17;//妖精
}//namespace attr
constexpr std::array<std::string_view,18> attr_to_sv={
    "Normal",
    "Fighting",
    "Flying",
    "Poison",
    "Ground",
    "Rock",
    "Bug",
    "Ghost",
    "Fire",
    "Water",
    "Grass",
    "Electric",
    "Psychic",
    "Ice",
    "Dragon",
    "Steel",
    "Dark",
    "Fairy"
};
//没找到,返回-1
constexpr signed char sv_to_attr(std::string_view sv)noexcept{
    for(unsigned char index=0;index<pokemon::attr_to_sv.size();++index){
        if(sv==pokemon::attr_to_sv[index]){
            return index;
        }
    }
    return -1;
}
constexpr std::array<std::array<float,15>,15> gen_1_table={{
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
}};
constexpr std::array<std::array<float,17>,17> gen_2_5_table={{
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
}};
constexpr std::array<std::array<float,18>,18> gen_6_table={{
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
}};
namespace gen_table{
constexpr auto& _1  =pokemon::gen_1_table  ;//gen 1
constexpr auto& _2_5=pokemon::gen_2_5_table;//gen 2~5
constexpr auto& _6  =pokemon::gen_6_table  ;//gen 6^
}//namespace gen_table
}//namespace pokemon
