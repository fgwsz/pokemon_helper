#pragma once

#include<set>

#include"what.hpp"
#include"gen.hpp"
#include"type.hpp"
#include"type_chart.hpp"

namespace pokemon{

struct TypeMatchup{
    Type attack_type;
    std::set<Type> defense_type;
    float multiplier;

    void set(Gen gen,Type attack_type,std::set<Type> defense_type){
        if(defense_type.empty()||defense_type.size()>2){
            throw what("unknown type");
        }
        this->attack_type=attack_type;
        this->defense_type=defense_type;
        this->multiplier=1;
        for(auto const& def:defense_type){
            this->multiplier*=type_chart::at(gen,this->attack_type,def);
        }
    }
    void set(Gen gen,Type attack_type,Type defense_type){
        this->set(gen,attack_type,std::set<Type>{defense_type});
    }
    Type get_first_defense_type(void)const{
        if(this->defense_type.empty()){
            throw what("defense type is empty");
        }
        return *(this->defense_type.cbegin());
    }
};

}//namespace pokemon
