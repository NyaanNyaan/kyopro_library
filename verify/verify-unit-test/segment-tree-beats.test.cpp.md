---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: misc/rng.hpp
    title: misc/rng.hpp
  - icon: ':heavy_check_mark:'
    path: segment-tree/segment-tree-beats.hpp
    title: Range Chmin Chmax Add Update Range Min Max Sum Segment Tree Beats!
  - icon: ':question:'
    path: template/bitop.hpp
    title: template/bitop.hpp
  - icon: ':question:'
    path: template/debug.hpp
    title: template/debug.hpp
  - icon: ':question:'
    path: template/inout.hpp
    title: template/inout.hpp
  - icon: ':question:'
    path: template/macro.hpp
    title: template/macro.hpp
  - icon: ':question:'
    path: template/template.hpp
    title: template/template.hpp
  - icon: ':question:'
    path: template/util.hpp
    title: template/util.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/aplusb
    links:
    - https://judge.yosupo.jp/problem/aplusb
  bundledCode: "#line 1 \"verify/verify-unit-test/segment-tree-beats.test.cpp\"\n\
    #define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n//\n#line 2 \"template/template.hpp\"\
    \nusing namespace std;\n\n// intrinstic\n#include <immintrin.h>\n\n#include <algorithm>\n\
    #include <array>\n#include <bitset>\n#include <cassert>\n#include <cctype>\n#include\
    \ <cfenv>\n#include <cfloat>\n#include <chrono>\n#include <cinttypes>\n#include\
    \ <climits>\n#include <cmath>\n#include <complex>\n#include <cstdarg>\n#include\
    \ <cstddef>\n#include <cstdint>\n#include <cstdio>\n#include <cstdlib>\n#include\
    \ <cstring>\n#include <deque>\n#include <fstream>\n#include <functional>\n#include\
    \ <initializer_list>\n#include <iomanip>\n#include <ios>\n#include <iostream>\n\
    #include <istream>\n#include <iterator>\n#include <limits>\n#include <list>\n\
    #include <map>\n#include <memory>\n#include <new>\n#include <numeric>\n#include\
    \ <ostream>\n#include <queue>\n#include <random>\n#include <set>\n#include <sstream>\n\
    #include <stack>\n#include <streambuf>\n#include <string>\n#include <tuple>\n\
    #include <type_traits>\n#include <typeinfo>\n#include <unordered_map>\n#include\
    \ <unordered_set>\n#include <utility>\n#include <vector>\n\n// utility\n#line\
    \ 1 \"template/util.hpp\"\nnamespace Nyaan {\nusing ll = long long;\nusing i64\
    \ = long long;\nusing u64 = unsigned long long;\nusing i128 = __int128_t;\nusing\
    \ u128 = __uint128_t;\n\ntemplate <typename T>\nusing V = vector<T>;\ntemplate\
    \ <typename T>\nusing VV = vector<vector<T>>;\nusing vi = vector<int>;\nusing\
    \ vl = vector<long long>;\nusing vd = V<double>;\nusing vs = V<string>;\nusing\
    \ vvi = vector<vector<int>>;\nusing vvl = vector<vector<long long>>;\n\ntemplate\
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
    \ Nyaan {\nvoid solve();\n}\nint main() { Nyaan::solve(); }\n#line 4 \"verify/verify-unit-test/segment-tree-beats.test.cpp\"\
    \n//\n#line 2 \"segment-tree/segment-tree-beats.hpp\"\n\nstruct AngelBeats {\n\
    \  using i64 = long long;\n  static constexpr i64 INF = numeric_limits<i64>::max()\
    \ / 2.1;\n\n  struct alignas(32) Node {\n    i64 sum = 0, g1 = 0, l1 = 0;\n  \
    \  i64 g2 = -INF, gc = 1, l2 = INF, lc = 1, add = 0;\n  };\n\n  vector<Node> v;\n\
    \  i64 n, log;\n\n  AngelBeats() {}\n  AngelBeats(int _n) : AngelBeats(vector<i64>(_n))\
    \ {}\n  AngelBeats(const vector<i64>& vc) {\n    n = 1, log = 0;\n    while (n\
    \ < (int)vc.size()) n <<= 1, log++;\n    v.resize(2 * n);\n    for (i64 i = 0;\
    \ i < (int)vc.size(); ++i) {\n      v[i + n].sum = v[i + n].g1 = v[i + n].l1 =\
    \ vc[i];\n    }\n    for (i64 i = n - 1; i; --i) update(i);\n  }\n\n  void range_chmin(int\
    \ l, int r, i64 x) { inner_apply<1>(l, r, x); }\n  void range_chmax(int l, int\
    \ r, i64 x) { inner_apply<2>(l, r, x); }\n  void range_add(int l, int r, i64 x)\
    \ { inner_apply<3>(l, r, x); }\n  void range_update(int l, int r, i64 x) { inner_apply<4>(l,\
    \ r, x); }\n  i64 range_min(int l, int r) { return inner_fold<1>(l, r); }\n  i64\
    \ range_max(int l, int r) { return inner_fold<2>(l, r); }\n  i64 range_sum(int\
    \ l, int r) { return inner_fold<3>(l, r); }\n\n private:\n  void update(int k)\
    \ {\n    Node& p = v[k];\n    Node& l = v[k * 2 + 0];\n    Node& r = v[k * 2 +\
    \ 1];\n\n    p.sum = l.sum + r.sum;\n\n    if (l.g1 == r.g1) {\n      p.g1 = l.g1;\n\
    \      p.g2 = max(l.g2, r.g2);\n      p.gc = l.gc + r.gc;\n    } else {\n    \
    \  bool f = l.g1 > r.g1;\n      p.g1 = f ? l.g1 : r.g1;\n      p.gc = f ? l.gc\
    \ : r.gc;\n      p.g2 = max(f ? r.g1 : l.g1, f ? l.g2 : r.g2);\n    }\n\n    if\
    \ (l.l1 == r.l1) {\n      p.l1 = l.l1;\n      p.l2 = min(l.l2, r.l2);\n      p.lc\
    \ = l.lc + r.lc;\n    } else {\n      bool f = l.l1 < r.l1;\n      p.l1 = f ?\
    \ l.l1 : r.l1;\n      p.lc = f ? l.lc : r.lc;\n      p.l2 = min(f ? r.l1 : l.l1,\
    \ f ? l.l2 : r.l2);\n    }\n  }\n\n  void push_add(int k, i64 x) {\n    Node&\
    \ p = v[k];\n    p.sum += x << (log + __builtin_clz(k) - 31);\n    p.g1 += x;\n\
    \    p.l1 += x;\n    if (p.g2 != -INF) p.g2 += x;\n    if (p.l2 != INF) p.l2 +=\
    \ x;\n    p.add += x;\n  }\n  void push_min(int k, i64 x) {\n    Node& p = v[k];\n\
    \    p.sum += (x - p.g1) * p.gc;\n    if (p.l1 == p.g1) p.l1 = x;\n    if (p.l2\
    \ == p.g1) p.l2 = x;\n    p.g1 = x;\n  }\n  void push_max(int k, i64 x) {\n  \
    \  Node& p = v[k];\n    p.sum += (x - p.l1) * p.lc;\n    if (p.g1 == p.l1) p.g1\
    \ = x;\n    if (p.g2 == p.l1) p.g2 = x;\n    p.l1 = x;\n  }\n  void push(int k)\
    \ {\n    Node& p = v[k];\n    if (p.add != 0) {\n      push_add(k * 2 + 0, p.add);\n\
    \      push_add(k * 2 + 1, p.add);\n      p.add = 0;\n    }\n    if (p.g1 < v[k\
    \ * 2 + 0].g1) push_min(k * 2 + 0, p.g1);\n    if (p.l1 > v[k * 2 + 0].l1) push_max(k\
    \ * 2 + 0, p.l1);\n\n    if (p.g1 < v[k * 2 + 1].g1) push_min(k * 2 + 1, p.g1);\n\
    \    if (p.l1 > v[k * 2 + 1].l1) push_max(k * 2 + 1, p.l1);\n  }\n\n  void subtree_chmin(int\
    \ k, i64 x) {\n    if (v[k].g1 <= x) return;\n    if (v[k].g2 < x) {\n      push_min(k,\
    \ x);\n      return;\n    }\n    push(k);\n    subtree_chmin(k * 2 + 0, x);\n\
    \    subtree_chmin(k * 2 + 1, x);\n    update(k);\n  }\n\n  void subtree_chmax(int\
    \ k, i64 x) {\n    if (x <= v[k].l1) return;\n    if (x < v[k].l2) {\n      push_max(k,\
    \ x);\n      return;\n    }\n    push(k);\n    subtree_chmax(k * 2 + 0, x);\n\
    \    subtree_chmax(k * 2 + 1, x);\n    update(k);\n  }\n\n  template <int cmd>\n\
    \  inline void _apply(int k, i64 x) {\n    if constexpr (cmd == 1) subtree_chmin(k,\
    \ x);\n    if constexpr (cmd == 2) subtree_chmax(k, x);\n    if constexpr (cmd\
    \ == 3) push_add(k, x);\n    if constexpr (cmd == 4) subtree_chmin(k, x), subtree_chmax(k,\
    \ x);\n  }\n\n  template <int cmd>\n  void inner_apply(int l, int r, i64 x) {\n\
    \    if (l == r) return;\n    l += n, r += n;\n    for (int i = log; i >= 1; i--)\
    \ {\n      if (((l >> i) << i) != l) push(l >> i);\n      if (((r >> i) << i)\
    \ != r) push((r - 1) >> i);\n    }\n    {\n      int l2 = l, r2 = r;\n      while\
    \ (l < r) {\n        if (l & 1) _apply<cmd>(l++, x);\n        if (r & 1) _apply<cmd>(--r,\
    \ x);\n        l >>= 1;\n        r >>= 1;\n      }\n      l = l2;\n      r = r2;\n\
    \    }\n    for (int i = 1; i <= log; i++) {\n      if (((l >> i) << i) != l)\
    \ update(l >> i);\n      if (((r >> i) << i) != r) update((r - 1) >> i);\n   \
    \ }\n  }\n\n  template <int cmd>\n  inline i64 e() {\n    if constexpr (cmd ==\
    \ 1) return INF;\n    if constexpr (cmd == 2) return -INF;\n    return 0;\n  }\n\
    \n  template <int cmd>\n  inline void op(i64& a, const Node& b) {\n    if constexpr\
    \ (cmd == 1) a = min(a, b.l1);\n    if constexpr (cmd == 2) a = max(a, b.g1);\n\
    \    if constexpr (cmd == 3) a += b.sum;\n  }\n\n  template <int cmd>\n  i64 inner_fold(int\
    \ l, int r) {\n    if (l == r) return e<cmd>();\n    l += n, r += n;\n    for\
    \ (int i = log; i >= 1; i--) {\n      if (((l >> i) << i) != l) push(l >> i);\n\
    \      if (((r >> i) << i) != r) push((r - 1) >> i);\n    }\n    i64 lx = e<cmd>(),\
    \ rx = e<cmd>();\n    while (l < r) {\n      if (l & 1) op<cmd>(lx, v[l++]);\n\
    \      if (r & 1) op<cmd>(rx, v[--r]);\n      l >>= 1;\n      r >>= 1;\n    }\n\
    \    if constexpr (cmd == 1) lx = min(lx, rx);\n    if constexpr (cmd == 2) lx\
    \ = max(lx, rx);\n    if constexpr (cmd == 3) lx += rx;\n    return lx;\n  }\n\
    };\n\n/**\n * @brief Range Chmin Chmax Add Update Range Min Max Sum Segment Tree\
    \ Beats!\n * @docs docs/segment-tree/segment-tree-beats.md\n */\n#line 6 \"verify/verify-unit-test/segment-tree-beats.test.cpp\"\
    \n\nusing namespace Nyaan;\n\n#line 2 \"misc/rng.hpp\"\n\nnamespace my_rand {\n\
    \n// [0, 2^64 - 1)\nuint64_t rng() {\n  static uint64_t x_ =\n      uint64_t(chrono::duration_cast<chrono::nanoseconds>(\n\
    \                   chrono::high_resolution_clock::now().time_since_epoch())\n\
    \                   .count()) *\n      10150724397891781847ULL;\n  x_ ^= x_ <<\
    \ 7;\n  return x_ ^= x_ >> 9;\n}\n\n// [l, r)\nint64_t randint(int64_t l, int64_t\
    \ r) {\n  assert(l < r);\n  return l + rng() % (r - l);\n}\n\n// choose n numbers\
    \ from [l, r) without overlapping\nvector<int64_t> randset(int64_t l, int64_t\
    \ r, int64_t n) {\n  assert(l <= r && n <= r - l);\n  unordered_set<int64_t> s;\n\
    \  for (int64_t i = n; i; --i) {\n    int64_t m = randint(l, r + 1 - i);\n   \
    \ if (s.find(m) != s.end()) m = r - i;\n    s.insert(m);\n  }\n  vector<int64_t>\
    \ ret;\n  for (auto& x : s) ret.push_back(x);\n  return ret;\n}\n\n// [0.0, 1.0)\n\
    double rnd() {\n  union raw_cast {\n    double t;\n    uint64_t u;\n  };\n  constexpr\
    \ uint64_t p = uint64_t(1023 - 64) << 52;\n  return rng() * ((raw_cast*)(&p))->t;\n\
    }\n\ntemplate <typename T>\nvoid randshf(vector<T>& v) {\n  int n = v.size();\n\
    \  for (int loop = 0; loop < 2; loop++)\n    for (int i = 0; i < n; i++) swap(v[i],\
    \ v[randint(0, n)]);\n}\n\n}  // namespace my_rand\n\nusing my_rand::randint;\n\
    using my_rand::randset;\nusing my_rand::randshf;\nusing my_rand::rnd;\nusing my_rand::rng;\n\
    #line 10 \"verify/verify-unit-test/segment-tree-beats.test.cpp\"\nvoid verify(int\
    \ n, int coeff = 100) {\n  vl a(n);\n  rep(i, n) a[i] = randint(-TEN(10), TEN(10));\n\
    \n  AngelBeats seg(a);\n  int q = n * n * coeff;\n  while (q--) {\n    int cmd\
    \ = randint(0, 7);\n    if (cmd == 3) cmd = randint(0, 7);\n    int l, r;\n  \
    \  do {\n      l = randint(0, n);\n      r = randint(0, n + 1);\n    } while (l\
    \ > r);\n    i64 x = randint(-TEN(10), TEN(10));\n    if (cmd == 0) {\n      //\
    \ range chmin\n      seg.range_chmin(l, r, x);\n      for (int i = l; i < r; i++)\
    \ a[i] = min(a[i], x);\n    } else if (cmd == 1) {\n      // range chmax\n   \
    \   seg.range_chmax(l, r, x);\n      for (int i = l; i < r; i++) a[i] = max(a[i],\
    \ x);\n    } else if (cmd == 2) {\n      // range add\n      seg.range_add(l,\
    \ r, x);\n      for (int i = l; i < r; i++) a[i] += x;\n    } else if (cmd ==\
    \ 3) {\n      // range update\n      seg.range_update(l, r, x);\n      for (int\
    \ i = l; i < r; i++) a[i] = x;\n    } else if (cmd == 4) {\n      // range min\n\
    \      ll s1 = seg.range_min(l, r);\n      ll s2 = seg.INF;\n      for (int i\
    \ = l; i < r; i++) s2 = min(s2, a[i]);\n      assert(s1 == s2 && \"range min\"\
    );\n    } else if (cmd == 5) {\n      // range max\n      ll s1 = seg.range_max(l,\
    \ r);\n      ll s2 = -seg.INF;\n      for (int i = l; i < r; i++) s2 = max(s2,\
    \ a[i]);\n      assert(s1 == s2 && \"range max\");\n    } else if (cmd == 6) {\n\
    \      // range sum\n      ll s1 = seg.range_sum(l, r);\n      ll s2 = 0;\n  \
    \    for (int i = l; i < r; i++) s2 += a[i];\n      assert(s1 == s2 && \"range\
    \ sum\");\n    }\n  }\n}\n\nvoid Nyaan::solve() {\n  int a, b;\n  cin >> a >>\
    \ b;\n  cout << (a + b) << endl;\n\n  verify(1);\n  verify(2);\n  verify(63);\n\
    \  verify(64);\n  verify(65);\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n//\n#include\
    \ \"../../template/template.hpp\"\n//\n#include \"../../segment-tree/segment-tree-beats.hpp\"\
    \n\nusing namespace Nyaan;\n\n#include \"../../misc/rng.hpp\"\nvoid verify(int\
    \ n, int coeff = 100) {\n  vl a(n);\n  rep(i, n) a[i] = randint(-TEN(10), TEN(10));\n\
    \n  AngelBeats seg(a);\n  int q = n * n * coeff;\n  while (q--) {\n    int cmd\
    \ = randint(0, 7);\n    if (cmd == 3) cmd = randint(0, 7);\n    int l, r;\n  \
    \  do {\n      l = randint(0, n);\n      r = randint(0, n + 1);\n    } while (l\
    \ > r);\n    i64 x = randint(-TEN(10), TEN(10));\n    if (cmd == 0) {\n      //\
    \ range chmin\n      seg.range_chmin(l, r, x);\n      for (int i = l; i < r; i++)\
    \ a[i] = min(a[i], x);\n    } else if (cmd == 1) {\n      // range chmax\n   \
    \   seg.range_chmax(l, r, x);\n      for (int i = l; i < r; i++) a[i] = max(a[i],\
    \ x);\n    } else if (cmd == 2) {\n      // range add\n      seg.range_add(l,\
    \ r, x);\n      for (int i = l; i < r; i++) a[i] += x;\n    } else if (cmd ==\
    \ 3) {\n      // range update\n      seg.range_update(l, r, x);\n      for (int\
    \ i = l; i < r; i++) a[i] = x;\n    } else if (cmd == 4) {\n      // range min\n\
    \      ll s1 = seg.range_min(l, r);\n      ll s2 = seg.INF;\n      for (int i\
    \ = l; i < r; i++) s2 = min(s2, a[i]);\n      assert(s1 == s2 && \"range min\"\
    );\n    } else if (cmd == 5) {\n      // range max\n      ll s1 = seg.range_max(l,\
    \ r);\n      ll s2 = -seg.INF;\n      for (int i = l; i < r; i++) s2 = max(s2,\
    \ a[i]);\n      assert(s1 == s2 && \"range max\");\n    } else if (cmd == 6) {\n\
    \      // range sum\n      ll s1 = seg.range_sum(l, r);\n      ll s2 = 0;\n  \
    \    for (int i = l; i < r; i++) s2 += a[i];\n      assert(s1 == s2 && \"range\
    \ sum\");\n    }\n  }\n}\n\nvoid Nyaan::solve() {\n  int a, b;\n  cin >> a >>\
    \ b;\n  cout << (a + b) << endl;\n\n  verify(1);\n  verify(2);\n  verify(63);\n\
    \  verify(64);\n  verify(65);\n}\n"
  dependsOn:
  - template/template.hpp
  - template/util.hpp
  - template/bitop.hpp
  - template/inout.hpp
  - template/debug.hpp
  - template/macro.hpp
  - segment-tree/segment-tree-beats.hpp
  - misc/rng.hpp
  isVerificationFile: true
  path: verify/verify-unit-test/segment-tree-beats.test.cpp
  requiredBy: []
  timestamp: '2021-05-04 19:34:35+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/verify-unit-test/segment-tree-beats.test.cpp
layout: document
redirect_from:
- /verify/verify/verify-unit-test/segment-tree-beats.test.cpp
- /verify/verify/verify-unit-test/segment-tree-beats.test.cpp.html
title: verify/verify-unit-test/segment-tree-beats.test.cpp
---
