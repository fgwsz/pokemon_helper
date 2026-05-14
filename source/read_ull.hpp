#pragma once

#include<string>
#include<string_view>
#include<iostream>
#include<functional>

namespace pokemon{

unsigned long long read_ull(
    std::function<bool(unsigned long long)>const& check_fn
        =[](unsigned long long){return true;},
    std::string_view error_msg=""
){
    unsigned long long ret=0;
    std::string str={};
    while(true){
        std::cout<<"Please input number (unsigned long long): ";
        std::getline(std::cin,str);
        try{
            ret=std::stoull(str);
            std::cout<<"Your number is {"<<ret<<"}.\n";
            if(check_fn(ret)){
                return ret;
            }else{
                std::cout<<"Invalid input";
                if(!error_msg.empty()){
                    std::cout<<" ("<<error_msg<<")";
                }
                std::cout<<", please try again.\n";
            }
        }catch(std::invalid_argument const&){
            std::cout<<"Invalid input (not a number), please try again.\n";
        }catch(std::out_of_range const&){
            std::cout<<"Number too large, please try again.\n";
        }
    }
}

}//namespace pokemon
