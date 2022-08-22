---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: graph/graph-template.hpp
    title: "\u30B0\u30E9\u30D5\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-aoj-grl/aoj-grl-3-c.test.cpp
    title: verify/verify-aoj-grl/aoj-grl-3-c.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-graph/yosupo-strongly-connected-components.test.cpp
    title: verify/verify-yosupo-graph/yosupo-strongly-connected-components.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graph/strongly-connected-components.hpp\"\n\n#line 2 \"\
    graph/graph-template.hpp\"\n\ntemplate <typename T>\nstruct edge {\n  int src,\
    \ to;\n  T cost;\n\n  edge(int _to, T _cost) : src(-1), to(_to), cost(_cost) {}\n\
    \  edge(int _src, int _to, T _cost) : src(_src), to(_to), cost(_cost) {}\n\n \
    \ edge &operator=(const int &x) {\n    to = x;\n    return *this;\n  }\n\n  operator\
    \ int() const { return to; }\n};\ntemplate <typename T>\nusing Edges = vector<edge<T>>;\n\
    template <typename T>\nusing WeightedGraph = vector<Edges<T>>;\nusing UnweightedGraph\
    \ = vector<vector<int>>;\n\n// Input of (Unweighted) Graph\nUnweightedGraph graph(int\
    \ N, int M = -1, bool is_directed = false,\n                      bool is_1origin\
    \ = true) {\n  UnweightedGraph g(N);\n  if (M == -1) M = N - 1;\n  for (int _\
    \ = 0; _ < M; _++) {\n    int x, y;\n    cin >> x >> y;\n    if (is_1origin) x--,\
    \ y--;\n    g[x].push_back(y);\n    if (!is_directed) g[y].push_back(x);\n  }\n\
    \  return g;\n}\n\n// Input of Weighted Graph\ntemplate <typename T>\nWeightedGraph<T>\
    \ wgraph(int N, int M = -1, bool is_directed = false,\n                      \
    \  bool is_1origin = true) {\n  WeightedGraph<T> g(N);\n  if (M == -1) M = N -\
    \ 1;\n  for (int _ = 0; _ < M; _++) {\n    int x, y;\n    cin >> x >> y;\n   \
    \ T c;\n    cin >> c;\n    if (is_1origin) x--, y--;\n    g[x].emplace_back(x,\
    \ y, c);\n    if (!is_directed) g[y].emplace_back(y, x, c);\n  }\n  return g;\n\
    }\n\n// Input of Edges\ntemplate <typename T>\nEdges<T> esgraph(int N, int M,\
    \ int is_weighted = true, bool is_1origin = true) {\n  Edges<T> es;\n  for (int\
    \ _ = 0; _ < M; _++) {\n    int x, y;\n    cin >> x >> y;\n    T c;\n    if (is_weighted)\n\
    \      cin >> c;\n    else\n      c = 1;\n    if (is_1origin) x--, y--;\n    es.emplace_back(x,\
    \ y, c);\n  }\n  return es;\n}\n\n// Input of Adjacency Matrix\ntemplate <typename\
    \ T>\nvector<vector<T>> adjgraph(int N, int M, T INF, int is_weighted = true,\n\
    \                           bool is_directed = false, bool is_1origin = true)\
    \ {\n  vector<vector<T>> d(N, vector<T>(N, INF));\n  for (int _ = 0; _ < M; _++)\
    \ {\n    int x, y;\n    cin >> x >> y;\n    T c;\n    if (is_weighted)\n     \
    \ cin >> c;\n    else\n      c = 1;\n    if (is_1origin) x--, y--;\n    d[x][y]\
    \ = c;\n    if (!is_directed) d[y][x] = c;\n  }\n  return d;\n}\n\n/**\n * @brief\
    \ \u30B0\u30E9\u30D5\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8\n * @docs docs/graph/graph-template.md\n\
    \ */\n#line 4 \"graph/strongly-connected-components.hpp\"\n\n// Strongly Connected\
    \ Components\n// DAG of SC graph   ... scc.dag (including multiedges)\n// new\
    \ node of k     ... scc[k]\n// inv of scc[k] = i ... scc.belong(i)\ntemplate <typename\
    \ G>\nstruct StronglyConnectedComponents {\n private:\n  const G &g;\n  vector<vector<int>>\
    \ rg;\n  vector<int> comp, order;\n  vector<char> used;\n  vector<vector<int>>\
    \ blng;\n\n public:\n  vector<vector<int>> dag;\n  StronglyConnectedComponents(G\
    \ &_g) : g(_g), used(g.size(), 0) { build(); }\n\n  int operator[](int k) { return\
    \ comp[k]; }\n\n  vector<int> &belong(int i) { return blng[i]; }\n\n private:\n\
    \  void dfs(int idx) {\n    if (used[idx]) return;\n    used[idx] = true;\n  \
    \  for (auto to : g[idx]) dfs(int(to));\n    order.push_back(idx);\n  }\n\n  void\
    \ rdfs(int idx, int cnt) {\n    if (comp[idx] != -1) return;\n    comp[idx] =\
    \ cnt;\n    for (int to : rg[idx]) rdfs(to, cnt);\n  }\n\n  void build() {\n \
    \   for (int i = 0; i < (int)g.size(); i++) dfs(i);\n    reverse(begin(order),\
    \ end(order));\n    used.clear();\n    used.shrink_to_fit();\n\n    comp.resize(g.size(),\
    \ -1);\n\n    rg.resize(g.size());\n    for (int i = 0; i < (int)g.size(); i++)\
    \ {\n      for (auto e : g[i]) {\n        rg[(int)e].emplace_back(i);\n      }\n\
    \    }\n    int ptr = 0;\n    for (int i : order)\n      if (comp[i] == -1) rdfs(i,\
    \ ptr), ptr++;\n    rg.clear();\n    rg.shrink_to_fit();\n    order.clear();\n\
    \    order.shrink_to_fit();\n\n    dag.resize(ptr);\n    blng.resize(ptr);\n \
    \   for (int i = 0; i < (int)g.size(); i++) {\n      blng[comp[i]].push_back(i);\n\
    \      for (auto &to : g[i]) {\n        int x = comp[i], y = comp[to];\n     \
    \   if (x == y) continue;\n        dag[x].push_back(y);\n      }\n    }\n  }\n\
    };\n"
  code: "#pragma once\n\n#include \"./graph-template.hpp\"\n\n// Strongly Connected\
    \ Components\n// DAG of SC graph   ... scc.dag (including multiedges)\n// new\
    \ node of k     ... scc[k]\n// inv of scc[k] = i ... scc.belong(i)\ntemplate <typename\
    \ G>\nstruct StronglyConnectedComponents {\n private:\n  const G &g;\n  vector<vector<int>>\
    \ rg;\n  vector<int> comp, order;\n  vector<char> used;\n  vector<vector<int>>\
    \ blng;\n\n public:\n  vector<vector<int>> dag;\n  StronglyConnectedComponents(G\
    \ &_g) : g(_g), used(g.size(), 0) { build(); }\n\n  int operator[](int k) { return\
    \ comp[k]; }\n\n  vector<int> &belong(int i) { return blng[i]; }\n\n private:\n\
    \  void dfs(int idx) {\n    if (used[idx]) return;\n    used[idx] = true;\n  \
    \  for (auto to : g[idx]) dfs(int(to));\n    order.push_back(idx);\n  }\n\n  void\
    \ rdfs(int idx, int cnt) {\n    if (comp[idx] != -1) return;\n    comp[idx] =\
    \ cnt;\n    for (int to : rg[idx]) rdfs(to, cnt);\n  }\n\n  void build() {\n \
    \   for (int i = 0; i < (int)g.size(); i++) dfs(i);\n    reverse(begin(order),\
    \ end(order));\n    used.clear();\n    used.shrink_to_fit();\n\n    comp.resize(g.size(),\
    \ -1);\n\n    rg.resize(g.size());\n    for (int i = 0; i < (int)g.size(); i++)\
    \ {\n      for (auto e : g[i]) {\n        rg[(int)e].emplace_back(i);\n      }\n\
    \    }\n    int ptr = 0;\n    for (int i : order)\n      if (comp[i] == -1) rdfs(i,\
    \ ptr), ptr++;\n    rg.clear();\n    rg.shrink_to_fit();\n    order.clear();\n\
    \    order.shrink_to_fit();\n\n    dag.resize(ptr);\n    blng.resize(ptr);\n \
    \   for (int i = 0; i < (int)g.size(); i++) {\n      blng[comp[i]].push_back(i);\n\
    \      for (auto &to : g[i]) {\n        int x = comp[i], y = comp[to];\n     \
    \   if (x == y) continue;\n        dag[x].push_back(y);\n      }\n    }\n  }\n\
    };\n"
  dependsOn:
  - graph/graph-template.hpp
  isVerificationFile: false
  path: graph/strongly-connected-components.hpp
  requiredBy: []
  timestamp: '2021-11-23 10:22:25+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-yosupo-graph/yosupo-strongly-connected-components.test.cpp
  - verify/verify-aoj-grl/aoj-grl-3-c.test.cpp
documentation_of: graph/strongly-connected-components.hpp
layout: document
redirect_from:
- /library/graph/strongly-connected-components.hpp
- /library/graph/strongly-connected-components.hpp.html
title: graph/strongly-connected-components.hpp
---
