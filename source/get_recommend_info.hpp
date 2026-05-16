#pragma once

#include<cstddef>
#include<set>
#include<vector>
#include<functional>

#include"enum_value.hpp"
#include"gen.hpp"
#include"type.hpp"
#include"type_matchup.hpp"
#include"type_count.hpp"
#include"type_chart.hpp"

//推荐规则:
//第一个准则:盲点属性的覆盖数量
//第二个准则:盲点属性的暴击倍数
//第三个准则:弱点属性的覆盖数量
//第四个准则:弱点属性的暴击倍数

namespace pokemon{

struct RecommendInfoEntry{
    Type type;
    std::set<Type> coverage_gaps;
    std::vector<TypeMatchup> coverage_gap_super_matchups;
    std::set<Type> weaknesses;
    std::vector<TypeMatchup> weakness_super_matchups;
};

bool operator>(RecommendInfoEntry const& lhs,RecommendInfoEntry const& rhs){
    if(lhs.coverage_gaps.size()!=rhs.coverage_gaps.size()){
        return lhs.coverage_gaps.size()>rhs.coverage_gaps.size();
    }
    float lhs_multiplier=0;
    float rhs_multiplier=0;
    auto lhs_itr=lhs.coverage_gap_super_matchups.cbegin();
    auto rhs_itr=rhs.coverage_gap_super_matchups.cbegin();
    for(std::size_t index=0;index<lhs.coverage_gaps.size();++index){
        lhs_multiplier+=lhs_itr->multiplier;
        rhs_multiplier+=rhs_itr->multiplier;
        ++lhs_itr;
        ++rhs_itr;
    }
    if(lhs_multiplier!=rhs_multiplier){
        return lhs_multiplier>rhs_multiplier;
    }
    if(lhs.weaknesses.size()!=rhs.weaknesses.size()){
        return lhs.weaknesses.size()>rhs.weaknesses.size();
    }
    lhs_multiplier=0;
    rhs_multiplier=0;
    lhs_itr=lhs.weakness_super_matchups.cbegin();
    rhs_itr=rhs.weakness_super_matchups.cbegin();
    for(std::size_t index=0;index<lhs.weaknesses.size();++index){
        lhs_multiplier+=lhs_itr->multiplier;
        rhs_multiplier+=rhs_itr->multiplier;
        ++lhs_itr;
        ++rhs_itr;
    }
    if(lhs_multiplier!=rhs_multiplier){
        return lhs_multiplier>rhs_multiplier;
    }

    return enum_value(lhs.type)>enum_value(rhs.type);
}

std::set<RecommendInfoEntry,std::greater<RecommendInfoEntry>>
get_recommend_info(
    Gen gen,
    std::set<Type> const& current_attack_types,
    std::set<Type> const& target_coverage_gaps,
    std::set<Type> const& target_weaknesses
){
    unsigned char type_count=enum_value(gen_to_type_count(gen));
    std::set<RecommendInfoEntry,std::greater<RecommendInfoEntry>> ret={};
    RecommendInfoEntry entry={};
    TypeMatchup matchup={};
    for(unsigned char index=0;index<type_count;++index){
        entry.type=static_cast<Type>(index);
        if(current_attack_types.contains(entry.type)){
            continue;
        }
        entry.coverage_gaps.clear();
        entry.coverage_gap_super_matchups.clear();
        entry.weaknesses.clear();
        entry.weakness_super_matchups.clear();
        for(auto const& def:target_coverage_gaps){
            matchup.attack_type=entry.type;
            matchup.defense_type={def};
            matchup.multiplier=type_chart::at(
                gen,
                matchup.attack_type,
                *(matchup.defense_type.cbegin())
            );
            if(matchup.multiplier>1){
                entry.coverage_gaps.emplace(def);
                entry.coverage_gap_super_matchups.emplace_back(matchup);
            }
        }
        for(auto const& def:target_weaknesses){
            matchup.attack_type=entry.type;
            matchup.defense_type={def};
            matchup.multiplier=type_chart::at(
                gen,
                matchup.attack_type,
                *(matchup.defense_type.cbegin())
            );
            if(matchup.multiplier>1){
                entry.weaknesses.emplace(def);
                entry.weakness_super_matchups.emplace_back(matchup);
            }
        }
        if(!entry.coverage_gaps.empty()){
            ret.emplace(entry);
        }
    }
    return ret;
}

}//namespace pokemon
