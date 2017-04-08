//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

**/
//==================================================================================================
#ifndef BOOST_SIMD_OPERATOR_HPP_INCLUDED
#define BOOST_SIMD_OPERATOR_HPP_INCLUDED

namespace boost { namespace simd
{
  /*!
    @ingroup group-functions
    @defgroup group-operator Operators

    These functions provide scalar and SIMD version of the native C and C++ operators.

    Operators are provided in infix and prefix notations, except for scalar floating types
    as C++ does not allow overloading of operators for these types. Operators &, |, ~,  % and
    the ternary operator ?: are also not defined for floating types in C++.
    In these seldomly used cases, prefix bitwise_and, bitwise_or, complement
    and if_else are required.

    @warningbox{Note that && and || overloaded on simd packs do not make short circuitry}

    Here is the list of of operators and their infix associated notation.
    These remarks are only valid if the prefix notation is used and at least one parameter is a pack:
    otherwise infix operators on scalars are regulated by usual C++ langage rules.

    All operators are included as soon as <boost/simd/pack.hpp> is included.

    <center>
    | Name                                        | op  | arity |   types      |  precondition/result                          |
    |---------------------------------------------|-----|-------|--------------|-----------------------------------------------|
    | [bitwise_and     ](@ref real-bitwise_and)        | &   |  2    |  T1, T2      |  same bit size for T1 and T2    (1)           |
    | [bitwise_or      ](@ref real-bitwise_or)         | \|  |  2    |  T1, T2      |  same bit size for T1 and T2    (1)           |
    | [bitwise_xor     ](@ref real-bitwise_xor)        | ^   |  2    |  T1, T2      |  same bit size for T1 and T2    (1)           |
    | [complement      ](@ref real-complement)         | ~   |  1    |  T1          |                                               |
    | [divides         ](@ref real-divides)            | /   |  2    |  T1, T1      |  arithmetic types               (2)           |
    | [div             ](@ref real-div)                | /   |  2    |  T1, T1      |  arithmetic types               (2)           |
    | [if_else         ](@ref real-if_else)            | NA  |  3    |  T1, T2, T2  |                                               |
    | [is_equal        ](@ref real-is_equal)           | ==  |  2    |  T1, T1      |                                               |
    | [is_greater      ](@ref real-is_greater)         | >   |  2    |  T1, T1      |                                               |
    | [is_greater_equal](@ref real-is_greater_equal)   | >=  |  2    |  T1, T1      |                                               |
    | [is_less         ](@ref real-is_less)            | <   |  2    |  T1, T1      |                                               |
    | [is_less_equal   ](@ref real-is_less_equal)      | <=  |  2    |  T1, T1      |                                               |
    | [is_not_equal    ](@ref real-is_not_equal)       | !=  |  2    |  T1, T1      |                                               |
    | [logical_and     ](@ref real-logical_and)        | &&  |  2    |  T1, T1      |  returns a @ref logical                       |
    | [logical_not     ](@ref real-logical_not)        | !   |  1    |  T1, T1      |  returns a @ref logical                       |
    | [logical_or      ](@ref real-logical_or)         | \|\||  2    |  T1, T1      |  returns a @ref logical                       |
    | [minus           ](@ref real-minus)              | -   |  2    |  T1, T1      |  arithmetic types                (2)          |
    | [rem             ](@ref real-rem)                | %   |  2    |  T1, T2      |  T2 is integral scalar or associated to T1 (3)|
    | [multiplies      ](@ref real-multiplies)         | *   |  2    |  T1, T1      |  arithmetic types                (2)          |
    | [plus            ](@ref real-plus)               | +   |  2    |  T1, T1      |  arithmetic types                (2)          |
    | [shift_left      ](@ref real-shift_left)         | <<  |  2    |  T1, T2      |  T2 is integral scalar or associated to T1 (3)|
    | [shift_right     ](@ref real-shift_right)        | >>  |  2    |  T1, T2      |  T2 is integral scalar or associated to T1 (3)|
    | [shr             ](@ref real-shr)                | NA  |  2    |  T1, T2      |  T2 is integral scalar or associated to T1 (3)|
    | [unary_minus     ](@ref real-unary_minus)        | -   |  1    |  T1          |  signed arithmetic types         (2)          |
    | [unary_plus      ](@ref real-unary_plus)         | +   |  1    |  T1          |  arithmetic types                (2)          |
    </center>


    Notes:
     - (1)  This precisely means sizeof(T1) == sizeof(T2) or one is scalar and its size in bits is the same as
           the element of the other (which is a pack).

     - (2)  arithmetic types are defined as std::int8_t, std::int16_t, std::int32_t, std::int64_t,
           std::uint8_t, std::uint16_t, std::uint32_t, std::uint64_t, float, double and packs of these.

           The use of implementation dependent types as char, int, long, long long and their unsigned conterpart
           is discouraged and even may lead to inconsistent behaviour.

           Also it must be noted that "arithmetic" operators cannot mix types. This is to ensure correct SIMD
           performance if the operation is supported by hardware.

     - (3)  This precisely means T2 is both scalar and of integral type or T2 is as_integer_t<T1>. Note that if T2 scalar
           is always simd hardware supported, the other case is often emulated.

   Extensions:

     [div]( @ref real-div) "division"  and [rem](@ref real-rem) "remainder" operators have extensions to be seen following the links.

  **/
} }

#include <boost/simd/function/bitwise_and.hpp>
#include <boost/simd/function/bitwise_or.hpp>
#include <boost/simd/function/bitwise_xor.hpp>
#include <boost/simd/function/complement.hpp>
#include <boost/simd/function/div.hpp>
#include <boost/simd/function/divides.hpp>
#include <boost/simd/function/minus.hpp>
#include <boost/simd/function/multiplies.hpp>
#include <boost/simd/function/plus.hpp>
#include <boost/simd/function/shift_left.hpp>
#include <boost/simd/function/shift_right.hpp>
#include <boost/simd/function/shl.hpp>
#include <boost/simd/function/unary_minus.hpp>
#include <boost/simd/function/unary_plus.hpp>
#include <boost/simd/function/if_else.hpp>
#include <boost/simd/function/is_equal.hpp>
#include <boost/simd/function/is_greater.hpp>
#include <boost/simd/function/is_greater_equal.hpp>
#include <boost/simd/function/is_less.hpp>
#include <boost/simd/function/is_less_equal.hpp>
#include <boost/simd/function/is_not_equal.hpp>
#include <boost/simd/function/logical_and.hpp>
#include <boost/simd/function/logical_not.hpp>
#include <boost/simd/function/logical_or.hpp>
#include <boost/simd/function/minus.hpp>
#include <boost/simd/function/rem.hpp>
#include <boost/simd/function/multiplies.hpp>
#include <boost/simd/function/plus.hpp>
#include <boost/simd/function/shift_left.hpp>
#include <boost/simd/function/shift_right.hpp>
#include <boost/simd/function/shl.hpp>
#include <boost/simd/function/unary_minus.hpp>
#include <boost/simd/function/unary_plus.hpp>

#endif
