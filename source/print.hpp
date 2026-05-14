#pragma once

#include<cstddef>
#include<iostream>
#include<vector>

#include"what.hpp"
#include"gen.hpp"
#include"type.hpp"
#include"type_sv.hpp"

namespace pokemon{

void print_gen(Gen gen){
    if(gen==Gen::_1){
        std::cout<<"gen 1";
    }else if(gen==Gen::_2_5){
        std::cout<<"gen 2~5";
    }else if(gen==Gen::_6){
        std::cout<<"gen 6^";
    }else{
        throw what("unknown gen");
    }
}

void print_type(Type type){
    std::cout<<type_to_type_sv(type);
}

void print_types(std::vector<Type>const& types){
    if(types.size()==1){
        return print_type(types[0]);
    }
    std::cout<<"[";
    std::size_t index=0;
    for(auto const& type:types){
        print_type(type);
        if(index+1!=types.size()){
            std::cout<<", ";
        }
        ++index;
    }
    std::cout<<"]";
}

}//namespace pokemon
