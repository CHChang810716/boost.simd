//==================================================================================================
/*
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/type/complex/function/arg.hpp>
#include <boost/simd/type/complex.hpp>
#include <boost/simd/pack.hpp>
#include <boost/simd/constant/pi.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/function/sqrt.hpp>
#include <simd_test.hpp>

namespace bs = boost::simd;

STF_CASE_TPL( "Complex arg on complex<T>", STF_IEEE_TYPES)
{
  bs::complex<T> r0(0,4), r1(4,0), r2(3,3), r3(-1,0), r4(0,-1), r5(-2,-2);

  STF_EQUAL(r0.argument(), bs::Pi<T>()/2);
  STF_EQUAL(r1.argument(), bs::Zero<T>());
  STF_EQUAL(r2.argument(), bs::Pi<T>()/4);
  STF_EQUAL(r3.argument(), bs::Pi<T>());
  STF_EQUAL(r4.argument(), -bs::Pi<T>()/2);
  STF_EQUAL(r5.argument(), -3*bs::Pi<T>()/4);

  STF_EQUAL(bs::arg(r0),  bs::Pi<T>()/2);
  STF_EQUAL(bs::arg(r1),  bs::Zero<T>());
  STF_EQUAL(bs::arg(r2),  bs::Pi<T>()/4);    ;
  STF_EQUAL(bs::arg(r3),  bs::Pi<T>());
  STF_EQUAL(bs::arg(r4),  -bs::Pi<T>()/2);
  STF_EQUAL(bs::arg(r5),  -3*bs::Pi<T>()/4);
}

STF_CASE_TPL( "Complex pedantic_(arg) on complex<T>", STF_IEEE_TYPES)
{
  bs::complex<T> r0(0,4), r1(4,0), r2(3,3), r3(-1,0), r4(0,-1), r5(-2,-2);
  using bs::arg;

  STF_EQUAL(bs::pedantic_(arg)(r0),  bs::Pi<T>()/2);
  STF_EQUAL(bs::pedantic_(arg)(r1),  bs::Zero<T>());
  STF_EQUAL(bs::pedantic_(arg)(r2),  bs::Pi<T>()/4);    ;
  STF_EQUAL(bs::pedantic_(arg)(r3),  bs::Pi<T>());
  STF_EQUAL(bs::pedantic_(arg)(r4),  -bs::Pi<T>()/2);
  STF_EQUAL(bs::pedantic_(arg)(r5),  -3*bs::Pi<T>()/4);
}

