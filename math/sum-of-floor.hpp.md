---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-unit-test/math.test.cpp
    title: verify/verify-unit-test/math.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-math/yosupo-sum-of-floor.test.cpp
    title: verify/verify-yosupo-math/yosupo-sum-of-floor.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/sum-of-floor.hpp\"\n\n\n\n// sum_{0 <= i < N} (ai +\
    \ b) // m\ntemplate <typename T>\nT sum_of_floor(T n, T m, T a, T b) {\n  T ret\
    \ = 0;\n  if (a >= m) ret += (n - 1) * n * (a / m) / 2, a %= m;\n  if (b >= m)\
    \ ret += n * (b / m), b %= m;\n  T y = (a * n + b) / m;\n  if (y == 0) return\
    \ ret;\n  T x = y * m - b;\n  ret += (n - (x + a - 1) / a) * y;\n  ret += sum_of_floor(y,\
    \ a, m, (a - x % a) % a);\n  return ret;\n}\n\n// verify www.codechef.com/viewsolution/36222026\n\
    // count x : ax + b mod m < yr, 0 <= x < xr\ntemplate <typename T>\nT mod_affine_range_counting(T\
    \ a, T b, T m, T xr, T yr) {\n  assert(0 <= yr && yr <= m);\n  return sum_of_floor(xr,\
    \ m, a, b + m) - sum_of_floor(xr, m, a, b + m - yr);\n}\n"
  code: "#pragma once\n\n\n\n// sum_{0 <= i < N} (ai + b) // m\ntemplate <typename\
    \ T>\nT sum_of_floor(T n, T m, T a, T b) {\n  T ret = 0;\n  if (a >= m) ret +=\
    \ (n - 1) * n * (a / m) / 2, a %= m;\n  if (b >= m) ret += n * (b / m), b %= m;\n\
    \  T y = (a * n + b) / m;\n  if (y == 0) return ret;\n  T x = y * m - b;\n  ret\
    \ += (n - (x + a - 1) / a) * y;\n  ret += sum_of_floor(y, a, m, (a - x % a) %\
    \ a);\n  return ret;\n}\n\n// verify www.codechef.com/viewsolution/36222026\n\
    // count x : ax + b mod m < yr, 0 <= x < xr\ntemplate <typename T>\nT mod_affine_range_counting(T\
    \ a, T b, T m, T xr, T yr) {\n  assert(0 <= yr && yr <= m);\n  return sum_of_floor(xr,\
    \ m, a, b + m) - sum_of_floor(xr, m, a, b + m - yr);\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: math/sum-of-floor.hpp
  requiredBy: []
  timestamp: '2020-12-08 18:07:05+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-unit-test/math.test.cpp
  - verify/verify-yosupo-math/yosupo-sum-of-floor.test.cpp
documentation_of: math/sum-of-floor.hpp
layout: document
redirect_from:
- /library/math/sum-of-floor.hpp
- /library/math/sum-of-floor.hpp.html
title: math/sum-of-floor.hpp
---
