#include<iostream>
#include<format>

#include"pokemon.hpp"

int main(void){
    //读取世代信息
    pokemon::Gen current_gen=pokemon::num_to_gen(
        pokemon::read_ull(
            "Please input gen num(in [1,+inf)).",
            [](unsigned long long num){return num>=1;},
            "gen num is not in [1,+inf)"
        )
    );
    std::cout<<"current gen: "<<current_gen<<'\n';
    //读取宝可梦自身属性信息
    std::vector<pokemon::Type> owner_type=pokemon::read_types(
        current_gen,
        "Please enter pokemon type.",
        [](std::vector<pokemon::Type>const& types){
            return types.size()==1||types.size()==2;
        },
        "pokemon type has 1~2 single type"
    );
    //显示弱点信息
    if(owner_type.size()==1){
        std::cout<<"Weaknesses: "
            <<pokemon::get_weaknesses(current_gen,owner_type[0])<<'\n';
    }else{
        std::cout<<"Weaknesses: "
            <<pokemon::get_weaknesses(current_gen,owner_type[0],owner_type[1])
            <<'\n';
    }
    //读取宝可梦攻击招式属性信息
    std::vector<pokemon::Type> atk_types=pokemon::read_types(
        current_gen,
        "Please enter pokemon atk types.",
        [](std::vector<pokemon::Type>const& types){
            return types.size()>=1&&types.size()<=4;
        },
        "pokemon atk type has 1~4 single type"
    );
    //显示打击盲点信息
    auto coverage_gaps=pokemon::get_coverage_gaps(current_gen,atk_types);
    std::cout<<"Coverage gaps: "<<coverage_gaps<<'\n';
    //显示属性推荐
    if(coverage_gaps.empty()){
        return 0;
    }
    return 0;
}
