#pragma once

#include<vector>

#include"enum_value.hpp"
#include"gen.hpp"
#include"type.hpp"
#include"type_count.hpp"
#include"type_chart.hpp"

namespace pokemon{

std::vector<Type> get_coverage_gaps(Gen gen,std::vector<Type>const& types){
    unsigned char type_count=enum_value(gen_to_type_count(gen));
    std::vector<unsigned char> map(type_count,0);//=0未覆盖,=1已覆盖
    for(auto const& type:types){
        for(unsigned char index=0;index<type_count;++index){
            if(
                map[index]==0
                &&type_chart::at(gen,type,static_cast<Type>(index))>=1
            ){
                map[index]=1;
            }
        }
    }
    std::vector<Type> ret={};
    for(unsigned char index=0;index<type_count;++index){
        if(map[index]==0){
            ret.emplace_back(static_cast<Type>(index));
        }
    }
    return ret;
}

}//namespace pokemon
