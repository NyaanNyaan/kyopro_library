---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: inner/inner_math.hpp
    title: inner/inner_math.hpp
  - icon: ':heavy_check_mark:'
    path: misc/rng.hpp
    title: misc/rng.hpp
  - icon: ':heavy_check_mark:'
    path: modint/arbitrary-prime-modint.hpp
    title: modint/arbitrary-prime-modint.hpp
  - icon: ':heavy_check_mark:'
    path: modint/modint-montgomery64.hpp
    title: modint/modint-montgomery64.hpp
  - icon: ':heavy_check_mark:'
    path: prime/factor-enumerate.hpp
    title: prime/factor-enumerate.hpp
  - icon: ':heavy_check_mark:'
    path: prime/fast-factorize.hpp
    title: "\u9AD8\u901F\u7D20\u56E0\u6570\u5206\u89E3(Miller Rabin/Pollard's Rho)"
  - icon: ':heavy_check_mark:'
    path: prime/osak.hpp
    title: prime/osak.hpp
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
  bundledCode: "#line 1 \"verify/verify-unit-test/osak.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/aplusb\"\n//\n#line 2 \"template/template.hpp\"\
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
    \ Nyaan {\nvoid solve();\n}\nint main() { Nyaan::solve(); }\n#line 4 \"verify/verify-unit-test/osak.test.cpp\"\
    \n//\n#line 2 \"prime/fast-factorize.hpp\"\n\n#line 2 \"inner/inner_math.hpp\"\
    \n\nnamespace inner {\n\nusing i32 = int32_t;\nusing u32 = uint32_t;\nusing i64\
    \ = int64_t;\nusing u64 = uint64_t;\n\ntemplate <typename T>\nT gcd(T a, T b)\
    \ {\n  while (b) swap(a %= b, b);\n  return a;\n}\n\ntemplate <typename T>\nT\
    \ inv(T a, T p) {\n  T b = p, x = 1, y = 0;\n  while (a) {\n    T q = b / a;\n\
    \    swap(a, b %= a);\n    swap(x, y -= q * x);\n  }\n  assert(b == 1);\n  return\
    \ y < 0 ? y + p : y;\n}\n\ntemplate <typename T, typename U>\nT modpow(T a, U\
    \ n, T p) {\n  T ret = 1 % p;\n  for (; n; n >>= 1, a = U(a) * a % p)\n    if\
    \ (n & 1) ret = U(ret) * a % p;\n  return ret;\n}\n\n}  // namespace inner\n#line\
    \ 2 \"misc/rng.hpp\"\n\nnamespace my_rand {\n\n// [0, 2^64 - 1)\nuint64_t rng()\
    \ {\n  static uint64_t x_ =\n      uint64_t(chrono::duration_cast<chrono::nanoseconds>(\n\
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
    #line 2 \"modint/arbitrary-prime-modint.hpp\"\n\n\n\nstruct ArbitraryLazyMontgomeryModInt\
    \ {\n  using mint = ArbitraryLazyMontgomeryModInt;\n  using i32 = int32_t;\n \
    \ using u32 = uint32_t;\n  using u64 = uint64_t;\n\n  static u32 mod;\n  static\
    \ u32 r;\n  static u32 n2;\n\n  static u32 get_r() {\n    u32 ret = mod;\n   \
    \ for (i32 i = 0; i < 4; ++i) ret *= 2 - mod * ret;\n    return ret;\n  }\n\n\
    \  static void set_mod(u32 m) {\n    assert(m < (1 << 30));\n    assert((m & 1)\
    \ == 1);\n    mod = m;\n    n2 = -u64(m) % m;\n    r = get_r();\n    assert(r\
    \ * mod == 1);\n  }\n\n  u32 a;\n\n  ArbitraryLazyMontgomeryModInt() : a(0) {}\n\
    \  ArbitraryLazyMontgomeryModInt(const int64_t &b)\n      : a(reduce(u64(b % mod\
    \ + mod) * n2)){};\n\n  static u32 reduce(const u64 &b) {\n    return (b + u64(u32(b)\
    \ * u32(-r)) * mod) >> 32;\n  }\n\n  mint &operator+=(const mint &b) {\n    if\
    \ (i32(a += b.a - 2 * mod) < 0) a += 2 * mod;\n    return *this;\n  }\n\n  mint\
    \ &operator-=(const mint &b) {\n    if (i32(a -= b.a) < 0) a += 2 * mod;\n   \
    \ return *this;\n  }\n\n  mint &operator*=(const mint &b) {\n    a = reduce(u64(a)\
    \ * b.a);\n    return *this;\n  }\n\n  mint &operator/=(const mint &b) {\n   \
    \ *this *= b.inverse();\n    return *this;\n  }\n\n  mint operator+(const mint\
    \ &b) const { return mint(*this) += b; }\n  mint operator-(const mint &b) const\
    \ { return mint(*this) -= b; }\n  mint operator*(const mint &b) const { return\
    \ mint(*this) *= b; }\n  mint operator/(const mint &b) const { return mint(*this)\
    \ /= b; }\n  bool operator==(const mint &b) const {\n    return (a >= mod ? a\
    \ - mod : a) == (b.a >= mod ? b.a - mod : b.a);\n  }\n  bool operator!=(const\
    \ mint &b) const {\n    return (a >= mod ? a - mod : a) != (b.a >= mod ? b.a -\
    \ mod : b.a);\n  }\n  mint operator-() const { return mint() - mint(*this); }\n\
    \n  mint pow(u64 n) const {\n    mint ret(1), mul(*this);\n    while (n > 0) {\n\
    \      if (n & 1) ret *= mul;\n      mul *= mul;\n      n >>= 1;\n    }\n    return\
    \ ret;\n  }\n\n  friend ostream &operator<<(ostream &os, const mint &b) {\n  \
    \  return os << b.get();\n  }\n\n  friend istream &operator>>(istream &is, mint\
    \ &b) {\n    int64_t t;\n    is >> t;\n    b = ArbitraryLazyMontgomeryModInt(t);\n\
    \    return (is);\n  }\n\n  mint inverse() const { return pow(mod - 2); }\n\n\
    \  u32 get() const {\n    u32 ret = reduce(a);\n    return ret >= mod ? ret -\
    \ mod : ret;\n  }\n\n  static u32 get_mod() { return mod; }\n};\ntypename ArbitraryLazyMontgomeryModInt::u32\
    \ ArbitraryLazyMontgomeryModInt::mod;\ntypename ArbitraryLazyMontgomeryModInt::u32\
    \ ArbitraryLazyMontgomeryModInt::r;\ntypename ArbitraryLazyMontgomeryModInt::u32\
    \ ArbitraryLazyMontgomeryModInt::n2;\n#line 2 \"modint/modint-montgomery64.hpp\"\
    \n\n\n\nstruct montgomery64 {\n  using mint = montgomery64;\n  using i64 = int64_t;\n\
    \  using u64 = uint64_t;\n  using u128 = __uint128_t;\n\n  static u64 mod;\n \
    \ static u64 r;\n  static u64 n2;\n\n  static u64 get_r() {\n    u64 ret = mod;\n\
    \    for (i64 i = 0; i < 5; ++i) ret *= 2 - mod * ret;\n    return ret;\n  }\n\
    \n  static void set_mod(u64 m) {\n    assert(m < (1LL << 62));\n    assert((m\
    \ & 1) == 1);\n    mod = m;\n    n2 = -u128(m) % m;\n    r = get_r();\n    assert(r\
    \ * mod == 1);\n  }\n\n  u64 a;\n\n  montgomery64() : a(0) {}\n  montgomery64(const\
    \ int64_t &b) : a(reduce((u128(b) + mod) * n2)){};\n\n  static u64 reduce(const\
    \ u128 &b) {\n    return (b + u128(u64(b) * u64(-r)) * mod) >> 64;\n  }\n\n  mint\
    \ &operator+=(const mint &b) {\n    if (i64(a += b.a - 2 * mod) < 0) a += 2 *\
    \ mod;\n    return *this;\n  }\n\n  mint &operator-=(const mint &b) {\n    if\
    \ (i64(a -= b.a) < 0) a += 2 * mod;\n    return *this;\n  }\n\n  mint &operator*=(const\
    \ mint &b) {\n    a = reduce(u128(a) * b.a);\n    return *this;\n  }\n\n  mint\
    \ &operator/=(const mint &b) {\n    *this *= b.inverse();\n    return *this;\n\
    \  }\n\n  mint operator+(const mint &b) const { return mint(*this) += b; }\n \
    \ mint operator-(const mint &b) const { return mint(*this) -= b; }\n  mint operator*(const\
    \ mint &b) const { return mint(*this) *= b; }\n  mint operator/(const mint &b)\
    \ const { return mint(*this) /= b; }\n  bool operator==(const mint &b) const {\n\
    \    return (a >= mod ? a - mod : a) == (b.a >= mod ? b.a - mod : b.a);\n  }\n\
    \  bool operator!=(const mint &b) const {\n    return (a >= mod ? a - mod : a)\
    \ != (b.a >= mod ? b.a - mod : b.a);\n  }\n  mint operator-() const { return mint()\
    \ - mint(*this); }\n\n  mint pow(u128 n) const {\n    mint ret(1), mul(*this);\n\
    \    while (n > 0) {\n      if (n & 1) ret *= mul;\n      mul *= mul;\n      n\
    \ >>= 1;\n    }\n    return ret;\n  }\n\n  friend ostream &operator<<(ostream\
    \ &os, const mint &b) {\n    return os << b.get();\n  }\n\n  friend istream &operator>>(istream\
    \ &is, mint &b) {\n    int64_t t;\n    is >> t;\n    b = montgomery64(t);\n  \
    \  return (is);\n  }\n\n  mint inverse() const { return pow(mod - 2); }\n\n  u64\
    \ get() const {\n    u64 ret = reduce(a);\n    return ret >= mod ? ret - mod :\
    \ ret;\n  }\n\n  static u64 get_mod() { return mod; }\n};\ntypename montgomery64::u64\
    \ montgomery64::mod, montgomery64::r, montgomery64::n2;\n#line 7 \"prime/fast-factorize.hpp\"\
    \n\nnamespace fast_factorize {\nusing u64 = uint64_t;\n\ntemplate <typename mint>\n\
    bool miller_rabin(u64 n, vector<u64> as) {\n  if (mint::get_mod() != n) mint::set_mod(n);\n\
    \  u64 d = n - 1;\n  while (~d & 1) d >>= 1;\n  mint e{1}, rev{int64_t(n - 1)};\n\
    \  for (u64 a : as) {\n    if (n <= a) break;\n    u64 t = d;\n    mint y = mint(a).pow(t);\n\
    \    while (t != n - 1 && y != e && y != rev) {\n      y *= y;\n      t *= 2;\n\
    \    }\n    if (y != rev && t % 2 == 0) return false;\n  }\n  return true;\n}\n\
    \nbool is_prime(u64 n) {\n  if (~n & 1) return n == 2;\n  if (n <= 1) return false;\n\
    \  if (n < (1LL << 30))\n    return miller_rabin<ArbitraryLazyMontgomeryModInt>(n,\
    \ {2, 7, 61});\n  else\n    return miller_rabin<montgomery64>(\n        n, {2,\
    \ 325, 9375, 28178, 450775, 9780504, 1795265022});\n}\n\ntemplate <typename mint,\
    \ typename T>\nT pollard_rho(T n) {\n  if (~n & 1) return 2;\n  if (is_prime(n))\
    \ return n;\n  if (mint::get_mod() != n) mint::set_mod(n);\n  mint R, one = 1;\n\
    \  auto f = [&](mint x) { return x * x + R; };\n  auto rnd_ = [&]() { return rng()\
    \ % (n - 2) + 2; };\n  while (1) {\n    mint x, y, ys, q = one;\n    R = rnd_(),\
    \ y = rnd_();\n    T g = 1;\n    constexpr int m = 128;\n    for (int r = 1; g\
    \ == 1; r <<= 1) {\n      x = y;\n      for (int i = 0; i < r; ++i) y = f(y);\n\
    \      for (int k = 0; g == 1 && k < r; k += m) {\n        ys = y;\n        for\
    \ (int i = 0; i < m && i < r - k; ++i) q *= x - (y = f(y));\n        g = inner::gcd<T>(q.get(),\
    \ n);\n      }\n    }\n    if (g == n) do\n        g = inner::gcd<T>((x - (ys\
    \ = f(ys))).get(), n);\n      while (g == 1);\n    if (g != n) return g;\n  }\n\
    \  exit(1);\n}\n\nusing i64 = long long;\n\nvector<i64> inner_factorize(u64 n)\
    \ {\n  if (n <= 1) return {};\n  u64 p;\n  if (n <= (1LL << 30))\n    p = pollard_rho<ArbitraryLazyMontgomeryModInt,\
    \ uint32_t>(n);\n  else\n    p = pollard_rho<montgomery64, uint64_t>(n);\n  if\
    \ (p == n) return {i64(p)};\n  auto l = inner_factorize(p);\n  auto r = inner_factorize(n\
    \ / p);\n  copy(begin(r), end(r), back_inserter(l));\n  return l;\n}\n\nvector<i64>\
    \ factorize(u64 n) {\n  auto ret = inner_factorize(n);\n  sort(begin(ret), end(ret));\n\
    \  return ret;\n}\n\nmap<i64, i64> factor_count(u64 n) {\n  map<i64, i64> mp;\n\
    \  for (auto &x : factorize(n)) mp[x]++;\n  return mp;\n}\n\nvector<i64> divisors(u64\
    \ n) {\n  if (n == 0) return {};\n  vector<pair<i64, i64>> v;\n  for (auto &p\
    \ : factorize(n)) {\n    if (v.empty() || v.back().first != p) {\n      v.emplace_back(p,\
    \ 1);\n    } else {\n      v.back().second++;\n    }\n  }\n  vector<i64> ret;\n\
    \  auto f = [&](auto rc, int i, i64 x) -> void {\n    if (i == (int)v.size())\
    \ {\n      ret.push_back(x);\n      return;\n    }\n    for (int j = v[i].second;;\
    \ --j) {\n      rc(rc, i + 1, x);\n      if (j == 0) break;\n      x *= v[i].first;\n\
    \    }\n  };\n  f(f, 0, 1);\n  sort(begin(ret), end(ret));\n  return ret;\n}\n\
    \n}  // namespace fast_factorize\n\nusing fast_factorize::divisors;\nusing fast_factorize::factor_count;\n\
    using fast_factorize::factorize;\nusing fast_factorize::is_prime;\n\n/**\n * @brief\
    \ \u9AD8\u901F\u7D20\u56E0\u6570\u5206\u89E3(Miller Rabin/Pollard's Rho)\n * @docs\
    \ docs/prime/fast-factorize.md\n */\n#line 2 \"prime/osak.hpp\"\n\n#line 2 \"\
    prime/factor-enumerate.hpp\"\n\nvector<int> factor_enumerate(int N) {\n  vector<int>\
    \ lp(N + 1, 0);\n  if (N < 2) return lp;\n  vector<int> pr{2, 3};\n  for (int\
    \ i = 2; i <= N; i += 2) lp[i] = 2;\n  for (int i = 3; i <= N; i += 6) lp[i] =\
    \ 3;\n  for (int i = 5, d = 4; i <= N; i += d = 6 - d) {\n    if (lp[i] == 0)\
    \ {\n      lp[i] = i;\n      pr.push_back(i);\n    }\n    for (int j = 2; j <\
    \ (int)pr.size() && i * pr[j] <= N; ++j) {\n      lp[i * pr[j]] = pr[j];\n   \
    \   if (pr[j] == lp[i]) break;\n    }\n  }\n  return lp;\n}\n#line 4 \"prime/osak.hpp\"\
    \n\ntemplate <int MAX>\nvector<int> osak(int n) {\n  static vector<int> f = factor_enumerate(MAX);\n\
    \  vector<int> ret;\n  while (f[n]) ret.push_back(f[n]), n /= f[n];\n  return\
    \ ret;\n}\n\ntemplate <int MAX>\nvector<pair<int, int>> osak_table(int n) {\n\
    \  static vector<int> f = factor_enumerate(MAX);\n  vector<pair<int, int>> v;\n\
    \  for (; f[n]; n /= f[n]) {\n    if (v.empty() || v.back().first != f[n]) {\n\
    \      v.emplace_back(f[n], 1);\n    } else {\n      v.back().second++;\n    }\n\
    \  }\n  return v;\n}\n\ntemplate <int MAX>\nvector<int> osak_divisors(int n) {\n\
    \  if(n == 0) return {};\n  if(n == 1) return vector<int>(1, 1);\n  auto p = osak_table<MAX>(n);\n\
    \  vector<int> ds;\n\n  auto dfs = [&](auto r, int i, int c) {\n    if (i == (int)p.size())\
    \ {\n      ds.push_back(c);\n      return;\n    }\n    for (int j = 0; j <= p[i].second;\
    \ j++) {\n      r(r, i + 1, c);\n      c *= p[i].first;\n    }\n  };\n\n  dfs(dfs,\
    \ 0, 1);\n  sort(begin(ds), end(ds));\n  return ds;\n}\n#line 7 \"verify/verify-unit-test/osak.test.cpp\"\
    \n\nunsigned long long rng2() {\n  static unsigned long long x_ =\n      chrono::duration_cast<chrono::nanoseconds>(\n\
    \          chrono::high_resolution_clock::now().time_since_epoch())\n        \
    \  .count();\n  x_ = x_ ^ (x_ << 7);\n  return x_ = x_ ^ (x_ >> 9);\n}\n\nconstexpr\
    \ int MX = 10000000;\n\nusing namespace Nyaan;\nvoid Nyaan::solve() {\n  auto\
    \ end = [](auto x, auto y) {\n    out(x);\n    out(y);\n    exit(1);\n  };\n \
    \ rep(i, 100000) {\n    auto f1 = osak<MX>(i);\n    auto f2 = factorize(i);\n\
    \    if (f1.size() != f2.size()) end(f1, f2);\n    rep(i, sz(f1)) if (f1[i] !=\
    \ (int)f2[i]) end(f1, f2);\n\n    auto d1 = osak_divisors<MX>(i);\n    auto d2\
    \ = divisors(i);\n    if (d1.size() != d2.size()) end(d1, d2);\n    rep(i, sz(d1))\
    \ if (d1[i] != (int)d2[i]) end(d1, d2);\n  }\n\n  rep(_, 200000) {\n    int i\
    \ = rng2() & ((1 << 23) - 1);\n    auto f1 = osak<MX>(i);\n    auto f2 = factorize(i);\n\
    \    if (f1.size() != f2.size()) end(f1, f2);\n    rep(i, sz(f1)) if (f1[i] !=\
    \ (int)f2[i]) end(f1, f2);\n\n    auto d1 = osak_divisors<MX>(i);\n    auto d2\
    \ = divisors(i);\n    if (d1.size() != d2.size()) end(d1, d2);\n    rep(i, sz(d1))\
    \ if (d1[i] != (int)d2[i]) end(d1, d2);\n  }\n\n  int a, b;\n  cin >> a >> b;\n\
    \  cout << (a + b) << '\\n';\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n//\n#include\
    \ \"../../template/template.hpp\"\n//\n#include \"../../prime/fast-factorize.hpp\"\
    \n#include \"../../prime/osak.hpp\"\n\nunsigned long long rng2() {\n  static unsigned\
    \ long long x_ =\n      chrono::duration_cast<chrono::nanoseconds>(\n        \
    \  chrono::high_resolution_clock::now().time_since_epoch())\n          .count();\n\
    \  x_ = x_ ^ (x_ << 7);\n  return x_ = x_ ^ (x_ >> 9);\n}\n\nconstexpr int MX\
    \ = 10000000;\n\nusing namespace Nyaan;\nvoid Nyaan::solve() {\n  auto end = [](auto\
    \ x, auto y) {\n    out(x);\n    out(y);\n    exit(1);\n  };\n  rep(i, 100000)\
    \ {\n    auto f1 = osak<MX>(i);\n    auto f2 = factorize(i);\n    if (f1.size()\
    \ != f2.size()) end(f1, f2);\n    rep(i, sz(f1)) if (f1[i] != (int)f2[i]) end(f1,\
    \ f2);\n\n    auto d1 = osak_divisors<MX>(i);\n    auto d2 = divisors(i);\n  \
    \  if (d1.size() != d2.size()) end(d1, d2);\n    rep(i, sz(d1)) if (d1[i] != (int)d2[i])\
    \ end(d1, d2);\n  }\n\n  rep(_, 200000) {\n    int i = rng2() & ((1 << 23) - 1);\n\
    \    auto f1 = osak<MX>(i);\n    auto f2 = factorize(i);\n    if (f1.size() !=\
    \ f2.size()) end(f1, f2);\n    rep(i, sz(f1)) if (f1[i] != (int)f2[i]) end(f1,\
    \ f2);\n\n    auto d1 = osak_divisors<MX>(i);\n    auto d2 = divisors(i);\n  \
    \  if (d1.size() != d2.size()) end(d1, d2);\n    rep(i, sz(d1)) if (d1[i] != (int)d2[i])\
    \ end(d1, d2);\n  }\n\n  int a, b;\n  cin >> a >> b;\n  cout << (a + b) << '\\\
    n';\n}"
  dependsOn:
  - template/template.hpp
  - template/util.hpp
  - template/bitop.hpp
  - template/inout.hpp
  - template/debug.hpp
  - template/macro.hpp
  - prime/fast-factorize.hpp
  - inner/inner_math.hpp
  - misc/rng.hpp
  - modint/arbitrary-prime-modint.hpp
  - modint/modint-montgomery64.hpp
  - prime/osak.hpp
  - prime/factor-enumerate.hpp
  isVerificationFile: true
  path: verify/verify-unit-test/osak.test.cpp
  requiredBy: []
  timestamp: '2021-05-04 19:34:35+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/verify-unit-test/osak.test.cpp
layout: document
redirect_from:
- /verify/verify/verify-unit-test/osak.test.cpp
- /verify/verify/verify-unit-test/osak.test.cpp.html
title: verify/verify-unit-test/osak.test.cpp
---
