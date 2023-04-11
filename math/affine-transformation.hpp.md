---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-unit-test/rbst-segment-tree.test.cpp
    title: verify/verify-unit-test/rbst-segment-tree.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-ds/yosupo-dynamic-sequence-range-affine-range-sum-splay.test.cpp
    title: verify/verify-yosupo-ds/yosupo-dynamic-sequence-range-affine-range-sum-splay.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-ds/yosupo-dynamic-sequence-range-affine-range-sum-treap.test.cpp
    title: verify/verify-yosupo-ds/yosupo-dynamic-sequence-range-affine-range-sum-treap.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-ds/yosupo-dynamic-sequence-range-affine-range-sum.test.cpp
    title: verify/verify-yosupo-ds/yosupo-dynamic-sequence-range-affine-range-sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-ds/yosupo-dynamic-tree-vertex-add-path-sum.test.cpp
    title: verify/verify-yosupo-ds/yosupo-dynamic-tree-vertex-add-path-sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-ds/yosupo-dynamic-tree-vertex-set-path-composite.test.cpp
    title: verify/verify-yosupo-ds/yosupo-dynamic-tree-vertex-set-path-composite.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-ds/yosupo-point-set-range-composite-dynamic-segtree.test.cpp
    title: verify/verify-yosupo-ds/yosupo-point-set-range-composite-dynamic-segtree.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-ds/yosupo-point-set-range-composite-rbstseg.test.cpp
    title: verify/verify-yosupo-ds/yosupo-point-set-range-composite-rbstseg.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-ds/yosupo-point-set-range-composite-rbstseg2.test.cpp
    title: verify/verify-yosupo-ds/yosupo-point-set-range-composite-rbstseg2.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-ds/yosupo-range-add-range-sum-linkcuttree.test.cpp
    title: verify/verify-yosupo-ds/yosupo-range-add-range-sum-linkcuttree.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-ds/yosupo-range-affine-range-sum-dynamic-segtree.test.cpp
    title: verify/verify-yosupo-ds/yosupo-range-affine-range-sum-dynamic-segtree.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-ds/yosupo-range-affine-range-sum-rbstseg.test.cpp
    title: verify/verify-yosupo-ds/yosupo-range-affine-range-sum-rbstseg.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-ds/yosupo-range-affine-sqdec.test.cpp
    title: verify/verify-yosupo-ds/yosupo-range-affine-sqdec.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-ds/yosupo-vertex-set-path-composite.test.cpp
    title: verify/verify-yosupo-ds/yosupo-vertex-set-path-composite.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "\u30A2\u30D5\u30A3\u30F3\u5909\u63DB"
    links: []
  bundledCode: "#line 2 \"math/affine-transformation.hpp\"\n\ntemplate <typename mint>\n\
    struct Affine {\n  mint a, b;\n  constexpr Affine() : a(1), b(0) {}\n  constexpr\
    \ Affine(mint _a, mint _b) : a(_a), b(_b) {}\n  mint operator()(mint x) { return\
    \ a * x + b; }\n  // R(L(x))\n  friend Affine operator*(const Affine& l, const\
    \ Affine& r) {\n    return Affine(l.a * r.a, l.b * r.a + r.b);\n  }\n  bool operator==(const\
    \ Affine& r) const { return a == r.a && b == r.b; }\n  bool operator!=(const Affine&\
    \ r) const { return a != r.a || b != r.b; }\n  friend ostream& operator<<(ostream&\
    \ os, const Affine& r) {\n    os << \"( \" << r.a << \", \" << r.b << \" )\";\n\
    \    return os;\n  }\n};\n\n/**\n * @brief \u30A2\u30D5\u30A3\u30F3\u5909\u63DB\
    \n */\n"
  code: "#pragma once\n\ntemplate <typename mint>\nstruct Affine {\n  mint a, b;\n\
    \  constexpr Affine() : a(1), b(0) {}\n  constexpr Affine(mint _a, mint _b) :\
    \ a(_a), b(_b) {}\n  mint operator()(mint x) { return a * x + b; }\n  // R(L(x))\n\
    \  friend Affine operator*(const Affine& l, const Affine& r) {\n    return Affine(l.a\
    \ * r.a, l.b * r.a + r.b);\n  }\n  bool operator==(const Affine& r) const { return\
    \ a == r.a && b == r.b; }\n  bool operator!=(const Affine& r) const { return a\
    \ != r.a || b != r.b; }\n  friend ostream& operator<<(ostream& os, const Affine&\
    \ r) {\n    os << \"( \" << r.a << \", \" << r.b << \" )\";\n    return os;\n\
    \  }\n};\n\n/**\n * @brief \u30A2\u30D5\u30A3\u30F3\u5909\u63DB\n */\n"
  dependsOn: []
  isVerificationFile: false
  path: math/affine-transformation.hpp
  requiredBy: []
  timestamp: '2023-03-24 20:50:25+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-yosupo-ds/yosupo-dynamic-tree-vertex-add-path-sum.test.cpp
  - verify/verify-yosupo-ds/yosupo-point-set-range-composite-dynamic-segtree.test.cpp
  - verify/verify-yosupo-ds/yosupo-dynamic-sequence-range-affine-range-sum-splay.test.cpp
  - verify/verify-yosupo-ds/yosupo-point-set-range-composite-rbstseg.test.cpp
  - verify/verify-yosupo-ds/yosupo-range-affine-sqdec.test.cpp
  - verify/verify-yosupo-ds/yosupo-range-affine-range-sum-dynamic-segtree.test.cpp
  - verify/verify-yosupo-ds/yosupo-dynamic-sequence-range-affine-range-sum-treap.test.cpp
  - verify/verify-yosupo-ds/yosupo-vertex-set-path-composite.test.cpp
  - verify/verify-yosupo-ds/yosupo-dynamic-tree-vertex-set-path-composite.test.cpp
  - verify/verify-yosupo-ds/yosupo-range-add-range-sum-linkcuttree.test.cpp
  - verify/verify-yosupo-ds/yosupo-range-affine-range-sum-rbstseg.test.cpp
  - verify/verify-yosupo-ds/yosupo-dynamic-sequence-range-affine-range-sum.test.cpp
  - verify/verify-yosupo-ds/yosupo-point-set-range-composite-rbstseg2.test.cpp
  - verify/verify-unit-test/rbst-segment-tree.test.cpp
documentation_of: math/affine-transformation.hpp
layout: document
redirect_from:
- /library/math/affine-transformation.hpp
- /library/math/affine-transformation.hpp.html
title: "\u30A2\u30D5\u30A3\u30F3\u5909\u63DB"
---
