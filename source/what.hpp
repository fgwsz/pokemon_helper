#pragma once

#include<string>
#include<source_location>
#include<string_view>
#include<format>

namespace pokemon{
 
std::string what(
    std::string_view message,
    std::source_location location=std::source_location::current()
){
    return std::format("file: {}({}:{})`{}`: {}",
        location.file_name(),
        location.line(),
        location.column(),
        location.function_name(),
        message
    );
}

}//namespace pokemon
