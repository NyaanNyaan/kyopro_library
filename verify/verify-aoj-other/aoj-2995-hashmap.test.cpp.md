---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/dynamic-union-find.hpp
    title: "\u52D5\u7684Union Find"
  - icon: ':question:'
    path: graph/graph-template.hpp
    title: "\u30B0\u30E9\u30D5\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  - icon: ':question:'
    path: graph/static-graph.hpp
    title: Static Graph
  - icon: ':heavy_check_mark:'
    path: hashmap/hashmap-base.hpp
    title: "Hash Map(base)\u3000(\u30CF\u30C3\u30B7\u30E5\u30DE\u30C3\u30D7\u30FB\u57FA\
      \u5E95\u30AF\u30E9\u30B9)"
  - icon: ':heavy_check_mark:'
    path: hashmap/hashmap.hpp
    title: "\u30CF\u30C3\u30B7\u30E5\u30DE\u30C3\u30D7(\u9023\u60F3\u914D\u5217)"
  - icon: ':question:'
    path: misc/fastio.hpp
    title: misc/fastio.hpp
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
  - icon: ':heavy_check_mark:'
    path: tree/dsu-on-tree.hpp
    title: DSU on Tree(Guni)
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2995
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2995
  bundledCode: "#line 1 \"verify/verify-aoj-other/aoj-2995-hashmap.test.cpp\"\n#define\
    \ PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2995\"\n\n\
    #line 2 \"template/template.hpp\"\nusing namespace std;\n\n// intrinstic\n#include\
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
    \ Nyaan {\nvoid solve();\n}\nint main() { Nyaan::solve(); }\n#line 2 \"data-structure/dynamic-union-find.hpp\"\
    \n\n#line 2 \"hashmap/hashmap.hpp\"\n\n#line 2 \"hashmap/hashmap-base.hpp\"\n\n\
    namespace HashMapImpl {\nusing u32 = uint32_t;\nusing u64 = uint64_t;\n\ntemplate\
    \ <typename Key, typename Data>\nstruct HashMapBase;\n\ntemplate <typename Key,\
    \ typename Data>\nstruct itrB\n    : iterator<bidirectional_iterator_tag, Data,\
    \ ptrdiff_t, Data*, Data&> {\n  using base =\n      iterator<bidirectional_iterator_tag,\
    \ Data, ptrdiff_t, Data*, Data&>;\n  using ptr = typename base::pointer;\n  using\
    \ ref = typename base::reference;\n\n  u32 i;\n  HashMapBase<Key, Data>* p;\n\n\
    \  explicit constexpr itrB() : i(0), p(nullptr) {}\n  explicit constexpr itrB(u32\
    \ _i, HashMapBase<Key, Data>* _p) : i(_i), p(_p) {}\n  explicit constexpr itrB(u32\
    \ _i, const HashMapBase<Key, Data>* _p)\n      : i(_i), p(const_cast<HashMapBase<Key,\
    \ Data>*>(_p)) {}\n  friend void swap(itrB& l, itrB& r) { swap(l.i, r.i), swap(l.p,\
    \ r.p); }\n  friend bool operator==(const itrB& l, const itrB& r) { return l.i\
    \ == r.i; }\n  friend bool operator!=(const itrB& l, const itrB& r) { return l.i\
    \ != r.i; }\n  const ref operator*() const {\n    return const_cast<const HashMapBase<Key,\
    \ Data>*>(p)->data[i];\n  }\n  ref operator*() { return p->data[i]; }\n  ptr operator->()\
    \ const { return &(p->data[i]); }\n\n  itrB& operator++() {\n    assert(i != p->cap\
    \ && \"itr::operator++()\");\n    do {\n      i++;\n      if (i == p->cap) break;\n\
    \      if (p->flag[i] == true && p->dflag[i] == false) break;\n    } while (true);\n\
    \    return (*this);\n  }\n  itrB operator++(int) {\n    itrB it(*this);\n   \
    \ ++(*this);\n    return it;\n  }\n  itrB& operator--() {\n    do {\n      i--;\n\
    \      if (p->flag[i] == true && p->dflag[i] == false) break;\n      assert(i\
    \ != 0 && \"itr::operator--()\");\n    } while (true);\n    return (*this);\n\
    \  }\n  itrB operator--(int) {\n    itrB it(*this);\n    --(*this);\n    return\
    \ it;\n  }\n};\n\ntemplate <typename Key, typename Data>\nstruct HashMapBase {\n\
    \  using u32 = uint32_t;\n  using u64 = uint64_t;\n  using iterator = itrB<Key,\
    \ Data>;\n  using itr = iterator;\n\n protected:\n  template <typename K>\n  inline\
    \ u64 randomized(const K& key) const {\n    return u64(key) ^ r;\n  }\n\n  template\
    \ <typename K,\n            enable_if_t<is_same<K, Key>::value, nullptr_t> = nullptr,\n\
    \            enable_if_t<is_integral<K>::value, nullptr_t> = nullptr>\n  inline\
    \ u32 inner_hash(const K& key) const {\n    return (randomized(key) * 11995408973635179863ULL)\
    \ >> shift;\n  }\n  template <\n      typename K, enable_if_t<is_same<K, Key>::value,\
    \ nullptr_t> = nullptr,\n      enable_if_t<is_integral<decltype(K::first)>::value,\
    \ nullptr_t> = nullptr,\n      enable_if_t<is_integral<decltype(K::second)>::value,\
    \ nullptr_t> = nullptr>\n  inline u32 inner_hash(const K& key) const {\n    u64\
    \ a = randomized(key.first), b = randomized(key.second);\n    a *= 11995408973635179863ULL;\n\
    \    b *= 10150724397891781847ULL;\n    return (a + b) >> shift;\n  }\n  template\
    \ <typename K,\n            enable_if_t<is_same<K, Key>::value, nullptr_t> = nullptr,\n\
    \            enable_if_t<is_integral<typename K::value_type>::value, nullptr_t>\
    \ =\n                nullptr>\n  inline u32 inner_hash(const K& key) const {\n\
    \    static constexpr u64 mod = (1LL << 61) - 1;\n    static constexpr u64 base\
    \ = 950699498548472943ULL;\n    u64 res = 0;\n    for (auto& elem : key) {\n \
    \     __uint128_t x = __uint128_t(res) * base + (randomized(elem) & mod);\n  \
    \    res = (x & mod) + (x >> 61);\n    }\n    __uint128_t x = __uint128_t(res)\
    \ * base;\n    res = (x & mod) + (x >> 61);\n    if (res >= mod) res -= mod;\n\
    \    return res >> (shift - 3);\n  }\n\n  template <typename D = Data,\n     \
    \       enable_if_t<is_same<D, Key>::value, nullptr_t> = nullptr>\n  inline u32\
    \ hash(const D& dat) const {\n    return inner_hash(dat);\n  }\n  template <\n\
    \      typename D = Data,\n      enable_if_t<is_same<decltype(D::first), Key>::value,\
    \ nullptr_t> = nullptr>\n  inline u32 hash(const D& dat) const {\n    return inner_hash(dat.first);\n\
    \  }\n\n  template <typename D = Data,\n            enable_if_t<is_same<D, Key>::value,\
    \ nullptr_t> = nullptr>\n  inline Key dtok(const D& dat) const {\n    return dat;\n\
    \  }\n  template <\n      typename D = Data,\n      enable_if_t<is_same<decltype(D::first),\
    \ Key>::value, nullptr_t> = nullptr>\n  inline Key dtok(const D& dat) const {\n\
    \    return dat.first;\n  }\n\n  void reallocate(u32 ncap) {\n    vector<Data>\
    \ ndata(ncap);\n    vector<bool> nf(ncap);\n    shift = 64 - __lg(ncap);\n   \
    \ for (u32 i = 0; i < cap; i++) {\n      if (flag[i] == true && dflag[i] == false)\
    \ {\n        u32 h = hash(data[i]);\n        while (nf[h]) h = (h + 1) & (ncap\
    \ - 1);\n        ndata[h] = move(data[i]);\n        nf[h] = true;\n      }\n \
    \   }\n    data.swap(ndata);\n    flag.swap(nf);\n    cap = ncap;\n    dflag.resize(cap);\n\
    \    fill(std::begin(dflag), std::end(dflag), false);\n  }\n\n  inline bool extend_rate(u32\
    \ x) const { return x * 2 >= cap; }\n\n  inline bool shrink_rate(u32 x) const\
    \ {\n    return HASHMAP_DEFAULT_SIZE < cap && x * 10 <= cap;\n  }\n\n  inline\
    \ void extend() { reallocate(cap << 1); }\n\n  inline void shrink() { reallocate(cap\
    \ >> 1); }\n\n public:\n  u32 cap, s;\n  vector<Data> data;\n  vector<bool> flag,\
    \ dflag;\n  u32 shift;\n  static u64 r;\n  static constexpr uint32_t HASHMAP_DEFAULT_SIZE\
    \ = 4;\n\n  explicit HashMapBase()\n      : cap(HASHMAP_DEFAULT_SIZE),\n     \
    \   s(0),\n        data(cap),\n        flag(cap),\n        dflag(cap),\n     \
    \   shift(64 - __lg(cap)) {}\n\n  itr begin() const {\n    u32 h = 0;\n    while\
    \ (h != cap) {\n      if (flag[h] == true && dflag[h] == false) break;\n     \
    \ h++;\n    }\n    return itr(h, this);\n  }\n  itr end() const { return itr(this->cap,\
    \ this); }\n\n  friend itr begin(const HashMapBase& h) { return h.begin(); }\n\
    \  friend itr end(const HashMapBase& h) { return h.end(); }\n\n  itr find(const\
    \ Key& key) const {\n    u32 h = inner_hash(key);\n    while (true) {\n      if\
    \ (flag[h] == false) return this->end();\n      if (dtok(data[h]) == key) {\n\
    \        if (dflag[h] == true) return this->end();\n        return itr(h, this);\n\
    \      }\n      h = (h + 1) & (cap - 1);\n    }\n  }\n\n  bool contain(const Key&\
    \ key) const { return find(key) != this->end(); }\n\n  itr insert(const Data&\
    \ d) {\n    u32 h = hash(d);\n    while (true) {\n      if (flag[h] == false)\
    \ {\n        if (extend_rate(s + 1)) {\n          extend();\n          h = hash(d);\n\
    \          continue;\n        }\n        data[h] = d;\n        flag[h] = true;\n\
    \        ++s;\n        return itr(h, this);\n      }\n      if (dtok(data[h])\
    \ == dtok(d)) {\n        if (dflag[h] == true) {\n          data[h] = d;\n   \
    \       dflag[h] = false;\n          ++s;\n        }\n        return itr(h, this);\n\
    \      }\n      h = (h + 1) & (cap - 1);\n    }\n  }\n\n  // tips for speed up\
    \ :\n  // if return value is unnecessary, make argument_2 false.\n  itr erase(itr\
    \ it, bool get_next = true) {\n    if (it == this->end()) return this->end();\n\
    \    s--;\n    if (shrink_rate(s)) {\n      Data d = data[it.i];\n      shrink();\n\
    \      it = find(dtok(d));\n    }\n    int ni = (it.i + 1) & (cap - 1);\n    if\
    \ (this->flag[ni]) {\n      this->dflag[it.i] = true;\n    } else {\n      this->flag[it.i]\
    \ = false;\n    }\n    if (get_next) ++it;\n    return it;\n  }\n\n  itr erase(const\
    \ Key& key) { return erase(find(key)); }\n\n  bool empty() const { return s ==\
    \ 0; }\n\n  int size() const { return s; }\n\n  void clear() {\n    fill(std::begin(flag),\
    \ std::end(flag), false);\n    fill(std::begin(dflag), std::end(dflag), false);\n\
    \    s = 0;\n  }\n\n  void reserve(int n) {\n    if (n <= 0) return;\n    n =\
    \ 1 << min(23, __lg(n) + 2);\n    if (cap < u32(n)) reallocate(n);\n  }\n};\n\n\
    template <typename Key, typename Data>\nuint64_t HashMapBase<Key, Data>::r =\n\
    \    chrono::duration_cast<chrono::nanoseconds>(\n        chrono::high_resolution_clock::now().time_since_epoch())\n\
    \        .count();\n\n}  // namespace HashMapImpl\n\n/**\n * @brief Hash Map(base)\u3000\
    (\u30CF\u30C3\u30B7\u30E5\u30DE\u30C3\u30D7\u30FB\u57FA\u5E95\u30AF\u30E9\u30B9\
    )\n */\n#line 4 \"hashmap/hashmap.hpp\"\n\ntemplate <typename Key, typename Val>\n\
    struct HashMap : HashMapImpl::HashMapBase<Key, pair<Key, Val>> {\n  using base\
    \ = typename HashMapImpl::HashMapBase<Key, pair<Key, Val>>;\n  using HashMapImpl::HashMapBase<Key,\
    \ pair<Key, Val>>::HashMapBase;\n  using Data = pair<Key, Val>;\n\n  Val& operator[](const\
    \ Key& k) {\n    typename base::u32 h = base::inner_hash(k);\n    while (true)\
    \ {\n      if (base::flag[h] == false) {\n        if (base::extend_rate(base::s\
    \ + 1)) {\n          base::extend();\n          h = base::hash(k);\n         \
    \ continue;\n        }\n        base::data[h].first = k;\n        base::data[h].second\
    \ = Val();\n        base::flag[h] = true;\n        ++base::s;\n        return\
    \ base::data[h].second;\n      }\n      if (base::data[h].first == k) {\n    \
    \    if (base::dflag[h] == true) base::data[h].second = Val();\n        return\
    \ base::data[h].second;\n      }\n      h = (h + 1) & (base::cap - 1);\n    }\n\
    \  }\n\n  typename base::itr emplace(const Key& key, const Val& val) {\n    return\
    \ base::insert(Data(key, val));\n  }\n};\n\n/* \n * @brief \u30CF\u30C3\u30B7\u30E5\
    \u30DE\u30C3\u30D7(\u9023\u60F3\u914D\u5217)\n * @docs docs/hashmap/hashmap.md\n\
    **/\n#line 4 \"data-structure/dynamic-union-find.hpp\"\n\nstruct DynamicUnionFind\
    \ {\n  HashMap<int, int> m;\n  DynamicUnionFind() = default;\n\n  int data(int\
    \ k) {\n    auto it = m.find(k);\n    return it == m.end() ? m[k] = -1 : it->second;\n\
    \  }\n  int find(int k) {\n    int n = data(k);\n    return n < 0 ? k : m[k] =\
    \ find(n);\n  }\n\n  int unite(int x, int y) {\n    x = find(x), y = find(y);\n\
    \    if (x == y) return false;\n    auto itx = m.find(x), ity = m.find(y);\n \
    \   if (itx->second > ity->second) swap(itx, ity), swap(x, y);\n    itx->second\
    \ += ity->second;\n    ity->second = x;\n    return true;\n  }\n\n  template <typename\
    \ F>\n  int unite(int x, int y, const F& f) {\n    x = find(x), y = find(y);\n\
    \    if (x == y) return false;\n    auto itx = m.find(x), ity = m.find(y);\n \
    \   if (itx->second > ity->second) swap(itx, ity), swap(x, y);\n    itx->second\
    \ += ity->second;\n    ity->second = x;\n    f(x, y);\n    return true;\n  }\n\
    \n  int size(int k) { return -data(find(k)); }\n\n  int same(int x, int y) { return\
    \ find(x) == find(y); }\n\n  void clear() { m.clear(); }\n};\n\n/**\n * @brief\
    \ \u52D5\u7684Union Find\n * @docs docs/data-structure/dynamic-union-find.md\n\
    \ */\n#line 2 \"graph/static-graph.hpp\"\n\nnamespace StaticGraphImpl {\n\ntemplate\
    \ <typename T, bool Cond = is_void<T>::value>\nstruct E;\ntemplate <typename T>\n\
    struct E<T, false> {\n  int to;\n  T cost;\n  E() {}\n  E(const int& v, const\
    \ T& c) : to(v), cost(c) {}\n  operator int() const { return to; }\n};\ntemplate\
    \ <typename T>\nstruct E<T, true> {\n  int to;\n  E() {}\n  E(const int& v) :\
    \ to(v) {}\n  operator int() const { return to; }\n};\n\ntemplate <typename T\
    \ = void>\nstruct StaticGraph {\n private:\n  template <typename It>\n  struct\
    \ Es {\n    It b, e;\n    It begin() const { return b; }\n    It end() const {\
    \ return e; }\n    int size() const { return int(e - b); }\n    auto&& operator[](int\
    \ i) const { return b[i]; }\n  };\n  \n  int N, M, ec;\n  vector<int> head;\n\
    \  vector<pair<int, E<T>>> buf;\n  vector<E<T>> es;\n\n  void build() {\n    partial_sum(begin(head),\
    \ end(head), begin(head));\n    es.resize(M);\n    for (auto&& [u, e] : buf) es[--head[u]]\
    \ = e;\n  }\n\n public:\n  StaticGraph(int _n, int _m) : N(_n), M(_m), ec(0),\
    \ head(N + 1, 0) {\n    buf.reserve(M);\n  }\n\n  template <typename... Args>\n\
    \  void add_edge(int u, Args&&... args) {\n#pragma GCC diagnostic ignored \"-Wnarrowing\"\
    \n    buf.emplace_back(u, E<T>{std::forward<Args>(args)...});\n#pragma GCC diagnostic\
    \ warning \"-Wnarrowing\"\n    ++head[u];\n    if ((int)buf.size() == M) build();\n\
    \  }\n\n  Es<typename vector<E<T>>::iterator> operator[](int u) {\n    return\
    \ {begin(es) + head[u], begin(es) + head[u + 1]};\n  }\n  const Es<typename vector<E<T>>::const_iterator>\
    \ operator[](int u) const {\n    return {begin(es) + head[u], begin(es) + head[u\
    \ + 1]};\n  }\n  int size() const { return N; }\n};\n\n}  // namespace StaticGraphImpl\n\
    \nusing StaticGraphImpl::StaticGraph;\n\n/**\n * @brief Static Graph\n * @docs\
    \ docs/graph/static-graph.md\n */\n#line 2 \"misc/fastio.hpp\"\n\n#line 6 \"misc/fastio.hpp\"\
    \n\nusing namespace std;\n\nnamespace fastio {\nstatic constexpr int SZ = 1 <<\
    \ 17;\nchar inbuf[SZ], outbuf[SZ];\nint in_left = 0, in_right = 0, out_right =\
    \ 0;\n\nstruct Pre {\n  char num[40000];\n  constexpr Pre() : num() {\n    for\
    \ (int i = 0; i < 10000; i++) {\n      int n = i;\n      for (int j = 3; j >=\
    \ 0; j--) {\n        num[i * 4 + j] = n % 10 + '0';\n        n /= 10;\n      }\n\
    \    }\n  }\n} constexpr pre;\n\ninline void load() {\n  int len = in_right -\
    \ in_left;\n  memmove(inbuf, inbuf + in_left, len);\n  in_right = len + fread(inbuf\
    \ + len, 1, SZ - len, stdin);\n  in_left = 0;\n}\n\ninline void flush() {\n  fwrite(outbuf,\
    \ 1, out_right, stdout);\n  out_right = 0;\n}\n\ninline void skip_space() {\n\
    \  if (in_left + 32 > in_right) load();\n  while (inbuf[in_left] <= ' ') in_left++;\n\
    }\n\ninline void rd(char& c) {\n  if (in_left + 32 > in_right) load();\n  c =\
    \ inbuf[in_left++];\n}\ntemplate <typename T>\ninline void rd(T& x) {\n  if (in_left\
    \ + 32 > in_right) load();\n  char c;\n  do c = inbuf[in_left++];\n  while (c\
    \ < '-');\n  [[maybe_unused]] bool minus = false;\n  if constexpr (is_signed<T>::value\
    \ == true) {\n    if (c == '-') minus = true, c = inbuf[in_left++];\n  }\n  x\
    \ = 0;\n  while (c >= '0') {\n    x = x * 10 + (c & 15);\n    c = inbuf[in_left++];\n\
    \  }\n  if constexpr (is_signed<T>::value == true) {\n    if (minus) x = -x;\n\
    \  }\n}\ninline void rd() {}\ntemplate <typename Head, typename... Tail>\ninline\
    \ void rd(Head& head, Tail&... tail) {\n  rd(head);\n  rd(tail...);\n}\n\ninline\
    \ void wt(char c) {\n  if (out_right > SZ - 32) flush();\n  outbuf[out_right++]\
    \ = c;\n}\ninline void wt(bool b) {\n  if (out_right > SZ - 32) flush();\n  outbuf[out_right++]\
    \ = b ? '1' : '0';\n}\ninline void wt(const string &s) {\n  if (out_right + s.size()\
    \ > SZ - 32) flush();\n  memcpy(outbuf + out_right, s.data(), sizeof(char) * s.size());\n\
    \  out_right += s.size();\n}\ntemplate <typename T>\ninline void wt(T x) {\n \
    \ if (out_right > SZ - 32) flush();\n  if (!x) {\n    outbuf[out_right++] = '0';\n\
    \    return;\n  }\n  if constexpr (is_signed<T>::value == true) {\n    if (x <\
    \ 0) outbuf[out_right++] = '-', x = -x;\n  }\n  int i = 12;\n  char buf[16];\n\
    \  while (x >= 10000) {\n    memcpy(buf + i, pre.num + (x % 10000) * 4, 4);\n\
    \    x /= 10000;\n    i -= 4;\n  }\n  if (x < 100) {\n    if (x < 10) {\n    \
    \  outbuf[out_right] = '0' + x;\n      ++out_right;\n    } else {\n      uint32_t\
    \ q = (uint32_t(x) * 205) >> 11;\n      uint32_t r = uint32_t(x) - q * 10;\n \
    \     outbuf[out_right] = '0' + q;\n      outbuf[out_right + 1] = '0' + r;\n \
    \     out_right += 2;\n    }\n  } else {\n    if (x < 1000) {\n      memcpy(outbuf\
    \ + out_right, pre.num + (x << 2) + 1, 3);\n      out_right += 3;\n    } else\
    \ {\n      memcpy(outbuf + out_right, pre.num + (x << 2), 4);\n      out_right\
    \ += 4;\n    }\n  }\n  memcpy(outbuf + out_right, buf + i + 4, 12 - i);\n  out_right\
    \ += 12 - i;\n}\ninline void wt() {}\ntemplate <typename Head, typename... Tail>\n\
    inline void wt(Head&& head, Tail&&... tail) {\n  wt(head);\n  wt(forward<Tail>(tail)...);\n\
    }\ntemplate <typename... Args>\ninline void wtn(Args&&... x) {\n  wt(forward<Args>(x)...);\n\
    \  wt('\\n');\n}\n\nstruct Dummy {\n  Dummy() { atexit(flush); }\n} dummy;\n\n\
    }  // namespace fastio\nusing fastio::rd;\nusing fastio::skip_space;\nusing fastio::wt;\n\
    using fastio::wtn;\n#line 2 \"tree/dsu-on-tree.hpp\"\n\n\n\n#line 2 \"graph/graph-template.hpp\"\
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
    \ <typename T>\nEdges<T> esgraph(int N, int M, int is_weighted = true, bool is_1origin\
    \ = true) {\n  Edges<T> es;\n  for (int _ = 0; _ < M; _++) {\n    int x, y;\n\
    \    cin >> x >> y;\n    T c;\n    if (is_weighted)\n      cin >> c;\n    else\n\
    \      c = 1;\n    if (is_1origin) x--, y--;\n    es.emplace_back(x, y, c);\n\
    \  }\n  return es;\n}\n\n// Input of Adjacency Matrix\ntemplate <typename T>\n\
    vector<vector<T>> adjgraph(int N, int M, T INF, int is_weighted = true,\n    \
    \                       bool is_directed = false, bool is_1origin = true) {\n\
    \  vector<vector<T>> d(N, vector<T>(N, INF));\n  for (int _ = 0; _ < M; _++) {\n\
    \    int x, y;\n    cin >> x >> y;\n    T c;\n    if (is_weighted)\n      cin\
    \ >> c;\n    else\n      c = 1;\n    if (is_1origin) x--, y--;\n    d[x][y] =\
    \ c;\n    if (!is_directed) d[y][x] = c;\n  }\n  return d;\n}\n\n/**\n * @brief\
    \ \u30B0\u30E9\u30D5\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8\n * @docs docs/graph/graph-template.md\n\
    \ */\n#line 6 \"tree/dsu-on-tree.hpp\"\n\ntemplate <typename G>\nstruct DSUonTree\
    \ {\n private:\n  G &g;\n  int N;\n  vector<int> sub_sz, euler, down, up;\n  int\
    \ idx_;\n  int root;\n\n  int dfs1(int cur, int par = -1) {\n    sub_sz[cur] =\
    \ 1;\n    if ((int)g[cur].size() >= 2 and g[cur][0] == par) {\n      swap(g[cur][0],\
    \ g[cur][1]);\n    }\n    for (auto &dst : g[cur]) {\n      if (dst == par) continue;\n\
    \      sub_sz[cur] += dfs1(dst, cur);\n      if (sub_sz[dst] > sub_sz[g[cur][0]])\
    \ swap(dst, g[cur][0]);\n    }\n    return sub_sz[cur];\n  }\n\n  void dfs2(int\
    \ cur, int par = -1) {\n    euler[idx_] = cur;\n    down[cur] = idx_++;\n    for\
    \ (auto &dst : g[cur]) {\n      if (dst == par) continue;\n      dfs2(dst, cur);\n\
    \    }\n    up[cur] = idx_;\n  }\n\n public:\n  DSUonTree(G &_g,int _root = 0)\n\
    \      : g(_g),\n        N(_g.size()),\n        sub_sz(_g.size()),\n        euler(_g.size()),\n\
    \        down(_g.size()),\n        up(_g.size()),\n        idx_(0),\n        root(_root)\
    \ {\n    dfs1(root);\n    dfs2(root);\n  }\n\n  int idx(int u) const { return\
    \ down[u]; }\n\n  template <typename UPDATE, typename QUERY, typename CLEAR, typename\
    \ RESET>\n  void run(UPDATE &update, QUERY &query, CLEAR &clear, RESET &reset)\
    \ {\n    auto dsu = [&](auto rc, int cur, int par = -1, bool keep = false) ->\
    \ void {\n      for (int i = 1; i < (int)g[cur].size(); i++)\n        if (g[cur][i]\
    \ != par) rc(rc, g[cur][i], cur, false);\n      if (sub_sz[cur] != 1) rc(rc, g[cur][0],\
    \ cur, true);\n      if (sub_sz[cur] != 1)\n        for (int i = up[g[cur][0]];\
    \ i < up[cur]; i++) update(euler[i]);\n      update(cur);\n      query(cur);\n\
    \      if (!keep) {\n        for (int i = down[cur]; i < up[cur]; i++) clear(euler[i]);\n\
    \        reset();\n      }\n      return;\n    };\n    dsu(dsu, root);\n  }\n\
    };\n\n/**\n * @brief DSU on Tree(Guni)\n * @docs docs/tree/dsu-on-tree.md\n */\n\
    #line 8 \"verify/verify-aoj-other/aoj-2995-hashmap.test.cpp\"\n\nusing namespace\
    \ Nyaan; void Nyaan::solve() {\n  int N, K;\n  rd(N, K);\n  StaticGraph<void>\
    \ g(N, 2 * N - 2);\n  rep1(i, N - 1) {\n    int u, v;\n    rd(u, v);\n    --u,\
    \ --v;\n    g.add_edge(u, v);\n    g.add_edge(v, u);\n  }\n\n  V<pair<int, int>>\
    \ cl(N);\n  rep(i, N) rd(cl[i].first, cl[i].second);\n\n  DynamicUnionFind uf;\n\
    \  int sm = 0;\n  vi ans(N);\n  HashMap<int, int> val;\n  // reflect data of node\
    \ i\n  auto update = [&](int i) {\n    uf.unite(cl[i].first, cl[i].second,\n \
    \            [&](int x, int y) { val[x] += val[y]; });\n    int p = uf.find(cl[i].first);\n\
    \    if (uf.size(p) > val[p]) {\n      sm++;\n      val[p]++;\n    }\n  };\n \
    \ // answer queries of subtree i\n  auto query = [&](int i) { ans[i] = sm; };\n\
    \  // below two function are called if all data must be deleted\n  // delete data\
    \ of node i (if necesarry)\n  auto clear = [&](int) {};\n  // delete data related\
    \ to all (if necesarry)\n  auto reset = [&]() {\n    uf.clear();\n    sm = 0;\n\
    \    val.clear();\n  };\n\n  DSUonTree<decltype(g)> dsu(g);\n  dsu.run(update,\
    \ query, clear, reset);\n\n  each(x, ans) wtn(x);\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2995\"\
    \n\n#include \"../../template/template.hpp\"\n#include \"../../data-structure/dynamic-union-find.hpp\"\
    \n#include \"../../graph/static-graph.hpp\"\n#include \"../../misc/fastio.hpp\"\
    \n#include \"../../tree/dsu-on-tree.hpp\"\n\nusing namespace Nyaan; void Nyaan::solve()\
    \ {\n  int N, K;\n  rd(N, K);\n  StaticGraph<void> g(N, 2 * N - 2);\n  rep1(i,\
    \ N - 1) {\n    int u, v;\n    rd(u, v);\n    --u, --v;\n    g.add_edge(u, v);\n\
    \    g.add_edge(v, u);\n  }\n\n  V<pair<int, int>> cl(N);\n  rep(i, N) rd(cl[i].first,\
    \ cl[i].second);\n\n  DynamicUnionFind uf;\n  int sm = 0;\n  vi ans(N);\n  HashMap<int,\
    \ int> val;\n  // reflect data of node i\n  auto update = [&](int i) {\n    uf.unite(cl[i].first,\
    \ cl[i].second,\n             [&](int x, int y) { val[x] += val[y]; });\n    int\
    \ p = uf.find(cl[i].first);\n    if (uf.size(p) > val[p]) {\n      sm++;\n   \
    \   val[p]++;\n    }\n  };\n  // answer queries of subtree i\n  auto query = [&](int\
    \ i) { ans[i] = sm; };\n  // below two function are called if all data must be\
    \ deleted\n  // delete data of node i (if necesarry)\n  auto clear = [&](int)\
    \ {};\n  // delete data related to all (if necesarry)\n  auto reset = [&]() {\n\
    \    uf.clear();\n    sm = 0;\n    val.clear();\n  };\n\n  DSUonTree<decltype(g)>\
    \ dsu(g);\n  dsu.run(update, query, clear, reset);\n\n  each(x, ans) wtn(x);\n\
    }\n"
  dependsOn:
  - template/template.hpp
  - template/util.hpp
  - template/bitop.hpp
  - template/inout.hpp
  - template/debug.hpp
  - template/macro.hpp
  - data-structure/dynamic-union-find.hpp
  - hashmap/hashmap.hpp
  - hashmap/hashmap-base.hpp
  - graph/static-graph.hpp
  - misc/fastio.hpp
  - tree/dsu-on-tree.hpp
  - graph/graph-template.hpp
  isVerificationFile: true
  path: verify/verify-aoj-other/aoj-2995-hashmap.test.cpp
  requiredBy: []
  timestamp: '2021-11-23 10:22:25+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/verify-aoj-other/aoj-2995-hashmap.test.cpp
layout: document
redirect_from:
- /verify/verify/verify-aoj-other/aoj-2995-hashmap.test.cpp
- /verify/verify/verify-aoj-other/aoj-2995-hashmap.test.cpp.html
title: verify/verify-aoj-other/aoj-2995-hashmap.test.cpp
---
