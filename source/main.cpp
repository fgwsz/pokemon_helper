#include<iostream>
#include<format>

#include"pokemon.hpp"

int main(void){
    //读取世代信息
    std::cout<<"Please input gen num(in [1,+inf)).\n";
    auto gen_num=static_cast<unsigned char>(
        pokemon::read_ull(
            [](unsigned long long num){return num>=1;},
            "gen num is not in [1,+inf)"
        )
    );
    pokemon::Gen current_gen=pokemon::num_to_gen(gen_num);
    std::cout<<"current gen: ";
    pokemon::print_gen(current_gen);
    std::cout<<'\n';
    unsigned char type_count
        =pokemon::enum_value(pokemon::gen_to_type_count(current_gen));
    //读取宝可梦自身属性信息
    std::cout<<"Please input pokemon type id(1:single type,2:dual type).\n";
    auto type_id=static_cast<unsigned char>(
        pokemon::read_ull(
            [](unsigned long long num){return num==1||num==2;},
            "type id is not in [1,2]"
        )
    );
    std::vector<pokemon::Type> owner_type={};
    if(type_id==1){
        std::cout<<"Please input pokemon first type id.\n";
        auto first_type_id=static_cast<unsigned char>(
            pokemon::read_ull(
                [&type_count](unsigned long long num){return num<type_count;},
                std::format("type id is not in [0,{})",type_count)
            )
        );
        owner_type.emplace_back(static_cast<pokemon::Type>(first_type_id));
        std::cout<<"Pokemon type is ";
        pokemon::print_types(owner_type);
        std::cout<<'\n';
    }else{
        std::cout<<"Please input pokemon first type id.\n";
        auto first_type_id=static_cast<unsigned char>(
            pokemon::read_ull(
                [&type_count](unsigned long long num){return num<type_count;},
                std::format("type id is not in [0,{})",type_count)
            )
        );
        owner_type.emplace_back(static_cast<pokemon::Type>(first_type_id));
        std::cout<<"Please input pokemon second type id.\n";
        auto second_type_id=static_cast<unsigned char>(
            pokemon::read_ull(
                [&type_count](unsigned long long num){return num<type_count;},
                std::format("type id is not in [0,{})",type_count)
            )
        );
        owner_type.emplace_back(static_cast<pokemon::Type>(second_type_id));
        std::cout<<"Pokemon type is ";
        pokemon::print_types(owner_type);
        std::cout<<'\n';
    }
    if(type_id==1){
        std::cout<<"Weaknesses: ";
        pokemon::print_types(pokemon::get_weaknesses(current_gen,owner_type[0]));
        std::cout<<'\n';
    }else{
        std::cout<<"Weaknesses: ";
        pokemon::print_types(pokemon::get_weaknesses(current_gen,owner_type[0],owner_type[1]));
        std::cout<<'\n';
    }
    //读取宝可梦攻击招式属性信息
    return 0;
}
