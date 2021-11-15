---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/graph-template.hpp
    title: graph/graph-template.hpp
  - icon: ':heavy_check_mark:'
    path: segment-tree/segment-tree.hpp
    title: segment-tree/segment-tree.hpp
  - icon: ':heavy_check_mark:'
    path: template/bitop.hpp
    title: template/bitop.hpp
  - icon: ':heavy_check_mark:'
    path: template/debug.hpp
    title: template/debug.hpp
  - icon: ':heavy_check_mark:'
    path: template/inout.hpp
    title: template/inout.hpp
  - icon: ':heavy_check_mark:'
    path: template/macro.hpp
    title: template/macro.hpp
  - icon: ':heavy_check_mark:'
    path: template/template.hpp
    title: template/template.hpp
  - icon: ':heavy_check_mark:'
    path: template/util.hpp
    title: template/util.hpp
  - icon: ':heavy_check_mark:'
    path: tree/heavy-light-decomposition.hpp
    title: "Heavy Light Decomposition(\u91CD\u8EFD\u5206\u89E3)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/vertex_add_subtree_sum
    links:
    - https://judge.yosupo.jp/problem/vertex_add_subtree_sum
  bundledCode: "#line 1 \"verify/verify-yosupo-ds/yosupo-vertex-add-subtree-sum.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/vertex_add_subtree_sum\"\n\
    \n#line 2 \"template/template.hpp\"\nusing namespace std;\n\n// intrinstic\n#include\
    \ <immintrin.h>\n\n#include <algorithm>\n#include <array>\n#include <bitset>\n\
    #include <cassert>\n#include <cctype>\n#include <cfenv>\n#include <cfloat>\n#include\
    \ <chrono>\n#include <cinttypes>\n#include <climits>\n#include <cmath>\n#include\
    \ <complex>\n#include <cstdarg>\n#include <cstddef>\n#include <cstdint>\n#include\
    \ <cstdio>\n#include <cstdlib>\n#include <cstring>\n#include <deque>\n#include\
    \ <fstream>\n#include <functional>\n#include <initializer_list>\n#include <iomanip>\n\
    #include <ios>\n#include <iostream>\n#include <istream>\n#include <iterator>\n\
    #include <limits>\n#include <list>\n#include <map>\n#include <memory>\n#include\
    \ <new>\n#include <numeric>\n#include <ostream>\n#include <queue>\n#include <random>\n\
    #include <set>\n#include <sstream>\n#include <stack>\n#include <streambuf>\n#include\
    \ <string>\n#include <tuple>\n#include <type_traits>\n#include <typeinfo>\n#include\
    \ <unordered_map>\n#include <unordered_set>\n#include <utility>\n#include <vector>\n\
    \n// utility\n#line 1 \"template/util.hpp\"\nnamespace Nyaan {\nusing ll = long\
    \ long;\nusing i64 = long long;\nusing u64 = unsigned long long;\nusing i128 =\
    \ __int128_t;\nusing u128 = __uint128_t;\n\ntemplate <typename T>\nusing V = vector<T>;\n\
    template <typename T>\nusing VV = vector<vector<T>>;\nusing vi = vector<int>;\n\
    using vl = vector<long long>;\nusing vd = V<double>;\nusing vs = V<string>;\n\
    using vvi = vector<vector<int>>;\nusing vvl = vector<vector<long long>>;\n\ntemplate\
    \ <typename T, typename U>\nstruct P : pair<T, U> {\n  template <typename... Args>\n\
    \  P(Args... args) : pair<T, U>(args...) {}\n\n  using pair<T, U>::first;\n  using\
    \ pair<T, U>::second;\n\n  T &x() { return first; }\n  const T &x() const { return\
    \ first; }\n  U &y() { return second; }\n  const U &y() const { return second;\
    \ }\n\n  P &operator+=(const P &r) {\n    first += r.first;\n    second += r.second;\n\
    \    return *this;\n  }\n  P &operator-=(const P &r) {\n    first -= r.first;\n\
    \    second -= r.second;\n    return *this;\n  }\n  P &operator*=(const P &r)\
    \ {\n    first *= r.first;\n    second *= r.second;\n    return *this;\n  }\n\
    \  P operator+(const P &r) const { return P(*this) += r; }\n  P operator-(const\
    \ P &r) const { return P(*this) -= r; }\n  P operator*(const P &r) const { return\
    \ P(*this) *= r; }\n};\n\nusing pl = P<ll, ll>;\nusing pi = P<int, int>;\nusing\
    \ vp = V<pl>;\n\nconstexpr int inf = 1001001001;\nconstexpr long long infLL =\
    \ 4004004004004004004LL;\n\ntemplate <typename T>\nint sz(const T &t) {\n  return\
    \ t.size();\n}\n\ntemplate <typename T, typename U>\ninline bool amin(T &x, U\
    \ y) {\n  return (y < x) ? (x = y, true) : false;\n}\ntemplate <typename T, typename\
    \ U>\ninline bool amax(T &x, U y) {\n  return (x < y) ? (x = y, true) : false;\n\
    }\n\ntemplate <typename T>\ninline T Max(const vector<T> &v) {\n  return *max_element(begin(v),\
    \ end(v));\n}\ntemplate <typename T>\ninline T Min(const vector<T> &v) {\n  return\
    \ *min_element(begin(v), end(v));\n}\ntemplate <typename T>\ninline long long\
    \ Sum(const vector<T> &v) {\n  return accumulate(begin(v), end(v), 0LL);\n}\n\n\
    template <typename T>\nint lb(const vector<T> &v, const T &a) {\n  return lower_bound(begin(v),\
    \ end(v), a) - begin(v);\n}\ntemplate <typename T>\nint ub(const vector<T> &v,\
    \ const T &a) {\n  return upper_bound(begin(v), end(v), a) - begin(v);\n}\n\n\
    constexpr long long TEN(int n) {\n  long long ret = 1, x = 10;\n  for (; n; x\
    \ *= x, n >>= 1) ret *= (n & 1 ? x : 1);\n  return ret;\n}\n\ntemplate <typename\
    \ T, typename U>\npair<T, U> mkp(const T &t, const U &u) {\n  return make_pair(t,\
    \ u);\n}\n\ntemplate <typename T>\nvector<T> mkrui(const vector<T> &v, bool rev\
    \ = false) {\n  vector<T> ret(v.size() + 1);\n  if (rev) {\n    for (int i = int(v.size())\
    \ - 1; i >= 0; i--) ret[i] = v[i] + ret[i + 1];\n  } else {\n    for (int i =\
    \ 0; i < int(v.size()); i++) ret[i + 1] = ret[i] + v[i];\n  }\n  return ret;\n\
    };\n\ntemplate <typename T>\nvector<T> mkuni(const vector<T> &v) {\n  vector<T>\
    \ ret(v);\n  sort(ret.begin(), ret.end());\n  ret.erase(unique(ret.begin(), ret.end()),\
    \ ret.end());\n  return ret;\n}\n\ntemplate <typename F>\nvector<int> mkord(int\
    \ N, F f) {\n  vector<int> ord(N);\n  iota(begin(ord), end(ord), 0);\n  sort(begin(ord),\
    \ end(ord), f);\n  return ord;\n}\n\ntemplate <typename T>\nvector<int> mkinv(vector<T>\
    \ &v) {\n  int max_val = *max_element(begin(v), end(v));\n  vector<int> inv(max_val\
    \ + 1, -1);\n  for (int i = 0; i < (int)v.size(); i++) inv[v[i]] = i;\n  return\
    \ inv;\n}\n\n}  // namespace Nyaan\n#line 58 \"template/template.hpp\"\n\n// bit\
    \ operation\n#line 1 \"template/bitop.hpp\"\nnamespace Nyaan {\n__attribute__((target(\"\
    popcnt\"))) inline int popcnt(const u64 &a) {\n  return _mm_popcnt_u64(a);\n}\n\
    inline int lsb(const u64 &a) { return a ? __builtin_ctzll(a) : 64; }\ninline int\
    \ ctz(const u64 &a) { return a ? __builtin_ctzll(a) : 64; }\ninline int msb(const\
    \ u64 &a) { return a ? 63 - __builtin_clzll(a) : -1; }\ntemplate <typename T>\n\
    inline int gbit(const T &a, int i) {\n  return (a >> i) & 1;\n}\ntemplate <typename\
    \ T>\ninline void sbit(T &a, int i, bool b) {\n  if (gbit(a, i) != b) a ^= T(1)\
    \ << i;\n}\nconstexpr long long PW(int n) { return 1LL << n; }\nconstexpr long\
    \ long MSK(int n) { return (1LL << n) - 1; }\n}  // namespace Nyaan\n#line 61\
    \ \"template/template.hpp\"\n\n// inout\n#line 1 \"template/inout.hpp\"\nnamespace\
    \ Nyaan {\n\ntemplate <typename T, typename U>\nostream &operator<<(ostream &os,\
    \ const pair<T, U> &p) {\n  os << p.first << \" \" << p.second;\n  return os;\n\
    }\ntemplate <typename T, typename U>\nistream &operator>>(istream &is, pair<T,\
    \ U> &p) {\n  is >> p.first >> p.second;\n  return is;\n}\n\ntemplate <typename\
    \ T>\nostream &operator<<(ostream &os, const vector<T> &v) {\n  int s = (int)v.size();\n\
    \  for (int i = 0; i < s; i++) os << (i ? \" \" : \"\") << v[i];\n  return os;\n\
    }\ntemplate <typename T>\nistream &operator>>(istream &is, vector<T> &v) {\n \
    \ for (auto &x : v) is >> x;\n  return is;\n}\n\nvoid in() {}\ntemplate <typename\
    \ T, class... U>\nvoid in(T &t, U &... u) {\n  cin >> t;\n  in(u...);\n}\n\nvoid\
    \ out() { cout << \"\\n\"; }\ntemplate <typename T, class... U, char sep = ' '>\n\
    void out(const T &t, const U &... u) {\n  cout << t;\n  if (sizeof...(u)) cout\
    \ << sep;\n  out(u...);\n}\n\nvoid outr() {}\ntemplate <typename T, class... U,\
    \ char sep = ' '>\nvoid outr(const T &t, const U &... u) {\n  cout << t;\n  outr(u...);\n\
    }\n\nstruct IoSetupNya {\n  IoSetupNya() {\n    cin.tie(nullptr);\n    ios::sync_with_stdio(false);\n\
    \    cout << fixed << setprecision(15);\n    cerr << fixed << setprecision(7);\n\
    \  }\n} iosetupnya;\n\n}  // namespace Nyaan\n#line 64 \"template/template.hpp\"\
    \n\n// debug\n#line 1 \"template/debug.hpp\"\nnamespace DebugImpl {\n\ntemplate\
    \ <typename U, typename = void>\nstruct is_specialize : false_type {};\ntemplate\
    \ <typename U>\nstruct is_specialize<\n    U, typename conditional<false, typename\
    \ U::iterator, void>::type>\n    : true_type {};\ntemplate <typename U>\nstruct\
    \ is_specialize<\n    U, typename conditional<false, decltype(U::first), void>::type>\n\
    \    : true_type {};\ntemplate <typename U>\nstruct is_specialize<U, enable_if_t<is_integral<U>::value,\
    \ void>> : true_type {\n};\n\nvoid dump(const char& t) { cerr << t; }\n\nvoid\
    \ dump(const string& t) { cerr << t; }\n\nvoid dump(const bool& t) { cerr << (t\
    \ ? \"true\" : \"false\"); }\n\ntemplate <typename U,\n          enable_if_t<!is_specialize<U>::value,\
    \ nullptr_t> = nullptr>\nvoid dump(const U& t) {\n  cerr << t;\n}\n\ntemplate\
    \ <typename T>\nvoid dump(const T& t, enable_if_t<is_integral<T>::value>* = nullptr)\
    \ {\n  string res;\n  if (t == Nyaan::inf) res = \"inf\";\n  if constexpr (is_signed<T>::value)\
    \ {\n    if (t == -Nyaan::inf) res = \"-inf\";\n  }\n  if constexpr (sizeof(T)\
    \ == 8) {\n    if (t == Nyaan::infLL) res = \"inf\";\n    if constexpr (is_signed<T>::value)\
    \ {\n      if (t == -Nyaan::infLL) res = \"-inf\";\n    }\n  }\n  if (res.empty())\
    \ res = to_string(t);\n  cerr << res;\n}\n\ntemplate <typename T, typename U>\n\
    void dump(const pair<T, U>&);\ntemplate <typename T>\nvoid dump(const pair<T*,\
    \ int>&);\n\ntemplate <typename T>\nvoid dump(const T& t,\n          enable_if_t<!is_void<typename\
    \ T::iterator>::value>* = nullptr) {\n  cerr << \"[ \";\n  for (auto it = t.begin();\
    \ it != t.end();) {\n    dump(*it);\n    cerr << (++it == t.end() ? \"\" : \"\
    , \");\n  }\n  cerr << \" ]\";\n}\n\ntemplate <typename T, typename U>\nvoid dump(const\
    \ pair<T, U>& t) {\n  cerr << \"( \";\n  dump(t.first);\n  cerr << \", \";\n \
    \ dump(t.second);\n  cerr << \" )\";\n}\n\ntemplate <typename T>\nvoid dump(const\
    \ pair<T*, int>& t) {\n  cerr << \"[ \";\n  for (int i = 0; i < t.second; i++)\
    \ {\n    dump(t.first[i]);\n    cerr << (i == t.second - 1 ? \"\" : \", \");\n\
    \  }\n  cerr << \" ]\";\n}\n\nvoid trace() { cerr << endl; }\ntemplate <typename\
    \ Head, typename... Tail>\nvoid trace(Head&& head, Tail&&... tail) {\n  cerr <<\
    \ \" \";\n  dump(head);\n  if (sizeof...(tail) != 0) cerr << \",\";\n  trace(forward<Tail>(tail)...);\n\
    }\n\n}  // namespace DebugImpl\n\n#ifdef NyaanDebug\n#define trc(...)        \
    \                    \\\n  do {                                      \\\n    cerr\
    \ << \"## \" << #__VA_ARGS__ << \" = \"; \\\n    DebugImpl::trace(__VA_ARGS__);\
    \          \\\n  } while (0)\n#else\n#define trc(...) (void(0))\n#endif\n#line\
    \ 67 \"template/template.hpp\"\n\n// macro\n#line 1 \"template/macro.hpp\"\n#define\
    \ each(x, v) for (auto&& x : v)\n#define each2(x, y, v) for (auto&& [x, y] : v)\n\
    #define all(v) (v).begin(), (v).end()\n#define rep(i, N) for (long long i = 0;\
    \ i < (long long)(N); i++)\n#define repr(i, N) for (long long i = (long long)(N)-1;\
    \ i >= 0; i--)\n#define rep1(i, N) for (long long i = 1; i <= (long long)(N);\
    \ i++)\n#define repr1(i, N) for (long long i = (N); (long long)(i) > 0; i--)\n\
    #define reg(i, a, b) for (long long i = (a); i < (b); i++)\n#define regr(i, a,\
    \ b) for (long long i = (b)-1; i >= (a); i--)\n#define fi first\n#define se second\n\
    #define ini(...)   \\\n  int __VA_ARGS__; \\\n  in(__VA_ARGS__)\n#define inl(...)\
    \         \\\n  long long __VA_ARGS__; \\\n  in(__VA_ARGS__)\n#define ins(...)\
    \      \\\n  string __VA_ARGS__; \\\n  in(__VA_ARGS__)\n#define in2(s, t)    \
    \                       \\\n  for (int i = 0; i < (int)s.size(); i++) { \\\n \
    \   in(s[i], t[i]);                         \\\n  }\n#define in3(s, t, u)    \
    \                    \\\n  for (int i = 0; i < (int)s.size(); i++) { \\\n    in(s[i],\
    \ t[i], u[i]);                   \\\n  }\n#define in4(s, t, u, v)            \
    \         \\\n  for (int i = 0; i < (int)s.size(); i++) { \\\n    in(s[i], t[i],\
    \ u[i], v[i]);             \\\n  }\n#define die(...)             \\\n  do {  \
    \                     \\\n    Nyaan::out(__VA_ARGS__); \\\n    return;       \
    \           \\\n  } while (0)\n#line 70 \"template/template.hpp\"\n\nnamespace\
    \ Nyaan {\nvoid solve();\n}\nint main() { Nyaan::solve(); }\n#line 2 \"segment-tree/segment-tree.hpp\"\
    \n\n\n\ntemplate <typename T, typename F>\nstruct SegmentTree {\n  int size;\n\
    \  vector<T> seg;\n  const F f;\n  const T I;\n\n  SegmentTree(F _f, const T &I_)\
    \ : size(0), f(_f), I(I_) {}\n\n  SegmentTree(int N, F _f, const T &I_) : f(_f),\
    \ I(I_) { init(N); }\n\n  SegmentTree(const vector<T> &v, F _f, T I_) : f(_f),\
    \ I(I_) {\n    init(v.size());\n    for (int i = 0; i < (int)v.size(); i++) {\n\
    \      seg[i + size] = v[i];\n    }\n    build();\n  }\n\n  void init(int N) {\n\
    \    size = 1;\n    while (size < N) size <<= 1;\n    seg.assign(2 * size, I);\n\
    \  }\n\n  void set(int k, T x) { seg[k + size] = x; }\n\n  void build() {\n  \
    \  for (int k = size - 1; k > 0; k--) {\n      seg[k] = f(seg[2 * k], seg[2 *\
    \ k + 1]);\n    }\n  }\n\n  void update(int k, T x) {\n    k += size;\n    seg[k]\
    \ = x;\n    while (k >>= 1) {\n      seg[k] = f(seg[2 * k], seg[2 * k + 1]);\n\
    \    }\n  }\n\n  void add(int k, T x) {\n    k += size;\n    seg[k] += x;\n  \
    \  while (k >>= 1) {\n      seg[k] = f(seg[2 * k], seg[2 * k + 1]);\n    }\n \
    \ }\n\n  // query to [a, b)\n  T query(int a, int b) {\n    T L = I, R = I;\n\
    \    for (a += size, b += size; a < b; a >>= 1, b >>= 1) {\n      if (a & 1) L\
    \ = f(L, seg[a++]);\n      if (b & 1) R = f(seg[--b], R);\n    }\n    return f(L,\
    \ R);\n  }\n\n  T &operator[](const int &k) { return seg[k + size]; }\n\n  template\
    \ <typename C>\n  int find_subtree(int a, const C &check, T &M, bool type) {\n\
    \    while (a < size) {\n      T nxt = type ? f(seg[2 * a + type], M) : f(M, seg[2\
    \ * a + type]);\n      if (check(nxt))\n        a = 2 * a + type;\n      else\n\
    \        M = nxt, a = 2 * a + 1 - type;\n    }\n    return a - size;\n  }\n\n\
    \  template <typename C>\n  int find_first(int a, const C &check) {\n    T L =\
    \ I;\n    if (a <= 0) {\n      if (check(f(L, seg[1]))) return find_subtree(1,\
    \ check, L, false);\n      return -1;\n    }\n    int b = size;\n    for (a +=\
    \ size, b += size; a < b; a >>= 1, b >>= 1) {\n      if (a & 1) {\n        T nxt\
    \ = f(L, seg[a]);\n        if (check(nxt)) return find_subtree(a, check, L, false);\n\
    \        L = nxt;\n        ++a;\n      }\n    }\n    return -1;\n  }\n\n  template\
    \ <typename C>\n  int find_last(int b, const C &check) {\n    T R = I;\n    if\
    \ (b >= size) {\n      if (check(f(seg[1], R))) return find_subtree(1, check,\
    \ R, true);\n      return -1;\n    }\n    int a = size;\n    for (b += size; a\
    \ < b; a >>= 1, b >>= 1) {\n      if (b & 1) {\n        T nxt = f(seg[--b], R);\n\
    \        if (check(nxt)) return find_subtree(b, check, R, true);\n        R =\
    \ nxt;\n      }\n    }\n    return -1;\n  }\n};\n#line 2 \"tree/heavy-light-decomposition.hpp\"\
    \n\n#line 2 \"graph/graph-template.hpp\"\n\ntemplate <typename T>\nstruct edge\
    \ {\n  int src, to;\n  T cost;\n\n  edge(int _to, T _cost) : src(-1), to(_to),\
    \ cost(_cost) {}\n  edge(int _src, int _to, T _cost) : src(_src), to(_to), cost(_cost)\
    \ {}\n\n  edge &operator=(const int &x) {\n    to = x;\n    return *this;\n  }\n\
    \n  operator int() const { return to; }\n};\ntemplate <typename T>\nusing Edges\
    \ = vector<edge<T>>;\ntemplate <typename T>\nusing WeightedGraph = vector<Edges<T>>;\n\
    using UnweightedGraph = vector<vector<int>>;\n\n// Input of (Unweighted) Graph\n\
    UnweightedGraph graph(int N, int M = -1, bool is_directed = false,\n         \
    \             bool is_1origin = true) {\n  UnweightedGraph g(N);\n  if (M == -1)\
    \ M = N - 1;\n  for (int _ = 0; _ < M; _++) {\n    int x, y;\n    cin >> x >>\
    \ y;\n    if (is_1origin) x--, y--;\n    g[x].push_back(y);\n    if (!is_directed)\
    \ g[y].push_back(x);\n  }\n  return g;\n}\n\n// Input of Weighted Graph\ntemplate\
    \ <typename T>\nWeightedGraph<T> wgraph(int N, int M = -1, bool is_directed =\
    \ false,\n                        bool is_1origin = true) {\n  WeightedGraph<T>\
    \ g(N);\n  if (M == -1) M = N - 1;\n  for (int _ = 0; _ < M; _++) {\n    int x,\
    \ y;\n    cin >> x >> y;\n    T c;\n    cin >> c;\n    if (is_1origin) x--, y--;\n\
    \    g[x].emplace_back(x, y, c);\n    if (!is_directed) g[y].emplace_back(y, x,\
    \ c);\n  }\n  return g;\n}\n\n// Input of Edges\ntemplate <typename T>\nEdges<T>\
    \ esgraph(int N, int M, int is_weighted = true, bool is_1origin = true) {\n  Edges<T>\
    \ es;\n  for (int _ = 0; _ < M; _++) {\n    int x, y;\n    cin >> x >> y;\n  \
    \  T c;\n    if (is_weighted)\n      cin >> c;\n    else\n      c = 1;\n    if\
    \ (is_1origin) x--, y--;\n    es.emplace_back(x, y, c);\n  }\n  return es;\n}\n\
    \n// Input of Adjacency Matrix\ntemplate <typename T>\nvector<vector<T>> adjgraph(int\
    \ N, int M, T INF, int is_weighted = true,\n                           bool is_directed\
    \ = false, bool is_1origin = true) {\n  vector<vector<T>> d(N, vector<T>(N, INF));\n\
    \  for (int _ = 0; _ < M; _++) {\n    int x, y;\n    cin >> x >> y;\n    T c;\n\
    \    if (is_weighted)\n      cin >> c;\n    else\n      c = 1;\n    if (is_1origin)\
    \ x--, y--;\n    d[x][y] = c;\n    if (!is_directed) d[y][x] = c;\n  }\n  return\
    \ d;\n}\n#line 4 \"tree/heavy-light-decomposition.hpp\"\n\ntemplate <typename\
    \ G>\nstruct HeavyLightDecomposition {\n private:\n  void dfs_sz(int cur) {\n\
    \    size[cur] = 1;\n    for (auto& dst : g[cur]) {\n      if (dst == par[cur])\
    \ {\n        if (g[cur].size() >= 2 && int(dst) == int(g[cur][0]))\n         \
    \ swap(g[cur][0], g[cur][1]);\n        else\n          continue;\n      }\n  \
    \    depth[dst] = depth[cur] + 1;\n      par[dst] = cur;\n      dfs_sz(dst);\n\
    \      size[cur] += size[dst];\n      if (size[dst] > size[g[cur][0]]) {\n   \
    \     swap(dst, g[cur][0]);\n      }\n    }\n  }\n\n  void dfs_hld(int cur) {\n\
    \    down[cur] = id++;\n    for (auto dst : g[cur]) {\n      if (dst == par[cur])\
    \ continue;\n      nxt[dst] = (int(dst) == int(g[cur][0]) ? nxt[cur] : int(dst));\n\
    \      dfs_hld(dst);\n    }\n    up[cur] = id;\n  }\n\n  // [u, v)\n  vector<pair<int,\
    \ int>> ascend(int u, int v) const {\n    vector<pair<int, int>> res;\n    while\
    \ (nxt[u] != nxt[v]) {\n      res.emplace_back(down[u], down[nxt[u]]);\n     \
    \ u = par[nxt[u]];\n    }\n    if (u != v) res.emplace_back(down[u], down[v] +\
    \ 1);\n    return res;\n  }\n\n  // (u, v]\n  vector<pair<int, int>> descend(int\
    \ u, int v) const {\n    if (u == v) return {};\n    if (nxt[u] == nxt[v]) return\
    \ {{down[u] + 1, down[v]}};\n    auto res = descend(u, par[nxt[v]]);\n    res.emplace_back(down[nxt[v]],\
    \ down[v]);\n    return res;\n  }\n\n public:\n  G& g;\n  int id;\n  vector<int>\
    \ size, depth, down, up, nxt, par;\n  HeavyLightDecomposition(G& _g, int root\
    \ = 0)\n      : g(_g),\n        id(0),\n        size(g.size(), 0),\n        depth(g.size(),\
    \ 0),\n        down(g.size(), -1),\n        up(g.size(), -1),\n        nxt(g.size(),\
    \ root),\n        par(g.size(), root) {\n    dfs_sz(root);\n    dfs_hld(root);\n\
    \  }\n\n  void build(int root) {\n    dfs_sz(root);\n    dfs_hld(root);\n  }\n\
    \n  pair<int, int> idx(int i) const { return make_pair(down[i], up[i]); }\n\n\
    \  template <typename F>\n  void path_query(int u, int v, bool vertex, const F&\
    \ f) {\n    int l = lca(u, v);\n    for (auto&& [a, b] : ascend(u, l)) {\n   \
    \   int s = a + 1, t = b;\n      s > t ? f(t, s) : f(s, t);\n    }\n    if (vertex)\
    \ f(down[l], down[l] + 1);\n    for (auto&& [a, b] : descend(l, v)) {\n      int\
    \ s = a, t = b + 1;\n      s > t ? f(t, s) : f(s, t);\n    }\n  }\n\n  template\
    \ <typename F>\n  void path_noncommutative_query(int u, int v, bool vertex, const\
    \ F& f) {\n    int l = lca(u, v);\n    for (auto&& [a, b] : ascend(u, l)) f(a\
    \ + 1, b);\n    if (vertex) f(down[l], down[l] + 1);\n    for (auto&& [a, b] :\
    \ descend(l, v)) f(a, b + 1);\n  }\n\n  template <typename F>\n  void subtree_query(int\
    \ u, bool vertex, const F& f) {\n    f(down[u] + int(!vertex), up[u]);\n  }\n\n\
    \  int lca(int a, int b) {\n    while (nxt[a] != nxt[b]) {\n      if (down[a]\
    \ < down[b]) swap(a, b);\n      a = par[nxt[a]];\n    }\n    return depth[a] <\
    \ depth[b] ? a : b;\n  }\n\n  int dist(int a, int b) { return depth[a] + depth[b]\
    \ - depth[lca(a, b)] * 2; }\n};\n\n/**\n * @brief Heavy Light Decomposition(\u91CD\
    \u8EFD\u5206\u89E3)\n * @docs docs/tree/heavy-light-decomposition.md\n */\n#line\
    \ 6 \"verify/verify-yosupo-ds/yosupo-vertex-add-subtree-sum.test.cpp\"\n\nusing\
    \ namespace Nyaan; void Nyaan::solve() {\n  ini(N, Q);\n  vl a(N);\n  in(a);\n\
    \  vvi g(N);\n  rep1(u, N - 1) {\n    ini(v);\n    g[u].push_back(v);\n    g[v].push_back(u);\n\
    \  }\n\n  HeavyLightDecomposition<vvi> hld(g);\n  auto f = [](ll a, ll b) { return\
    \ a + b; };\n  SegmentTree<ll, decltype(f)> seg(N, f, 0);\n  rep(i, N) { seg.set(hld.idx(i).first,\
    \ a[i]); }\n  seg.build();\n\n  ll ans = 0;\n  auto que = [&](int u, int v) {\
    \ ans += seg.query(u, v); };\n\n  rep(_, Q) {\n    ini(cmd);\n    if (cmd) {\n\
    \      ini(u);\n      ans = 0;\n      hld.subtree_query(u, true, que);\n     \
    \ out(ans);\n    } else {\n      inl(k, x);\n      seg.add(hld.idx(k).first, x);\n\
    \    }\n  }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/vertex_add_subtree_sum\"\
    \n\n#include \"../../template/template.hpp\"\n#include \"../../segment-tree/segment-tree.hpp\"\
    \n#include \"../../tree/heavy-light-decomposition.hpp\"\n\nusing namespace Nyaan;\
    \ void Nyaan::solve() {\n  ini(N, Q);\n  vl a(N);\n  in(a);\n  vvi g(N);\n  rep1(u,\
    \ N - 1) {\n    ini(v);\n    g[u].push_back(v);\n    g[v].push_back(u);\n  }\n\
    \n  HeavyLightDecomposition<vvi> hld(g);\n  auto f = [](ll a, ll b) { return a\
    \ + b; };\n  SegmentTree<ll, decltype(f)> seg(N, f, 0);\n  rep(i, N) { seg.set(hld.idx(i).first,\
    \ a[i]); }\n  seg.build();\n\n  ll ans = 0;\n  auto que = [&](int u, int v) {\
    \ ans += seg.query(u, v); };\n\n  rep(_, Q) {\n    ini(cmd);\n    if (cmd) {\n\
    \      ini(u);\n      ans = 0;\n      hld.subtree_query(u, true, que);\n     \
    \ out(ans);\n    } else {\n      inl(k, x);\n      seg.add(hld.idx(k).first, x);\n\
    \    }\n  }\n}"
  dependsOn:
  - template/template.hpp
  - template/util.hpp
  - template/bitop.hpp
  - template/inout.hpp
  - template/debug.hpp
  - template/macro.hpp
  - segment-tree/segment-tree.hpp
  - tree/heavy-light-decomposition.hpp
  - graph/graph-template.hpp
  isVerificationFile: true
  path: verify/verify-yosupo-ds/yosupo-vertex-add-subtree-sum.test.cpp
  requiredBy: []
  timestamp: '2021-05-17 12:37:17+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/verify-yosupo-ds/yosupo-vertex-add-subtree-sum.test.cpp
layout: document
redirect_from:
- /verify/verify/verify-yosupo-ds/yosupo-vertex-add-subtree-sum.test.cpp
- /verify/verify/verify-yosupo-ds/yosupo-vertex-add-subtree-sum.test.cpp.html
title: verify/verify-yosupo-ds/yosupo-vertex-add-subtree-sum.test.cpp
---
