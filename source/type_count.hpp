#pragma once

#include"gen.hpp"
#include"what.hpp"

namespace pokemon{

enum class TypeCount:unsigned char{
    gen_1  =15,//第一世代
    gen_2_5=17,//第二世代到第五世代
    gen_6  =18 //第六世代及以后
};

TypeCount gen_to_type_count(Gen gen){
    if(gen==Gen::_1){
        return TypeCount::gen_1;
    }else if(gen==Gen::_2_5){
        return TypeCount::gen_2_5;
    }else if(gen==Gen::_6){
        return TypeCount::gen_6;
    }else{
        throw what("unknown gen");
    }
}

}//namespace pokemon
