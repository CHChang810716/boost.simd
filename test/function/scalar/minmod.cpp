//==================================================================================================
/*!

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/function/scalar/minmod.hpp>
#include <scalar_test.hpp>
#include <boost/simd/detail/dispatch/meta/as_integer.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/constant/two.hpp>
#include <boost/simd/constant/mtwo.hpp>

STF_CASE_TPL (" minmod real",  STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::minmod;
  using r_t = decltype(minmod(T(), T()));

  // return type conformity test
  STF_TYPE_IS(r_t, T);

  // specific values tests
#ifndef BOOST_SIMD_NO_INVALIDS
  STF_EQUAL(minmod(bs::Inf<T>(), bs::Inf<T>()), bs::Inf<T>());
  STF_EQUAL(minmod(bs::Minf<T>(), bs::Minf<T>()), bs::Minf<T>());
  STF_IEEE_EQUAL(minmod(bs::Nan<T>(), bs::Nan<T>()), bs::Nan<T>());
#endif
  STF_EQUAL(minmod(bs::Mone<T>(), bs::Mone<T>()), bs::Mone<T>());
  STF_EQUAL(minmod(bs::One<T>(), bs::One<T>()), bs::One<T>());
  STF_EQUAL(minmod(bs::Zero<T>(), bs::Zero<T>()), bs::Zero<T>());
  STF_IEEE_EQUAL(minmod(bs::Nan<T>(), bs::One<T>()), bs::Nan<T>());
  STF_IEEE_EQUAL(minmod(bs::One<T>(), bs::Nan<T>()), bs::One<T>());
  STF_IEEE_EQUAL(minmod(bs::Nan<T>(), bs::Zero<T>()), bs::Nan<T>());
  STF_IEEE_EQUAL(minmod(bs::Zero<T>(), bs::Nan<T>()), bs::Zero<T>());
  STF_EQUAL(minmod(bs::One<T>(), bs::Two<T>()), bs::One<T>());
  STF_EQUAL(minmod(bs::Two<T>(), bs::One<T>()), bs::One<T>());
  STF_EQUAL(minmod(bs::One<T>(), bs::Mtwo<T>()), bs::Zero<T>());
  STF_EQUAL(minmod(bs::Mtwo<T>(), bs::One<T>()), bs::Zero<T>());
} // end of test for floating_

STF_CASE_TPL (" minmodunsigned_int",  STF_UNSIGNED_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::minmod;
  using r_t = decltype(minmod(T(), T()));

  // return type conformity test
  STF_TYPE_IS(r_t, T);

  // specific values tests
  STF_EQUAL(minmod(bs::One<T>(), bs::One<T>()), bs::One<T>());
  STF_EQUAL(minmod(bs::Zero<T>(), bs::Zero<T>()), bs::Zero<T>());
  STF_EQUAL(minmod(bs::One<T>(), bs::Zero<T>()), bs::Zero<T>());
  STF_EQUAL(minmod(bs::Zero<T>(), bs::One<T>()), bs::Zero<T>());
} // end of test for unsigned_int_

STF_CASE_TPL (" minmodsigned_int",  STF_SIGNED_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::minmod;
  using r_t = decltype(minmod(T(), T()));

  // return type conformity test
  STF_TYPE_IS(r_t, T);

  // specific values tests
  STF_EQUAL(minmod(bs::Mone<T>(), bs::Mone<T>()), bs::Mone<T>());
  STF_EQUAL(minmod(bs::One<T>(), bs::One<T>()), bs::One<T>());
  STF_EQUAL(minmod(bs::Zero<T>(), bs::Zero<T>()), bs::Zero<T>());
  STF_EQUAL(minmod(bs::One<T>(), bs::Zero<T>()), bs::Zero<T>());
  STF_EQUAL(minmod(bs::Zero<T>(), bs::One<T>()), bs::Zero<T>());
  STF_EQUAL(minmod(bs::Mone<T>(), bs::Zero<T>()), bs::Zero<T>());
  STF_EQUAL(minmod(bs::Zero<T>(), bs::Mone<T>()), bs::Zero<T>());
  STF_EQUAL(minmod(bs::One<T>(), bs::Mtwo<T>()), bs::Zero<T>());
  STF_EQUAL(minmod(bs::Mtwo<T>(), bs::One<T>()), bs::Zero<T>());
} // end of test for signed_int_
