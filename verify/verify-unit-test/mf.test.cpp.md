---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: misc/timer.hpp
    title: misc/timer.hpp
  - icon: ':heavy_check_mark:'
    path: modint/montgomery-modint.hpp
    title: modint/montgomery-modint.hpp
  - icon: ':heavy_check_mark:'
    path: multiplicative-function/divisor-multiple-transform.hpp
    title: "\u500D\u6570\u5909\u63DB\u30FB\u7D04\u6570\u5909\u63DB"
  - icon: ':heavy_check_mark:'
    path: multiplicative-function/enamurate-multiplicative-function.hpp
    title: "\u4E57\u6CD5\u7684\u95A2\u6570\u306E\u5217\u6319"
  - icon: ':heavy_check_mark:'
    path: multiplicative-function/mf-famous-series.hpp
    title: "\u6709\u540D\u306A\u4E57\u6CD5\u7684\u95A2\u6570"
  - icon: ':heavy_check_mark:'
    path: prime/prime-enumerate.hpp
    title: prime/prime-enumerate.hpp
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
  bundledCode: "#line 1 \"verify/verify-unit-test/mf.test.cpp\"\n#define PROBLEM \"\
    https://judge.yosupo.jp/problem/aplusb\"\n\n#line 2 \"template/template.hpp\"\n\
    using namespace std;\n\n// intrinstic\n#include <immintrin.h>\n\n#include <algorithm>\n\
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
    \ Nyaan {\nvoid solve();\n}\nint main() { Nyaan::solve(); }\n#line 4 \"verify/verify-unit-test/mf.test.cpp\"\
    \n//\n#line 2 \"modint/montgomery-modint.hpp\"\n\n\n\ntemplate <uint32_t mod>\n\
    struct LazyMontgomeryModInt {\n  using mint = LazyMontgomeryModInt;\n  using i32\
    \ = int32_t;\n  using u32 = uint32_t;\n  using u64 = uint64_t;\n\n  static constexpr\
    \ u32 get_r() {\n    u32 ret = mod;\n    for (i32 i = 0; i < 4; ++i) ret *= 2\
    \ - mod * ret;\n    return ret;\n  }\n\n  static constexpr u32 r = get_r();\n\
    \  static constexpr u32 n2 = -u64(mod) % mod;\n  static_assert(r * mod == 1, \"\
    invalid, r * mod != 1\");\n  static_assert(mod < (1 << 30), \"invalid, mod >=\
    \ 2 ^ 30\");\n  static_assert((mod & 1) == 1, \"invalid, mod % 2 == 0\");\n\n\
    \  u32 a;\n\n  constexpr LazyMontgomeryModInt() : a(0) {}\n  constexpr LazyMontgomeryModInt(const\
    \ int64_t &b)\n      : a(reduce(u64(b % mod + mod) * n2)){};\n\n  static constexpr\
    \ u32 reduce(const u64 &b) {\n    return (b + u64(u32(b) * u32(-r)) * mod) >>\
    \ 32;\n  }\n\n  constexpr mint &operator+=(const mint &b) {\n    if (i32(a +=\
    \ b.a - 2 * mod) < 0) a += 2 * mod;\n    return *this;\n  }\n\n  constexpr mint\
    \ &operator-=(const mint &b) {\n    if (i32(a -= b.a) < 0) a += 2 * mod;\n   \
    \ return *this;\n  }\n\n  constexpr mint &operator*=(const mint &b) {\n    a =\
    \ reduce(u64(a) * b.a);\n    return *this;\n  }\n\n  constexpr mint &operator/=(const\
    \ mint &b) {\n    *this *= b.inverse();\n    return *this;\n  }\n\n  constexpr\
    \ mint operator+(const mint &b) const { return mint(*this) += b; }\n  constexpr\
    \ mint operator-(const mint &b) const { return mint(*this) -= b; }\n  constexpr\
    \ mint operator*(const mint &b) const { return mint(*this) *= b; }\n  constexpr\
    \ mint operator/(const mint &b) const { return mint(*this) /= b; }\n  constexpr\
    \ bool operator==(const mint &b) const {\n    return (a >= mod ? a - mod : a)\
    \ == (b.a >= mod ? b.a - mod : b.a);\n  }\n  constexpr bool operator!=(const mint\
    \ &b) const {\n    return (a >= mod ? a - mod : a) != (b.a >= mod ? b.a - mod\
    \ : b.a);\n  }\n  constexpr mint operator-() const { return mint() - mint(*this);\
    \ }\n\n  constexpr mint pow(u64 n) const {\n    mint ret(1), mul(*this);\n   \
    \ while (n > 0) {\n      if (n & 1) ret *= mul;\n      mul *= mul;\n      n >>=\
    \ 1;\n    }\n    return ret;\n  }\n  \n  constexpr mint inverse() const { return\
    \ pow(mod - 2); }\n\n  friend ostream &operator<<(ostream &os, const mint &b)\
    \ {\n    return os << b.get();\n  }\n\n  friend istream &operator>>(istream &is,\
    \ mint &b) {\n    int64_t t;\n    is >> t;\n    b = LazyMontgomeryModInt<mod>(t);\n\
    \    return (is);\n  }\n  \n  constexpr u32 get() const {\n    u32 ret = reduce(a);\n\
    \    return ret >= mod ? ret - mod : ret;\n  }\n\n  static constexpr u32 get_mod()\
    \ { return mod; }\n};\n#line 2 \"multiplicative-function/divisor-multiple-transform.hpp\"\
    \n\n\n\n#line 2 \"prime/prime-enumerate.hpp\"\n\n// Prime Sieve {2, 3, 5, 7, 11,\
    \ 13, 17, ...}\nvector<int> prime_enumerate(int N) {\n  vector<bool> sieve(N /\
    \ 3 + 1, 1);\n  for (int p = 5, d = 4, i = 1, sqn = sqrt(N); p <= sqn; p += d\
    \ = 6 - d, i++) {\n    if (!sieve[i]) continue;\n    for (int q = p * p / 3, r\
    \ = d * p / 3 + (d * p % 3 == 2), s = 2 * p,\n             qe = sieve.size();\n\
    \         q < qe; q += r = s - r)\n      sieve[q] = 0;\n  }\n  vector<int> ret{2,\
    \ 3};\n  for (int p = 5, d = 4, i = 1; p <= N; p += d = 6 - d, i++)\n    if (sieve[i])\
    \ ret.push_back(p);\n  while (!ret.empty() && ret.back() > N) ret.pop_back();\n\
    \  return ret;\n}\n#line 6 \"multiplicative-function/divisor-multiple-transform.hpp\"\
    \n\nstruct divisor_transform {\n  template <typename T>\n  static void zeta_transform(vector<T>\
    \ &a) {\n    int N = a.size() - 1;\n    auto sieve = prime_enumerate(N);\n   \
    \ for (auto &p : sieve)\n      for (int k = 1; k * p <= N; ++k) a[k * p] += a[k];\n\
    \  }\n  template <typename T>\n  static void mobius_transform(T &a) {\n    int\
    \ N = a.size() - 1;\n    auto sieve = prime_enumerate(N);\n    for (auto &p :\
    \ sieve)\n      for (int k = N / p; k > 0; --k) a[k * p] -= a[k];\n  }\n\n  template\
    \ <typename T>\n  static void zeta_transform(map<long long, T> &a) {\n    for\
    \ (auto p = rbegin(a); p != rend(a); p++)\n      for (auto &x : a) {\n       \
    \ if (p->first == x.first) break;\n        if (p->first % x.first == 0) p->second\
    \ += x.second;\n      }\n  }\n  template <typename T>\n  static void mobius_transform(map<long\
    \ long, T> &a) {\n    for (auto &x : a)\n      for (auto p = rbegin(a); p != rend(a);\
    \ p++) {\n        if (x.first == p->first) break;\n        if (p->first % x.first\
    \ == 0) p->second -= x.second;\n      }\n  }\n};\n\nstruct multiple_transform\
    \ {\n  template <typename T>\n  static void zeta_transform(vector<T> &a) {\n \
    \   int N = a.size() - 1;\n    auto sieve = prime_enumerate(N);\n    for (auto\
    \ &p : sieve)\n      for (int k = N / p; k > 0; --k) a[k] += a[k * p];\n  }\n\
    \  template <typename T>\n  static void mobius_transform(vector<T> &a) {\n   \
    \ int N = a.size() - 1;\n    auto sieve = prime_enumerate(N);\n    for (auto &p\
    \ : sieve)\n      for (int k = 1; k * p <= N; ++k) a[k] -= a[k * p];\n  }\n\n\
    \  template <typename T>\n  static void zeta_transform(map<long long, T> &a) {\n\
    \    for (auto &x : a)\n      for (auto p = rbegin(a); p->first != x.first; p++)\n\
    \        if (p->first % x.first == 0) x.second += p->second;\n  }\n  template\
    \ <typename T>\n  static void mobius_transform(map<long long, T> &a) {\n    for\
    \ (auto p1 = rbegin(a); p1 != rend(a); p1++)\n      for (auto p2 = rbegin(a);\
    \ p2 != p1; p2++)\n        if (p2->first % p1->first == 0) p1->second -= p2->second;\n\
    \  }\n};\n\n/**\n * @brief \u500D\u6570\u5909\u63DB\u30FB\u7D04\u6570\u5909\u63DB\
    \n * @docs docs/multiplicative-function/divisor-multiple-transform.md\n */\n#line\
    \ 2 \"multiplicative-function/enamurate-multiplicative-function.hpp\"\n\n#line\
    \ 5 \"multiplicative-function/enamurate-multiplicative-function.hpp\"\n\n// f(n,\
    \ p, c) : n = pow(p, c), f is multiplicative function\n\ntemplate <typename T,\
    \ T (*f)(int, int, int)>\nstruct enamurate_multiplicative_function {\n  enamurate_multiplicative_function(int\
    \ _n)\n      : ps(prime_enumerate(_n)), a(_n + 1, T()), n(_n), p(ps.size()) {}\n\
    \n  vector<T> run() {\n    a[1] = 1;\n    dfs(-1, 1, 1);\n    return a;\n  }\n\
    \n private:\n  vector<int> ps;\n  vector<T> a;\n  int n, p;\n  void dfs(int i,\
    \ long long x, T y) {\n    a[x] = y;\n    if (y == T()) return;\n    for (int\
    \ j = i + 1; j < p; j++) {\n      long long nx = x * ps[j];\n      long long dx\
    \ = ps[j];\n      if (nx > n) break;\n      for (int c = 1; nx <= n; nx *= ps[j],\
    \ dx *= ps[j], ++c) {\n        dfs(j, nx, y * f(dx, ps[j], c));\n      }\n   \
    \ }\n  }\n};\n\n/**\n * @brief \u4E57\u6CD5\u7684\u95A2\u6570\u306E\u5217\u6319\
    \n */\n#line 2 \"multiplicative-function/mf-famous-series.hpp\"\n\n#line 5 \"\
    multiplicative-function/mf-famous-series.hpp\"\n\nnamespace multiplicative_function\
    \ {\ntemplate <typename T>\nT moebius(int, int, int c) {\n  return c == 0 ? 1\
    \ : c == 1 ? -1 : 0;\n}\ntemplate <typename T>\nT sigma0(int, int, int c) {\n\
    \  return c + 1;\n}\ntemplate <typename T>\nT sigma1(int n, int p, int) {\n  return\
    \ (n - 1) / (p - 1) + n;\n}\ntemplate <typename T>\nT totient(int n, int p, int)\
    \ {\n  return n - n / p;\n}\n}  // namespace multiplicative_function\n\ntemplate\
    \ <typename T>\nstatic constexpr vector<T> mobius_function(int n) {\n  enamurate_multiplicative_function<T,\
    \ multiplicative_function::moebius<T>> em(\n      n);\n  return em.run();\n}\n\
    \ntemplate <typename T>\nstatic constexpr vector<T> sigma0(int n) {\n  enamurate_multiplicative_function<T,\
    \ multiplicative_function::sigma0<T>> em(\n      n);\n  return em.run();\n}\n\n\
    template <typename T>\nstatic constexpr vector<T> sigma1(int n) {\n  enamurate_multiplicative_function<T,\
    \ multiplicative_function::sigma1<T>> em(\n      n);\n  return em.run();\n}\n\n\
    template <typename T>\nstatic constexpr vector<T> totient(int n) {\n  enamurate_multiplicative_function<T,\
    \ multiplicative_function::totient<T>> em(\n      n);\n  return em.run();\n}\n\
    \n/**\n * @brief \u6709\u540D\u306A\u4E57\u6CD5\u7684\u95A2\u6570\n * @docs docs/multiplicative-function/mf-famous-series.md\n\
    \ */\n#line 9 \"verify/verify-unit-test/mf.test.cpp\"\nusing mint = LazyMontgomeryModInt<998244353>;\n\
    \n#line 2 \"misc/timer.hpp\"\n\n#line 4 \"misc/timer.hpp\"\n\nstruct Timer {\n\
    \  chrono::high_resolution_clock::time_point st;\n\n  Timer() { reset(); }\n\n\
    \  void reset() { st = chrono::high_resolution_clock::now(); }\n\n  chrono::milliseconds::rep\
    \ elapsed() {\n    auto ed = chrono::high_resolution_clock::now();\n    return\
    \ chrono::duration_cast<chrono::milliseconds>(ed - st).count();\n  }\n};\n#line\
    \ 12 \"verify/verify-unit-test/mf.test.cpp\"\n\nusing namespace Nyaan;\n\n#include\
    \ <cxxabi.h>\nstring get_name(const type_info& id) {\n  int stat;\n  char* name\
    \ = abi::__cxa_demangle(id.name(), 0, 0, &stat);\n  assert(name != NULL && stat\
    \ == 0);\n  string res = string(name);\n  free(name);\n  return res;\n}\n\ntemplate\
    \ <typename T>\nvoid test_moebius(int n = TEN(7)) {\n  Timer timer;\n  // moebius\
    \ function\n  {\n    // cerr << \"moebius, \" << get_name(typeid(T)) << endl;\n\
    \    timer.reset();\n    auto m1 = mobius_function<T>(n);\n    // cerr << \"emf\
    \ : \" << timer.elapsed() << endl;\n\n    timer.reset();\n    vector<T> m2(n +\
    \ 1);\n    m2[1] = 1;\n    divisor_transform::mobius_transform(m2);\n    // cerr\
    \ << \"dmt : \" << timer.elapsed() << endl;\n    assert(m1 == m2);\n  }\n}\n\n\
    template <typename T>\nvoid test_sigma0(int n = TEN(7)) {\n  Timer timer;\n  //\
    \ divisor function\n  {\n    // cerr << \"sigma0, \" << get_name(typeid(T)) <<\
    \ endl;\n    timer.reset();\n    auto m1 = sigma0<T>(n);\n    // cerr << \"emf\
    \ : \" << timer.elapsed() << endl;\n\n    timer.reset();\n    vector<T> m2(n +\
    \ 1, 1);\n    m2[0] = 0;\n    divisor_transform::zeta_transform(m2);\n    // cerr\
    \ << \"dzt : \" << timer.elapsed() << endl;\n    assert(m1 == m2);\n  }\n}\n\n\
    template <typename T>\nvoid test_sigma1(int n = TEN(7)) {\n  Timer timer;\n  //\
    \ divisor function\n  {\n    // cerr << \"sigma1, \" << get_name(typeid(T)) <<\
    \ endl;\n    timer.reset();\n    auto m1 = sigma1<T>(n);\n    // cerr << \"emf\
    \ : \" << timer.elapsed() << endl;\n\n    timer.reset();\n    vector<T> m2(n +\
    \ 1);\n    rep(i, n + 1) m2[i] = i;\n    divisor_transform::zeta_transform(m2);\n\
    \    // cerr << \"dzt : \" << timer.elapsed() << endl;\n    assert(m1 == m2);\n\
    \  }\n}\n\ntemplate <typename T>\nvoid test_totient(int n = TEN(7)) {\n  Timer\
    \ timer;\n  // divisor function\n  {\n    // cerr << \"totient, \" << get_name(typeid(T))\
    \ << endl;\n    timer.reset();\n    auto m1 = totient<T>(n);\n    // cerr << \"\
    emf : \" << timer.elapsed() << endl;\n\n    timer.reset();\n    vector<T> m2(n\
    \ + 1);\n    rep(i, n + 1) m2[i] = i;\n    divisor_transform::mobius_transform(m2);\n\
    \    // cerr << \"dzt : \" << timer.elapsed() << endl;\n\n    assert(m1 == m2);\n\
    \  }\n}\n\nvoid Nyaan::solve() {\n  for (int i : vi{0, 1, 2, 3, TEN(1), TEN(2),\
    \ TEN(4), TEN(6), 3333333}) {\n    cerr << i << endl;\n    test_moebius<char>(i);\n\
    \    test_moebius<int>(i);\n    test_moebius<mint>(i);\n\n    test_sigma0<char>(i);\n\
    \    test_sigma0<int>(i);\n    test_sigma0<mint>(i);\n\n    test_sigma1<int>(i);\n\
    \    test_sigma1<mint>(i);\n\n    test_totient<int>(i);\n    test_totient<mint>(i);\n\
    \  }\n\n  int a, b;\n  cin >> a >> b;\n  cout << a + b << endl;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n\n#include \"\
    ../../template/template.hpp\"\n//\n#include \"../../modint/montgomery-modint.hpp\"\
    \n#include \"../../multiplicative-function/divisor-multiple-transform.hpp\"\n\
    #include \"../../multiplicative-function/enamurate-multiplicative-function.hpp\"\
    \n#include \"../../multiplicative-function/mf-famous-series.hpp\"\nusing mint\
    \ = LazyMontgomeryModInt<998244353>;\n\n#include \"../../misc/timer.hpp\"\n\n\
    using namespace Nyaan;\n\n#include <cxxabi.h>\nstring get_name(const type_info&\
    \ id) {\n  int stat;\n  char* name = abi::__cxa_demangle(id.name(), 0, 0, &stat);\n\
    \  assert(name != NULL && stat == 0);\n  string res = string(name);\n  free(name);\n\
    \  return res;\n}\n\ntemplate <typename T>\nvoid test_moebius(int n = TEN(7))\
    \ {\n  Timer timer;\n  // moebius function\n  {\n    // cerr << \"moebius, \"\
    \ << get_name(typeid(T)) << endl;\n    timer.reset();\n    auto m1 = mobius_function<T>(n);\n\
    \    // cerr << \"emf : \" << timer.elapsed() << endl;\n\n    timer.reset();\n\
    \    vector<T> m2(n + 1);\n    m2[1] = 1;\n    divisor_transform::mobius_transform(m2);\n\
    \    // cerr << \"dmt : \" << timer.elapsed() << endl;\n    assert(m1 == m2);\n\
    \  }\n}\n\ntemplate <typename T>\nvoid test_sigma0(int n = TEN(7)) {\n  Timer\
    \ timer;\n  // divisor function\n  {\n    // cerr << \"sigma0, \" << get_name(typeid(T))\
    \ << endl;\n    timer.reset();\n    auto m1 = sigma0<T>(n);\n    // cerr << \"\
    emf : \" << timer.elapsed() << endl;\n\n    timer.reset();\n    vector<T> m2(n\
    \ + 1, 1);\n    m2[0] = 0;\n    divisor_transform::zeta_transform(m2);\n    //\
    \ cerr << \"dzt : \" << timer.elapsed() << endl;\n    assert(m1 == m2);\n  }\n\
    }\n\ntemplate <typename T>\nvoid test_sigma1(int n = TEN(7)) {\n  Timer timer;\n\
    \  // divisor function\n  {\n    // cerr << \"sigma1, \" << get_name(typeid(T))\
    \ << endl;\n    timer.reset();\n    auto m1 = sigma1<T>(n);\n    // cerr << \"\
    emf : \" << timer.elapsed() << endl;\n\n    timer.reset();\n    vector<T> m2(n\
    \ + 1);\n    rep(i, n + 1) m2[i] = i;\n    divisor_transform::zeta_transform(m2);\n\
    \    // cerr << \"dzt : \" << timer.elapsed() << endl;\n    assert(m1 == m2);\n\
    \  }\n}\n\ntemplate <typename T>\nvoid test_totient(int n = TEN(7)) {\n  Timer\
    \ timer;\n  // divisor function\n  {\n    // cerr << \"totient, \" << get_name(typeid(T))\
    \ << endl;\n    timer.reset();\n    auto m1 = totient<T>(n);\n    // cerr << \"\
    emf : \" << timer.elapsed() << endl;\n\n    timer.reset();\n    vector<T> m2(n\
    \ + 1);\n    rep(i, n + 1) m2[i] = i;\n    divisor_transform::mobius_transform(m2);\n\
    \    // cerr << \"dzt : \" << timer.elapsed() << endl;\n\n    assert(m1 == m2);\n\
    \  }\n}\n\nvoid Nyaan::solve() {\n  for (int i : vi{0, 1, 2, 3, TEN(1), TEN(2),\
    \ TEN(4), TEN(6), 3333333}) {\n    cerr << i << endl;\n    test_moebius<char>(i);\n\
    \    test_moebius<int>(i);\n    test_moebius<mint>(i);\n\n    test_sigma0<char>(i);\n\
    \    test_sigma0<int>(i);\n    test_sigma0<mint>(i);\n\n    test_sigma1<int>(i);\n\
    \    test_sigma1<mint>(i);\n\n    test_totient<int>(i);\n    test_totient<mint>(i);\n\
    \  }\n\n  int a, b;\n  cin >> a >> b;\n  cout << a + b << endl;\n}\n"
  dependsOn:
  - template/template.hpp
  - template/util.hpp
  - template/bitop.hpp
  - template/inout.hpp
  - template/debug.hpp
  - template/macro.hpp
  - modint/montgomery-modint.hpp
  - multiplicative-function/divisor-multiple-transform.hpp
  - prime/prime-enumerate.hpp
  - multiplicative-function/enamurate-multiplicative-function.hpp
  - multiplicative-function/mf-famous-series.hpp
  - misc/timer.hpp
  isVerificationFile: true
  path: verify/verify-unit-test/mf.test.cpp
  requiredBy: []
  timestamp: '2021-11-14 23:34:55+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/verify-unit-test/mf.test.cpp
layout: document
redirect_from:
- /verify/verify/verify-unit-test/mf.test.cpp
- /verify/verify/verify-unit-test/mf.test.cpp.html
title: verify/verify-unit-test/mf.test.cpp
---
