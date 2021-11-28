---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/dynamic-binary-indexed-tree.hpp
    title: "\u52D5\u7684Binary Indexed Tree"
  - icon: ':heavy_check_mark:'
    path: data-structure/hash-map-variable-length.hpp
    title: "Hash Map(\u53EF\u5909\u9577\u7248)"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-ds/yosupo-point-add-rectangle-sum-bit2d.test.cpp
    title: verify/verify-yosupo-ds/yosupo-point-add-rectangle-sum-bit2d.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "\u52D5\u7684\u4E8C\u6B21\u5143Binary Indexed Tree"
    links: []
  bundledCode: "#line 2 \"data-structure-2d/dynamic-binary-indexed-tree-2d.hpp\"\n\
    \n#line 2 \"data-structure/dynamic-binary-indexed-tree.hpp\"\n\n#line 2 \"data-structure/hash-map-variable-length.hpp\"\
    \n\ntemplate <typename Key, typename Val>\nstruct HashMap {\n  using u32 = uint32_t;\n\
    \  using u64 = uint64_t;\n\n  u32 cap, s;\n  vector<Key> keys;\n  vector<Val>\
    \ vals;\n  vector<bool> flag;\n  u64 r;\n  u32 shift;\n  Val DefaultValue;\n\n\
    \  static u64 rng() {\n    u64 m = chrono::duration_cast<chrono::nanoseconds>(\n\
    \                chrono::high_resolution_clock::now().time_since_epoch())\n  \
    \              .count();\n    m ^= m >> 16;\n    m ^= m << 32;\n    return m;\n\
    \  }\n\n  void reallocate() {\n    cap <<= 1;\n    vector<Key> k(cap);\n    vector<Val>\
    \ v(cap);\n    vector<bool> f(cap);\n    u32 sh = shift - 1;\n    for (int i =\
    \ 0; i < (int)flag.size(); i++) {\n      if (flag[i]) {\n        u32 hash = (u64(keys[i])\
    \ * r) >> sh;\n        while (f[hash]) hash = (hash + 1) & (cap - 1);\n      \
    \  k[hash] = keys[i];\n        v[hash] = vals[i];\n        f[hash] = 1;\n    \
    \  }\n    }\n    keys.swap(k);\n    vals.swap(v);\n    flag.swap(f);\n    --shift;\n\
    \  }\n\n  explicit HashMap()\n      : cap(8),\n        s(0),\n        keys(cap),\n\
    \        vals(cap),\n        flag(cap),\n        r(rng()),\n        shift(64 -\
    \ __lg(cap)),\n        DefaultValue(Val()) {}\n\n  Val& operator[](const Key&\
    \ i) {\n    u32 hash = (u64(i) * r) >> shift;\n    while (true) {\n      if (!flag[hash])\
    \ {\n        if (s + s / 4 >= cap) {\n          reallocate();\n          return\
    \ (*this)[i];\n        }\n        keys[hash] = i;\n        flag[hash] = 1;\n \
    \       ++s;\n        return vals[hash] = DefaultValue;\n      }\n      if (keys[hash]\
    \ == i) return vals[hash];\n      hash = (hash + 1) & (cap - 1);\n    }\n  }\n\
    \n  // exist -> return pointer of Val\n  // not exist -> return nullptr\n  const\
    \ Val* find(const Key& i) const {\n    u32 hash = (u64(i) * r) >> shift;\n   \
    \ while (true) {\n      if (!flag[hash]) return nullptr;\n      if (keys[hash]\
    \ == i) return &(vals[hash]);\n      hash = (hash + 1) & (cap - 1);\n    }\n \
    \ }\n\n  // return vector< pair<const Key&, val& > >\n  vector<pair<Key, Val>>\
    \ enumerate() const {\n    vector<pair<Key, Val>> ret;\n    for (u32 i = 0; i\
    \ < cap; ++i)\n      if (flag[i]) ret.emplace_back(keys[i], vals[i]);\n    return\
    \ ret;\n  }\n\n  int size() const { return s; }\n\n  // set default_value\n  void\
    \ set_default(const Val& val) { DefaultValue = val; }\n};\n\n/**\n * @brief Hash\
    \ Map(\u53EF\u5909\u9577\u7248)\n * @docs docs/data-structure/hash-map.md\n */\n\
    #line 4 \"data-structure/dynamic-binary-indexed-tree.hpp\"\n\ntemplate <typename\
    \ S, typename T>\nstruct DynamicFenwickTree {\n  S N;\n  HashMap<S, T> data;\n\
    \  explicit DynamicFenwickTree() = default;\n  explicit DynamicFenwickTree(S size)\
    \ { N = size + 1; }\n\n  void add(S k, T x) {\n    for (++k; k < N; k += k & -k)\
    \ data[k] += x;\n  }\n\n  // [0, k)\n  T sum(S k) const {\n    if (k < 0) return\
    \ 0;\n    T ret = T();\n    for (; k > 0; k -= k & -k) {\n      const T* p = data.find(k);\n\
    \      ret += p ? *p : T();\n    }\n    return ret;\n  }\n\n  // [a, b)\n  T sum(S\
    \ a, S b) const { return sum(b) - sum(a); }\n\n  T operator[](S k) const { return\
    \ sum(k + 1) - sum(k); }\n\n  S lower_bound(T w) {\n    if (w <= 0) return 0;\n\
    \    S x = 0;\n    for (S k = 1 << __lg(N); k; k >>= 1) {\n      if (x + k <=\
    \ N - 1 && data[x + k] < w) {\n        w -= data[x + k];\n        x += k;\n  \
    \    }\n    }\n    return x;\n  }\n};\n\n/**\n * @brief \u52D5\u7684Binary Indexed\
    \ Tree\n * @docs docs/data-structure/dynamic-binary-indexed-tree.md\n */\n#line\
    \ 4 \"data-structure-2d/dynamic-binary-indexed-tree-2d.hpp\"\n\ntemplate <typename\
    \ T>\nstruct DynamicFenwickTree2D {\n  using BIT = DynamicFenwickTree<int, T>;\n\
    \  int N, M;\n  vector<BIT*> bit;\n  DynamicFenwickTree2D() = default;\n  DynamicFenwickTree2D(int\
    \ n, int m) : N(n + 1), M(m) {\n    for (int _ = 0; _ < N; ++_) bit.push_back(new\
    \ BIT(M));\n  }\n  \n  void add(int i, int j, const T& x) {\n    for (++i; i <\
    \ N; i += i & -i) (*bit[i]).add(j, x);\n  }\n\n  // i = [0, n), j = [0, m)\n \
    \ T sum(int n, int m) const {\n    if (n < 0 || m < 0) return T();\n    T ret\
    \ = T();\n    for (; n; n -= n & -n) ret += (*bit[n]).sum(m);\n    return ret;\n\
    \  }\n\n  // i = [nl, nr), j = [ml, mr)\n  T sum(int nl, int ml, int nr, int mr)\
    \ const {\n    T ret = T();\n    while (nl != nr) {\n      if (nl < nr) {\n  \
    \      ret += (*bit[nr]).sum(ml, mr);\n        nr -= nr & -nr;\n      } else {\n\
    \        ret -= (*bit[nl]).sum(ml, mr);\n        nl -= nl & -nl;\n      }\n  \
    \  }\n    return ret;\n  }\n};\n\n/*\n * @brief \u52D5\u7684\u4E8C\u6B21\u5143\
    Binary Indexed Tree\n */\n"
  code: "#pragma once\n\n#include \"../data-structure/dynamic-binary-indexed-tree.hpp\"\
    \n\ntemplate <typename T>\nstruct DynamicFenwickTree2D {\n  using BIT = DynamicFenwickTree<int,\
    \ T>;\n  int N, M;\n  vector<BIT*> bit;\n  DynamicFenwickTree2D() = default;\n\
    \  DynamicFenwickTree2D(int n, int m) : N(n + 1), M(m) {\n    for (int _ = 0;\
    \ _ < N; ++_) bit.push_back(new BIT(M));\n  }\n  \n  void add(int i, int j, const\
    \ T& x) {\n    for (++i; i < N; i += i & -i) (*bit[i]).add(j, x);\n  }\n\n  //\
    \ i = [0, n), j = [0, m)\n  T sum(int n, int m) const {\n    if (n < 0 || m <\
    \ 0) return T();\n    T ret = T();\n    for (; n; n -= n & -n) ret += (*bit[n]).sum(m);\n\
    \    return ret;\n  }\n\n  // i = [nl, nr), j = [ml, mr)\n  T sum(int nl, int\
    \ ml, int nr, int mr) const {\n    T ret = T();\n    while (nl != nr) {\n    \
    \  if (nl < nr) {\n        ret += (*bit[nr]).sum(ml, mr);\n        nr -= nr &\
    \ -nr;\n      } else {\n        ret -= (*bit[nl]).sum(ml, mr);\n        nl -=\
    \ nl & -nl;\n      }\n    }\n    return ret;\n  }\n};\n\n/*\n * @brief \u52D5\u7684\
    \u4E8C\u6B21\u5143Binary Indexed Tree\n */\n"
  dependsOn:
  - data-structure/dynamic-binary-indexed-tree.hpp
  - data-structure/hash-map-variable-length.hpp
  isVerificationFile: false
  path: data-structure-2d/dynamic-binary-indexed-tree-2d.hpp
  requiredBy: []
  timestamp: '2021-11-27 22:15:37+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-yosupo-ds/yosupo-point-add-rectangle-sum-bit2d.test.cpp
documentation_of: data-structure-2d/dynamic-binary-indexed-tree-2d.hpp
layout: document
redirect_from:
- /library/data-structure-2d/dynamic-binary-indexed-tree-2d.hpp
- /library/data-structure-2d/dynamic-binary-indexed-tree-2d.hpp.html
title: "\u52D5\u7684\u4E8C\u6B21\u5143Binary Indexed Tree"
---
