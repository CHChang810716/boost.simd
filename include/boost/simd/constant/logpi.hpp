//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_CONSTANT_LOGPI_HPP_INCLUDED
#define BOOST_SIMD_CONSTANT_LOGPI_HPP_INCLUDED

/*!
  @ingroup group-constant
  @defgroup constant-Logpi Logpi (function template)

  Generates the constant \f$\log\pi\f$

  @headerref{<boost/simd/constant/logpi.hpp>}

  @par Description

  1.  @code
      template<typename T> T Logpi();
      @endcode

  2.  @code
      template<typename T> T Logpi( boost::simd::as_<T> const& target );
      @endcode

  Generates a value of type @c T that evaluates to \f$\log\pi\f$.

  @par Parameters

  | Name                | Description                                                         |
  |--------------------:|:--------------------------------------------------------------------|
  | **target**          | a [placeholder](@ref type-as) value encapsulating the constant type |

  @par Return Value
  A value of type @c T that evaluates to `T(1.1447298858494001741434273513531)`

  @par Requirements
  - **T** models IEEEValue
**/

#include <boost/simd/constant/scalar/logpi.hpp>
#include <boost/simd/constant/simd/logpi.hpp>

#endif
