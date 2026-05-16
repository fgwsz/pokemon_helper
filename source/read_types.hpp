#pragma once

#include<string>
#include<string_view>
#include<vector>
#include<set>
#include<cctype>
#include<algorithm>
#include<stdexcept>
#include<functional>
#include <algorithm>

#include"what.hpp"
#include"type.hpp"
#include"print.hpp"
#include"enum_value.hpp"

namespace pokemon{

struct TypeRule{
    std::string_view prefix;
    std::string_view suffix;
    Type type;
};

static const std::vector<TypeRule> type_rules={
    {"b","ug",Type::Bug},
    {"da","rk",Type::Dark},
    {"dr","agon",Type::Dragon},
    {"e","lectric",Type::Electric},
    {"fa","iry",Type::Fairy},
    {"fig","hting",Type::Fighting},
    {"fir","e",Type::Fire},
    {"fl","ying",Type::Flying},
    {"gh","ost",Type::Ghost},
    {"gra","ss",Type::Grass},
    {"gro","und",Type::Ground},
    {"i","ce",Type::Ice},
    {"n","ormal",Type::Normal},
    {"po","ison",Type::Poison},
    {"ps","ychic",Type::Psychic},
    {"r","ock",Type::Rock},
    {"s","teel",Type::Steel},
    {"w","ater",Type::Water}
};

//不区分大小写比较两个字符串视图是否相等
bool iequals(std::string_view a,std::string_view b){
    return std::equal(
        a.begin(),a.end(),b.begin(),b.end(),
        [](char c1,char c2){
            return std::tolower(static_cast<unsigned char>(c1))==
                   std::tolower(static_cast<unsigned char>(c2));
        }
    );
}

//判断str是否为suffix的前缀(大小写不敏感)
bool is_prefix_of(std::string_view str,std::string_view suffix){
    if(str.size()>suffix.size()){
        return false;
    }
    return iequals(str,suffix.substr(0,str.size()));
}

//尝试匹配规则,成功则输出对应类型
bool match_type(const TypeRule& rule,std::string_view input,Type& out){
    if(input.size()<rule.prefix.size()){
        return false;
    }
    if(!iequals(input.substr(0,rule.prefix.size()),rule.prefix)){
        return false;
    }
    std::string_view rest=input.substr(rule.prefix.size());
    if(is_prefix_of(rest,rule.suffix)){
        out=rule.type;
        return true;
    }
    return false;
}

//去除字符串首尾空格
std::string_view trim(std::string_view s){
    std::size_t start=s.find_first_not_of(" \t");
    if(start==std::string_view::npos){
        return "";
    }
    std::size_t end=s.find_last_not_of(" \t");
    return s.substr(start,end-start+1);
}

//解析逗号分隔的类型列表(例如"b,da,dr"或"bu,dark,dra")
std::set<Type> parse_types(std::string_view input){
    std::set<Type> ret={};
    std::string_view remaining=input;
    std::size_t comma=0;
    std::string_view token={};
    bool matched=false;
    Type out=Type::Normal;
    while(!remaining.empty()){
        comma=remaining.find(',');
        token=(comma==std::string_view::npos)
            ?remaining
            :remaining.substr(0,comma)
        ;
        token=trim(token);
        if(!token.empty()){
            matched=false;
            for(auto const& rule:type_rules){
                if(match_type(rule,token,out)){
                    ret.emplace(out);
                    matched=true;
                    break;
                }
            }
            if(!matched){
                throw what("Invalid type name:"+std::string(token));
            }
        }
        if(comma==std::string_view::npos)break;
        remaining=remaining.substr(comma+1);
    }
    return ret;
}

std::set<Type> read_types(
    Gen gen,
    std::string_view help_msg="",
    std::function<bool(std::set<Type>const&)>const& check_fn
        =[](std::set<Type>const&){return true;},
    std::string_view error_msg=""
){
    constexpr char help_gen_1[]=
R"(Enter types(comma-separated), using shortest unique prefixes:
    b[ug]        dr[agon]    e[lectric]  fig[hting]  fir[e]
    fl[ying]     gh[ost]     gra[ss]     gro[und]    i[ce]
    n[ormal]     po[ison]    ps[ychic]   r[ock]      w[ater]
Example: b,da,dr
> )";
    constexpr char help_gen_2_5[]=
R"(Enter types(comma-separated), using shortest unique prefixes:
    b[ug]        da[rk]      dr[agon]    e[lectric]  fig[hting]  fir[e]
    fl[ying]     gh[ost]     gra[ss]     gro[und]    i[ce]       n[ormal]
    po[ison]     ps[ychic]   r[ock]      s[teel]     w[ater]
Example: b,da,dr
> )";
    constexpr char help_gen_6[]=
R"(Enter types(comma-separated), using shortest unique prefixes:
    b[ug]       da[rk]       dr[agon]    e[lectric]  fa[iry]     fig[hting]
    fir[e]      fl[ying]     gh[ost]     gra[ss]     gro[und]    i[ce]
    n[ormal]    po[ison]     ps[ychic]   r[ock]      s[teel]     w[ater]
Example: b,da,dr
> )";
    std::string_view help={};
    if(gen==Gen::_1){
        help=help_gen_1;
    }else if(gen==Gen::_2_5){
        help=help_gen_2_5;
    }else if(gen==Gen::_6){
        help=help_gen_6;
    }else{
        throw what("unknown gen");
    }
    std::set<Type> ret={};
    std::string str={};
    auto type_count=enum_value(gen_to_type_count(gen));
    bool continue_flag=false;
    while(true){
        str.clear();
        ret.clear();
        continue_flag=false;
        std::cout<<help_msg<<(help_msg.empty()?"":"\n");
        std::cout<<help;
        std::getline(std::cin,str);
        try{
            ret=parse_types(str);
            std::cout<<"\nEnter types is {"<<ret<<"}.\n";
            for(auto const& type:ret){
                if(enum_value(type)>=type_count){
                    std::cout
                        <<"Invalid input("<<type<<" does not exist in "
                        <<gen<<"), please try again.\n";
                    continue_flag=true;
                    break;
                }
            }
            if(continue_flag){
                continue;
            }
            if(check_fn(ret)){
                return ret;
            }else{
                std::cout<<"Invalid input";
                if(!error_msg.empty()){
                    std::cout<<" ("<<error_msg<<")";
                }
                std::cout<<", please try again.\n";
            }
        }catch(...){
            std::cout<<"Invalid input, please try again.\n";
        }
    }
}

}//namespace pokemon
