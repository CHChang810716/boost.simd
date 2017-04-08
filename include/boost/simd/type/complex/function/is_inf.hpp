//==================================================================================================
/**
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_TYPE_COMPLEX_FUNCTION_IS_INF_HPP_INCLUDED
#define BOOST_SIMD_TYPE_COMPLEX_FUNCTION_IS_INF_HPP_INCLUDED
#if defined(DOXYGEN_ONLY)

  /*!
    @ingroup group-complex
    @defgroup complex-is_inf is_inf (function object, complex version)

    This function object, complex version returns True if and only if real or imaginary part
    of the parameters is inf.

    @headerref{<boost/simd/type/complex/function/is_inf.hpp>}

    @par Description

    @code
    as_logical<IEEEValue> is_inf(complex<IEEEValue> const& z);
    @endcode


    @see ( %real ) [is_inf](@ref  real-is_inf)

    @par Example:

       @snippet c_is_inf.cpp is_inf

    @par Possible output:

       @snippet c_is_inf.txt is_inf

  **/

#include <boost/simd/function/is_inf.hpp>
#include <boost/simd/type/complex/function/impl/is_inf.hpp>

#endif
