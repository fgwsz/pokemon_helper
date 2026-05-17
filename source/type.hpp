#pragma once

#include"enum_value.hpp"
#include"what.hpp"

namespace pokemon{

enum class Type:unsigned char{
    Normal  =0 ,//一般
    Fighting=1 ,//格斗
    Flying  =2 ,//飞行
    Poison  =3 ,//毒
    Ground  =4 ,//地面
    Rock    =5 ,//岩石
    Bug     =6 ,//虫
    Ghost   =7 ,//幽灵
    Fire    =8 ,//火
    Water   =9 ,//水
    Grass   =10,//草
    Electric=11,//电
    Psychic =12,//超能力
    Ice     =13,//冰
    Dragon  =14,//龙
    //gen 2~5
    Steel   =15,//钢
    Dark    =16,//恶
    //gen 6^
    Fairy   =17 //妖精
};

Type make_type(unsigned char type_index){
    if(type_index>enum_value(Type::Fairy)){
        throw what("unknown type index");
    }
    return static_cast<Type>(type_index);
}

}//namespace pokemon
