---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-unit-test/wavelet-matrix.test.cpp
    title: verify/verify-unit-test/wavelet-matrix.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/data-structure-2d/wavelet-matrix.md
    document_title: Wavelet Matrix
    links: []
  bundledCode: "#line 2 \"data-structure-2d/wavelet-matrix.hpp\"\n\n#include <immintrin.h>\n\
    \nstruct bit_vector {\n  using u32 = uint32_t;\n  using i64 = int64_t;\n  using\
    \ u64 = uint64_t;\n\n  static constexpr u32 w = 64;\n  vector<u64> block;\n  vector<u32>\
    \ count;\n  u32 n, zeros;\n\n  inline u32 get(u32 i) const { return u32(block[i\
    \ / w] >> (i % w)) & 1u; }\n  inline void set(u32 i) { block[i / w] |= 1LL <<\
    \ (i % w); }\n\n  bit_vector() {}\n  bit_vector(int _n) { init(_n); }\n  __attribute__((optimize(\"\
    O3\", \"unroll-loops\"))) void init(int _n) {\n    n = zeros = _n;\n    block.resize(n\
    \ / w + 1, 0);\n    count.resize(block.size(), 0);\n  }\n\n  __attribute__((target(\"\
    popcnt\"))) void build() {\n    for (u32 i = 1; i < block.size(); ++i)\n     \
    \ count[i] = count[i - 1] + _mm_popcnt_u64(block[i - 1]);\n    zeros = rank0(n);\n\
    \  }\n\n  inline u32 rank0(u32 i) const { return i - rank1(i); }\n  __attribute__((target(\"\
    bmi2,popcnt\"))) inline u32 rank1(u32 i) const {\n    return count[i / w] + _mm_popcnt_u64(_bzhi_u64(block[i\
    \ / w], i % w));\n  }\n};\n\ntemplate <typename T>\nstruct WaveletMatrix {\n \
    \ using u32 = uint32_t;\n  using i64 = int64_t;\n  using u64 = uint64_t;\n\n \
    \ int n, lg;\n  vector<T> a;\n  vector<bit_vector> bv;\n\n  WaveletMatrix(u32\
    \ _n) : n(max<u32>(_n, 1)), a(n) {}\n  WaveletMatrix(const vector<T>& _a) : n(_a.size()),\
    \ a(_a) { build(); }\n\n  __attribute__((optimize(\"O3\"))) void build() {\n \
    \   lg = __lg(max<T>(*max_element(begin(a), end(a)), 1)) + 1;\n    bv.assign(lg,\
    \ n);\n    vector<T> cur = a, nxt(n);\n    for (int h = lg - 1; h >= 0; --h) {\n\
    \      for (int i = 0; i < n; ++i)\n        if ((cur[i] >> h) & 1) bv[h].set(i);\n\
    \      bv[h].build();\n      array<decltype(begin(nxt)), 2> it{begin(nxt), begin(nxt)\
    \ + bv[h].zeros};\n      for (int i = 0; i < n; ++i) *it[bv[h].get(i)]++ = cur[i];\n\
    \      swap(cur, nxt);\n    }\n    return;\n  }\n\n  void set(u32 i, const T&\
    \ x) { a[i] = x; }\n\n  inline pair<u32, u32> succ0(int l, int r, int h) const\
    \ {\n    return make_pair(bv[h].rank0(l), bv[h].rank0(r));\n  }\n\n  inline pair<u32,\
    \ u32> succ1(int l, int r, int h) const {\n    u32 l0 = bv[h].rank0(l);\n    u32\
    \ r0 = bv[h].rank0(r);\n    u32 zeros = bv[h].zeros;\n    return make_pair(l +\
    \ zeros - l0, r + zeros - r0);\n  }\n\n  // return a[k]\n  T access(u32 k) const\
    \ {\n    T ret = 0;\n    for (int h = lg - 1; h >= 0; --h) {\n      u32 f = bv[h].get(k);\n\
    \      ret |= f ? T(1) << h : 0;\n      k = f ? bv[h].rank1(k) + bv[h].zeros :\
    \ bv[h].rank0(k);\n    }\n    return ret;\n  }\n\n  // k-th (0-indexed) smallest\
    \ number in a[l, r)\n  T kth_smallest(u32 l, u32 r, u32 k) const {\n    T res\
    \ = 0;\n    for (int h = lg - 1; h >= 0; --h) {\n      u32 l0 = bv[h].rank0(l),\
    \ r0 = bv[h].rank0(r);\n      if (k < r0 - l0)\n        l = l0, r = r0;\n    \
    \  else {\n        k -= r0 - l0;\n        res |= (T)1 << h;\n        l += bv[h].zeros\
    \ - l0;\n        r += bv[h].zeros - r0;\n      }\n    }\n    return res;\n  }\n\
    \n  // k-th (0-indexed) largest number in a[l, r)\n  T kth_largest(int l, int\
    \ r, int k) {\n    return kth_smallest(l, r, r - l - k - 1);\n  }\n\n  // count\
    \ i s.t. (l <= i < r) && (v[i] < upper)\n  int range_freq(int l, int r, T upper)\
    \ {\n    if (upper >= (T(1) << lg)) return r - l;\n    int ret = 0;\n    for (int\
    \ h = lg - 1; h >= 0; --h) {\n      bool f = (upper >> h) & 1;\n      u32 l0 =\
    \ bv[h].rank0(l), r0 = bv[h].rank0(r);\n      if (f) {\n        ret += r0 - l0;\n\
    \        l += bv[h].zeros - l0;\n        r += bv[h].zeros - r0;\n      } else\
    \ {\n        l = l0;\n        r = r0;\n      }\n    }\n    return ret;\n  }\n\n\
    \  int range_freq(int l, int r, T lower, T upper) {\n    return range_freq(l,\
    \ r, upper) - range_freq(l, r, lower);\n  }\n\n  // max v[i] s.t. (l <= i < r)\
    \ && (v[i] < upper)\n  T prev_value(int l, int r, T upper) {\n    int cnt = range_freq(l,\
    \ r, upper);\n    return cnt == 0 ? T(-1) : kth_smallest(l, r, cnt - 1);\n  }\n\
    \n  // min v[i] s.t. (l <= i < r) && (lower <= v[i])\n  T next_value(int l, int\
    \ r, T lower) {\n    int cnt = range_freq(l, r, lower);\n    return cnt == r -\
    \ l ? T(-1) : kth_smallest(l, r, cnt);\n  }\n};\n\n/*\n * @brief Wavelet Matrix\n\
    \ * @docs docs/data-structure-2d/wavelet-matrix.md\n */\n"
  code: "#pragma once\n\n#include <immintrin.h>\n\nstruct bit_vector {\n  using u32\
    \ = uint32_t;\n  using i64 = int64_t;\n  using u64 = uint64_t;\n\n  static constexpr\
    \ u32 w = 64;\n  vector<u64> block;\n  vector<u32> count;\n  u32 n, zeros;\n\n\
    \  inline u32 get(u32 i) const { return u32(block[i / w] >> (i % w)) & 1u; }\n\
    \  inline void set(u32 i) { block[i / w] |= 1LL << (i % w); }\n\n  bit_vector()\
    \ {}\n  bit_vector(int _n) { init(_n); }\n  __attribute__((optimize(\"O3\", \"\
    unroll-loops\"))) void init(int _n) {\n    n = zeros = _n;\n    block.resize(n\
    \ / w + 1, 0);\n    count.resize(block.size(), 0);\n  }\n\n  __attribute__((target(\"\
    popcnt\"))) void build() {\n    for (u32 i = 1; i < block.size(); ++i)\n     \
    \ count[i] = count[i - 1] + _mm_popcnt_u64(block[i - 1]);\n    zeros = rank0(n);\n\
    \  }\n\n  inline u32 rank0(u32 i) const { return i - rank1(i); }\n  __attribute__((target(\"\
    bmi2,popcnt\"))) inline u32 rank1(u32 i) const {\n    return count[i / w] + _mm_popcnt_u64(_bzhi_u64(block[i\
    \ / w], i % w));\n  }\n};\n\ntemplate <typename T>\nstruct WaveletMatrix {\n \
    \ using u32 = uint32_t;\n  using i64 = int64_t;\n  using u64 = uint64_t;\n\n \
    \ int n, lg;\n  vector<T> a;\n  vector<bit_vector> bv;\n\n  WaveletMatrix(u32\
    \ _n) : n(max<u32>(_n, 1)), a(n) {}\n  WaveletMatrix(const vector<T>& _a) : n(_a.size()),\
    \ a(_a) { build(); }\n\n  __attribute__((optimize(\"O3\"))) void build() {\n \
    \   lg = __lg(max<T>(*max_element(begin(a), end(a)), 1)) + 1;\n    bv.assign(lg,\
    \ n);\n    vector<T> cur = a, nxt(n);\n    for (int h = lg - 1; h >= 0; --h) {\n\
    \      for (int i = 0; i < n; ++i)\n        if ((cur[i] >> h) & 1) bv[h].set(i);\n\
    \      bv[h].build();\n      array<decltype(begin(nxt)), 2> it{begin(nxt), begin(nxt)\
    \ + bv[h].zeros};\n      for (int i = 0; i < n; ++i) *it[bv[h].get(i)]++ = cur[i];\n\
    \      swap(cur, nxt);\n    }\n    return;\n  }\n\n  void set(u32 i, const T&\
    \ x) { a[i] = x; }\n\n  inline pair<u32, u32> succ0(int l, int r, int h) const\
    \ {\n    return make_pair(bv[h].rank0(l), bv[h].rank0(r));\n  }\n\n  inline pair<u32,\
    \ u32> succ1(int l, int r, int h) const {\n    u32 l0 = bv[h].rank0(l);\n    u32\
    \ r0 = bv[h].rank0(r);\n    u32 zeros = bv[h].zeros;\n    return make_pair(l +\
    \ zeros - l0, r + zeros - r0);\n  }\n\n  // return a[k]\n  T access(u32 k) const\
    \ {\n    T ret = 0;\n    for (int h = lg - 1; h >= 0; --h) {\n      u32 f = bv[h].get(k);\n\
    \      ret |= f ? T(1) << h : 0;\n      k = f ? bv[h].rank1(k) + bv[h].zeros :\
    \ bv[h].rank0(k);\n    }\n    return ret;\n  }\n\n  // k-th (0-indexed) smallest\
    \ number in a[l, r)\n  T kth_smallest(u32 l, u32 r, u32 k) const {\n    T res\
    \ = 0;\n    for (int h = lg - 1; h >= 0; --h) {\n      u32 l0 = bv[h].rank0(l),\
    \ r0 = bv[h].rank0(r);\n      if (k < r0 - l0)\n        l = l0, r = r0;\n    \
    \  else {\n        k -= r0 - l0;\n        res |= (T)1 << h;\n        l += bv[h].zeros\
    \ - l0;\n        r += bv[h].zeros - r0;\n      }\n    }\n    return res;\n  }\n\
    \n  // k-th (0-indexed) largest number in a[l, r)\n  T kth_largest(int l, int\
    \ r, int k) {\n    return kth_smallest(l, r, r - l - k - 1);\n  }\n\n  // count\
    \ i s.t. (l <= i < r) && (v[i] < upper)\n  int range_freq(int l, int r, T upper)\
    \ {\n    if (upper >= (T(1) << lg)) return r - l;\n    int ret = 0;\n    for (int\
    \ h = lg - 1; h >= 0; --h) {\n      bool f = (upper >> h) & 1;\n      u32 l0 =\
    \ bv[h].rank0(l), r0 = bv[h].rank0(r);\n      if (f) {\n        ret += r0 - l0;\n\
    \        l += bv[h].zeros - l0;\n        r += bv[h].zeros - r0;\n      } else\
    \ {\n        l = l0;\n        r = r0;\n      }\n    }\n    return ret;\n  }\n\n\
    \  int range_freq(int l, int r, T lower, T upper) {\n    return range_freq(l,\
    \ r, upper) - range_freq(l, r, lower);\n  }\n\n  // max v[i] s.t. (l <= i < r)\
    \ && (v[i] < upper)\n  T prev_value(int l, int r, T upper) {\n    int cnt = range_freq(l,\
    \ r, upper);\n    return cnt == 0 ? T(-1) : kth_smallest(l, r, cnt - 1);\n  }\n\
    \n  // min v[i] s.t. (l <= i < r) && (lower <= v[i])\n  T next_value(int l, int\
    \ r, T lower) {\n    int cnt = range_freq(l, r, lower);\n    return cnt == r -\
    \ l ? T(-1) : kth_smallest(l, r, cnt);\n  }\n};\n\n/*\n * @brief Wavelet Matrix\n\
    \ * @docs docs/data-structure-2d/wavelet-matrix.md\n */\n"
  dependsOn: []
  isVerificationFile: false
  path: data-structure-2d/wavelet-matrix.hpp
  requiredBy: []
  timestamp: '2021-11-15 21:11:20+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-unit-test/wavelet-matrix.test.cpp
documentation_of: data-structure-2d/wavelet-matrix.hpp
layout: document
redirect_from:
- /library/data-structure-2d/wavelet-matrix.hpp
- /library/data-structure-2d/wavelet-matrix.hpp.html
title: Wavelet Matrix
---
## Wavelet Matrix

#### 概要

数列に対する様々なクエリを$\mathrm{O}(\log N)$で行えるデータ構造。定数倍も比較的軽い。

二次元クエリの処理に使われることが多く、例えばBITを上に載せることで矩形和・一点加算のクエリを処理できるようになる。[実装](https://nyaannyaan.github.io/library/data-structure-2d/fenwick-tree-on-wavelet-matrix.hpp)　また、bit vectorを平衡二分木に変えることで動的なクエリが処理できるようになる。(未実装…)

#### 使い方

- `WaveletMatrix(n)`: 要素数nのWaveletMatrixを生成する。
- `set(i, x)`:　i番目の要素にxを代入する。
- `build()`:　データ構造を構築する。(これ以降`set(i, x)`を呼び出してはいけない。)
- `accsess(k)`: k番目の要素の値を得る。
- `kth_smallest(l, r, k)`:　`[l, r)`の範囲でk(0-indexed)番目に小さい値を返す。
- `kth_largest(l, r, k)`:　`[l, r)`の範囲でk(0-indexed)番目に大きい値を返す。
- `range_freq(l, r, upper)`: `[l, r)`の範囲でupper未満の要素の個数を返す。
- `prev_value(l, r, lower)`: `l, r`の範囲でupper未満の最後の値を返す。
- `prev_value(l, r, lower)`: `l, r`の範囲でlower以上の最初の値を返す。
