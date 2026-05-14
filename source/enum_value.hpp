#pragma once

#include<type_traits>

namespace pokemon{

template<typename E>
constexpr std::underlying_type_t<E> enum_value(E e)noexcept{
    static_assert(
        std::is_enum_v<E>
        ,"pokemon::enum_value requires an enumeration type"
    );
    return static_cast<std::underlying_type_t<E>>(e);
}

}//namespace pokemon
