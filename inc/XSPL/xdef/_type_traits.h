#ifndef __TYPE_TRAITS_H__
#define __TYPE_TRAITS_H__

#include "_def.h"

namespace xdef
{

template<typename T, T V>
struct integral_constant
{
    constexpr T value = V;
    using value_type = T;
};

using true_type = integral_constant<bool, true>;
using false_type = integral_constant<bool, false>;

template<typename A, typename B>
struct is_same : false_type {};

template<typename A>
struct is_same<A, A> : true_type {};

template<typename A>
using is_void = is_same<A, void>;
template<typename A>
constexpr bool is_void_v = is_void<A>::value;

template<typename A>
using is_null_pointer = is_same<A, nullptr_t>;
template<typename A>
constexpr bool is_null_pointer_v = is_null_pointer<A>::value;

}

#endif