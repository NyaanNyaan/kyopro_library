---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/graph-template.hpp
    title: "\u30B0\u30E9\u30D5\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-aoj-other/aoj-2945-01bfs.test.cpp
    title: verify/verify-aoj-other/aoj-2945-01bfs.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-aoj-other/aoj-3506.test.cpp
    title: verify/verify-aoj-other/aoj-3506.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"shortest-path/bfs01.hpp\"\n\n#line 2 \"graph/graph-template.hpp\"\
    \n\ntemplate <typename T>\nstruct edge {\n  int src, to;\n  T cost;\n\n  edge(int\
    \ _to, T _cost) : src(-1), to(_to), cost(_cost) {}\n  edge(int _src, int _to,\
    \ T _cost) : src(_src), to(_to), cost(_cost) {}\n\n  edge &operator=(const int\
    \ &x) {\n    to = x;\n    return *this;\n  }\n\n  operator int() const { return\
    \ to; }\n};\ntemplate <typename T>\nusing Edges = vector<edge<T>>;\ntemplate <typename\
    \ T>\nusing WeightedGraph = vector<Edges<T>>;\nusing UnweightedGraph = vector<vector<int>>;\n\
    \n// Input of (Unweighted) Graph\nUnweightedGraph graph(int N, int M = -1, bool\
    \ is_directed = false,\n                      bool is_1origin = true) {\n  UnweightedGraph\
    \ g(N);\n  if (M == -1) M = N - 1;\n  for (int _ = 0; _ < M; _++) {\n    int x,\
    \ y;\n    cin >> x >> y;\n    if (is_1origin) x--, y--;\n    g[x].push_back(y);\n\
    \    if (!is_directed) g[y].push_back(x);\n  }\n  return g;\n}\n\n// Input of\
    \ Weighted Graph\ntemplate <typename T>\nWeightedGraph<T> wgraph(int N, int M\
    \ = -1, bool is_directed = false,\n                        bool is_1origin = true)\
    \ {\n  WeightedGraph<T> g(N);\n  if (M == -1) M = N - 1;\n  for (int _ = 0; _\
    \ < M; _++) {\n    int x, y;\n    cin >> x >> y;\n    T c;\n    cin >> c;\n  \
    \  if (is_1origin) x--, y--;\n    g[x].emplace_back(x, y, c);\n    if (!is_directed)\
    \ g[y].emplace_back(y, x, c);\n  }\n  return g;\n}\n\n// Input of Edges\ntemplate\
    \ <typename T>\nEdges<T> esgraph([[maybe_unused]] int N, int M, int is_weighted\
    \ = true,\n                 bool is_1origin = true) {\n  Edges<T> es;\n  for (int\
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
    \ */\n#line 4 \"shortest-path/bfs01.hpp\"\n\n// unreachable -> -1\ntemplate <typename\
    \ T>\nvector<T> bfs01(WeightedGraph<T>& g, int start = 0) {\n  int N = (int)g.size();\n\
    \  vector<T> d(N, -1);\n  vector<int> vis(N, 0);\n  deque<int> Q;\n  d[start]\
    \ = 0;\n  Q.push_back(start);\n  while (!Q.empty()) {\n    int cur = Q.front();\n\
    \    Q.pop_front();\n    if (vis[cur]) continue;\n    vis[cur] = 1;\n    for (auto&\
    \ dst : g[cur]) {\n      if (d[dst] != -1 and d[dst] <= d[cur] + dst.cost) continue;\n\
    \      d[dst] = d[cur] + dst.cost;\n      if (dst.cost == 0) {\n        Q.push_front(dst);\n\
    \      } else {\n        Q.push_back(dst);\n      }\n    }\n  }\n  return d;\n\
    }\n"
  code: "#pragma once\n\n#include \"../graph/graph-template.hpp\"\n\n// unreachable\
    \ -> -1\ntemplate <typename T>\nvector<T> bfs01(WeightedGraph<T>& g, int start\
    \ = 0) {\n  int N = (int)g.size();\n  vector<T> d(N, -1);\n  vector<int> vis(N,\
    \ 0);\n  deque<int> Q;\n  d[start] = 0;\n  Q.push_back(start);\n  while (!Q.empty())\
    \ {\n    int cur = Q.front();\n    Q.pop_front();\n    if (vis[cur]) continue;\n\
    \    vis[cur] = 1;\n    for (auto& dst : g[cur]) {\n      if (d[dst] != -1 and\
    \ d[dst] <= d[cur] + dst.cost) continue;\n      d[dst] = d[cur] + dst.cost;\n\
    \      if (dst.cost == 0) {\n        Q.push_front(dst);\n      } else {\n    \
    \    Q.push_back(dst);\n      }\n    }\n  }\n  return d;\n}\n"
  dependsOn:
  - graph/graph-template.hpp
  isVerificationFile: false
  path: shortest-path/bfs01.hpp
  requiredBy: []
  timestamp: '2024-05-03 23:21:26+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-aoj-other/aoj-3506.test.cpp
  - verify/verify-aoj-other/aoj-2945-01bfs.test.cpp
documentation_of: shortest-path/bfs01.hpp
layout: document
redirect_from:
- /library/shortest-path/bfs01.hpp
- /library/shortest-path/bfs01.hpp.html
title: shortest-path/bfs01.hpp
---
