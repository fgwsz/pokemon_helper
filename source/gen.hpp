#pragma once

#include"what.hpp"

namespace pokemon{

enum class Gen:unsigned char{
    _1  ,//第一世代
    _2_5,//第二世代到第五世代
    _6   //第六世代及以后
};

Gen num_to_gen(unsigned long long num){
    if(num==1){
        return Gen::_1;
    }else if(num>=2&&num<=5){
        return Gen::_2_5;
    }else if(num>=6){
        return Gen::_6;
    }else{
        throw what("unknown gen");
    }
}

}//namespace pokemon
