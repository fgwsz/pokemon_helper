#include<iostream>
#include<tuple>
#include<set>
#include<vector>
#include<string>

#include"pokemon.hpp"

int main(void){
    pokemon::Gen current_gen=pokemon::Gen::_6;
    std::set<pokemon::Type> owner_type={};
    std::set<pokemon::Type> atk_types={};
    std::tuple<std::set<pokemon::Type>,std::vector<pokemon::TypeMatchup>>
        weaknesses={};
    std::tuple<std::set<pokemon::Type>,std::vector<pokemon::TypeMatchup>>
        coverage_gaps={};
    std::string choice={};
    try{
        while(true){
            //读取世代信息
            current_gen=pokemon::num_to_gen(pokemon::read_ull(
                "Please enter gen number(>=1,values>6 will use gen 6 rules).",
                [](unsigned long long num){return num>=1;},
                "gen number must be at least 1"
            ));
            std::cout<<"Current gen: "<<current_gen<<'\n';
            //读取宝可梦自身属性信息
            owner_type=pokemon::read_types(
                current_gen,
                "Please enter pokemon owner type(s).",
                [](std::set<pokemon::Type>const& types){
                    return types.size()==1||types.size()==2;
                },
                "pokemon owner type(s) must be exactly 1 or 2 types"
            );
            //读取宝可梦攻击招式属性信息
            atk_types=pokemon::read_types(
                current_gen,
                "Please enter pokemon attack type(s).",
                [](std::set<pokemon::Type>const& types){
                    return types.size()>=1&&types.size()<=4;
                },
                "pokemon attcak type(s) must be 1 to 4 types"
            );
            //显示防御优势属性
            std::cout<<"Defensive advantages: "
                <<pokemon::get_defensive_advantages(current_gen,owner_type)
                <<'\n';
            //显示有效打击信息
            std::cout<<"Super effectives: "
                <<pokemon::get_super_effectives(current_gen,atk_types)<<'\n';
            //显示弱点信息
            weaknesses=pokemon::get_weaknesses(current_gen,owner_type);
            std::cout<<"Weaknesses: "<<weaknesses<<'\n';
            //显示打击盲点信息
            coverage_gaps=pokemon::get_coverage_gaps(current_gen,atk_types);
            std::cout<<"Coverage gaps: "<<coverage_gaps<<'\n';
            //显示攻击类型推荐信息
            if(std::get<0>(coverage_gaps).empty()){
                return 0;
            }
            std::cout<<"Top recommended attack types:\n"
                <<pokemon::get_recommend_info(
                    current_gen,
                    atk_types,
                    std::get<0>(weaknesses),
                    std::get<0>(coverage_gaps)
                );
            //提示用户是否继续/退出
            std::cout<<"Do you want to continue?(y/n)\n> ";
            std::getline(std::cin,choice);
            if(choice!="y"&&choice!="Y"){
                break;
            }
        }
    }catch(std::string const& what){
        std::cout<<"What: "<<what<<'\n';
    }
    return 0;
}
