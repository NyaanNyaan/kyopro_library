---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/rollback-union-find.hpp
    title: "Rollback\u3064\u304DUnion Find"
  - icon: ':heavy_check_mark:'
    path: hashmap/hashmap-base.hpp
    title: "Hash Map(base)\u3000(\u30CF\u30C3\u30B7\u30E5\u30DE\u30C3\u30D7\u30FB\u57FA\
      \u5E95\u30AF\u30E9\u30B9)"
  - icon: ':heavy_check_mark:'
    path: hashmap/hashmap.hpp
    title: "\u30CF\u30C3\u30B7\u30E5\u30DE\u30C3\u30D7(\u9023\u60F3\u914D\u5217)"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-ds/yosupo-offline-dynamic-connectivity.test.cpp
    title: verify/verify-yosupo-ds/yosupo-offline-dynamic-connectivity.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graph/offline-dynamic-connectivity.hpp\"\n\n#line 2 \"data-structure/rollback-union-find.hpp\"\
    \n\nstruct RollbackUnionFind {\n  vector<int> data;\n  stack<pair<int, int> >\
    \ history;\n  int inner_snap;\n\n  RollbackUnionFind(int sz) : inner_snap(0) {\
    \ data.assign(sz, -1); }\n\n  bool unite(int x, int y) {\n    x = find(x), y =\
    \ find(y);\n    history.emplace(x, data[x]);\n    history.emplace(y, data[y]);\n\
    \    if (x == y) return false;\n    if (data[x] > data[y]) swap(x, y);\n    data[x]\
    \ += data[y];\n    data[y] = x;\n    return true;\n  }\n\n  int find(int k) {\n\
    \    if (data[k] < 0) return k;\n    return find(data[k]);\n  }\n\n  int same(int\
    \ x, int y) { return find(x) == find(y); }\n\n  int size(int k) { return (-data[find(k)]);\
    \ }\n\n  void undo() {\n    data[history.top().first] = history.top().second;\n\
    \    history.pop();\n    data[history.top().first] = history.top().second;\n \
    \   history.pop();\n  }\n\n  void snapshot() { inner_snap = int(history.size()\
    \ >> 1); }\n\n  int get_state() { return int(history.size() >> 1); }\n\n  void\
    \ rollback(int state = -1) {\n    if (state == -1) state = inner_snap;\n    state\
    \ <<= 1;\n    assert(state <= (int)history.size());\n    while (state < (int)history.size())\
    \ undo();\n  }\n};\n\n/**\n * @brief Rollback\u3064\u304DUnion Find\n * @docs\
    \ docs/data-structure/rollback-union-find.md\n */\n#line 2 \"hashmap/hashmap.hpp\"\
    \n\n#line 2 \"hashmap/hashmap-base.hpp\"\n\n#include <cstdint>\nusing namespace\
    \ std;\n\nnamespace HashMapImpl {\nusing u32 = uint32_t;\nusing u64 = uint64_t;\n\
    \ntemplate <typename Key, typename Data>\nstruct HashMapBase;\n\ntemplate <typename\
    \ Key, typename Data>\nstruct itrB\n    : iterator<bidirectional_iterator_tag,\
    \ Data, ptrdiff_t, Data*, Data&> {\n  using base =\n      iterator<bidirectional_iterator_tag,\
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
    \      if (p->occupied_flag[i] && !p->deleted_flag[i]) break;\n    } while (true);\n\
    \    return (*this);\n  }\n  itrB operator++(int) {\n    itrB it(*this);\n   \
    \ ++(*this);\n    return it;\n  }\n  itrB& operator--() {\n    do {\n      i--;\n\
    \      if (p->occupied_flag[i] && !p->deleted_flag[i]) break;\n      assert(i\
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
    \ nullptr_t> = nullptr>\n  inline Key data_to_key(const D& dat) const {\n    return\
    \ dat;\n  }\n  template <\n      typename D = Data,\n      enable_if_t<is_same<decltype(D::first),\
    \ Key>::value, nullptr_t> = nullptr>\n  inline Key data_to_key(const D& dat) const\
    \ {\n    return dat.first;\n  }\n\n  void reallocate(u32 ncap) {\n    vector<Data>\
    \ ndata(ncap);\n    vector<bool> nf(ncap);\n    shift = 64 - __lg(ncap);\n   \
    \ for (u32 i = 0; i < cap; i++) {\n      if (occupied_flag[i] && !deleted_flag[i])\
    \ {\n        u32 h = hash(data[i]);\n        while (nf[h]) h = (h + 1) & (ncap\
    \ - 1);\n        ndata[h] = move(data[i]);\n        nf[h] = true;\n      }\n \
    \   }\n    data.swap(ndata);\n    occupied_flag.swap(nf);\n    cap = ncap;\n \
    \   occupied = s;\n    deleted_flag.resize(cap);\n    fill(std::begin(deleted_flag),\
    \ std::end(deleted_flag), false);\n  }\n\n  inline bool extend_rate(u32 x) const\
    \ { return x * 2 >= cap; }\n\n  inline bool shrink_rate(u32 x) const {\n    return\
    \ HASHMAP_DEFAULT_SIZE < cap && x * 10 <= cap;\n  }\n\n  inline void extend()\
    \ { reallocate(cap << 1); }\n\n  inline void shrink() { reallocate(cap >> 1);\
    \ }\n\n public:\n  u32 cap, s, occupied;\n  vector<Data> data;\n  vector<bool>\
    \ occupied_flag, deleted_flag;\n  u32 shift;\n  static u64 r;\n  static constexpr\
    \ uint32_t HASHMAP_DEFAULT_SIZE = 4;\n\n  explicit HashMapBase()\n      : cap(HASHMAP_DEFAULT_SIZE),\n\
    \        s(0),\n        occupied(0),\n        data(cap),\n        occupied_flag(cap),\n\
    \        deleted_flag(cap),\n        shift(64 - __lg(cap)) {}\n\n  itr begin()\
    \ const {\n    u32 h = 0;\n    while (h != cap) {\n      if (occupied_flag[h]\
    \ && !deleted_flag[h]) break;\n      h++;\n    }\n    return itr(h, this);\n \
    \ }\n  itr end() const { return itr(this->cap, this); }\n\n  friend itr begin(const\
    \ HashMapBase& h) { return h.begin(); }\n  friend itr end(const HashMapBase& h)\
    \ { return h.end(); }\n\n  itr find(const Key& key) const {\n    u32 h = inner_hash(key);\n\
    \    while (true) {\n      if (occupied_flag[h] == false) return this->end();\n\
    \      if (data_to_key(data[h]) == key) {\n        if (deleted_flag[h] == true)\
    \ return this->end();\n        return itr(h, this);\n      }\n      h = (h + 1)\
    \ & (cap - 1);\n    }\n  }\n\n  bool contain(const Key& key) const { return find(key)\
    \ != this->end(); }\n\n  itr insert(const Data& d) {\n    u32 h = hash(d);\n \
    \   while (true) {\n      if (occupied_flag[h] == false) {\n        if (extend_rate(occupied\
    \ + 1)) {\n          extend();\n          h = hash(d);\n          continue;\n\
    \        }\n        data[h] = d;\n        occupied_flag[h] = true;\n        ++occupied,\
    \ ++s;\n        return itr(h, this);\n      }\n      if (data_to_key(data[h])\
    \ == data_to_key(d)) {\n        if (deleted_flag[h] == true) {\n          data[h]\
    \ = d;\n          deleted_flag[h] = false;\n          ++s;\n        }\n      \
    \  return itr(h, this);\n      }\n      h = (h + 1) & (cap - 1);\n    }\n  }\n\
    \n  // tips for speed up :\n  // if return value is unnecessary, make argument_2\
    \ false.\n  itr erase(itr it, bool get_next = true) {\n    if (it == this->end())\
    \ return this->end();\n    s--;\n    if (!get_next) {\n      this->deleted_flag[it.i]\
    \ = true;\n      if (shrink_rate(s)) shrink();\n      return this->end();\n  \
    \  }\n    itr nxt = it;\n    nxt++;\n    this->deleted_flag[it.i] = true;\n  \
    \  if (shrink_rate(s)) {\n      Data d = data[nxt.i];\n      shrink();\n     \
    \ it = find(data_to_key(d));\n    }\n    return nxt;\n  }\n\n  itr erase(const\
    \ Key& key) { return erase(find(key)); }\n\n  int count(const Key& key) { return\
    \ find(key) == end() ? 0 : 1; }\n\n  bool empty() const { return s == 0; }\n\n\
    \  int size() const { return s; }\n\n  void clear() {\n    fill(std::begin(occupied_flag),\
    \ std::end(occupied_flag), false);\n    fill(std::begin(deleted_flag), std::end(deleted_flag),\
    \ false);\n    s = occupied = 0;\n  }\n\n  void reserve(int n) {\n    if (n <=\
    \ 0) return;\n    n = 1 << min(23, __lg(n) + 2);\n    if (cap < u32(n)) reallocate(n);\n\
    \  }\n};\n\ntemplate <typename Key, typename Data>\nuint64_t HashMapBase<Key,\
    \ Data>::r =\n    chrono::duration_cast<chrono::nanoseconds>(\n        chrono::high_resolution_clock::now().time_since_epoch())\n\
    \        .count();\n\n}  // namespace HashMapImpl\n\n/**\n * @brief Hash Map(base)\u3000\
    (\u30CF\u30C3\u30B7\u30E5\u30DE\u30C3\u30D7\u30FB\u57FA\u5E95\u30AF\u30E9\u30B9\
    )\n */\n#line 4 \"hashmap/hashmap.hpp\"\n\ntemplate <typename Key, typename Val>\n\
    struct HashMap : HashMapImpl::HashMapBase<Key, pair<Key, Val>> {\n  using base\
    \ = typename HashMapImpl::HashMapBase<Key, pair<Key, Val>>;\n  using HashMapImpl::HashMapBase<Key,\
    \ pair<Key, Val>>::HashMapBase;\n  using Data = pair<Key, Val>;\n\n  Val& operator[](const\
    \ Key& k) {\n    typename base::u32 h = base::inner_hash(k);\n    while (true)\
    \ {\n      if (base::occupied_flag[h] == false) {\n        if (base::extend_rate(base::occupied\
    \ + 1)) {\n          base::extend();\n          h = base::hash(k);\n         \
    \ continue;\n        }\n        base::data[h].first = k;\n        base::data[h].second\
    \ = Val();\n        base::occupied_flag[h] = true;\n        ++base::occupied,\
    \ ++base::s;\n        return base::data[h].second;\n      }\n      if (base::data[h].first\
    \ == k) {\n        if (base::deleted_flag[h] == true) {\n          base::data[h].second\
    \ = Val();\n          base::deleted_flag[h] = false;\n          ++base::s;\n \
    \       }\n        return base::data[h].second;\n      }\n      h = (h + 1) &\
    \ (base::cap - 1);\n    }\n  }\n\n  typename base::itr emplace(const Key& key,\
    \ const Val& val) {\n    return base::insert(Data(key, val));\n  }\n};\n\n/*\n\
    \ * @brief \u30CF\u30C3\u30B7\u30E5\u30DE\u30C3\u30D7(\u9023\u60F3\u914D\u5217\
    )\n * @docs docs/hashmap/hashmap.md\n **/\n#line 5 \"graph/offline-dynamic-connectivity.hpp\"\
    \n\nstruct OffLineDynamicConnectivity {\n  int N, Q, segsz;\n  RollbackUnionFind\
    \ uf;\n  vector<vector<pair<int, int>>> seg, qadd, qdel;\n  HashMap<pair<int,\
    \ int>, pair<int, int>> cnt;\n\n  OffLineDynamicConnectivity(int n, int q)\n \
    \     : N(n), Q(q), uf(n), qadd(q), qdel(q) {\n    segsz = 1;\n    while (segsz\
    \ < Q) segsz *= 2;\n    seg.resize(segsz * 2);\n  }\n\n  void add_edge(int t,\
    \ int u, int v) { qadd[t].emplace_back(u, v); }\n  void del_edge(int t, int u,\
    \ int v) { qdel[t].emplace_back(u, v); }\n\n  void build() {\n    for (int i =\
    \ 0; i < Q; i++) {\n      for (auto& e : qadd[i]) {\n        auto& dat = cnt[e];\n\
    \        if (dat.second++ == 0) dat.first = i;\n      }\n      for (auto& e :\
    \ qdel[i]) {\n        auto& dat = cnt[e];\n        if (--dat.second == 0) segment(e,\
    \ dat.first, i);\n      }\n    }\n    for (auto& [e, dat] : cnt) {\n      if (dat.second\
    \ != 0) segment(e, dat.first, Q);\n    }\n  }\n\n  template <typename ADD, typename\
    \ DEL, typename QUERY>\n  void dfs(const ADD& add, const DEL& del, const QUERY&\
    \ query, int id, int l,\n           int r) {\n    if (Q <= l) return;\n    int\
    \ state = uf.get_state();\n    vector<pair<int, int>> es;\n    for (auto& [u,\
    \ v] : seg[id]) {\n      if (!uf.same(u, v)) {\n        uf.unite(u, v);\n    \
    \    add(u, v);\n        es.emplace_back(u, v);\n      }\n    }\n    if (l + 1\
    \ == r) {\n      query(l);\n    } else {\n      dfs(add, del, query, id * 2 +\
    \ 0, l, (l + r) >> 1);\n      dfs(add, del, query, id * 2 + 1, (l + r) >> 1, r);\n\
    \    }\n    for (auto& [u, v] : es) del(u, v);\n    uf.rollback(state);\n  }\n\
    \n  template <typename ADD, typename DEL, typename QUERY>\n  void run(const ADD&\
    \ add, const DEL& del, const QUERY& query) {\n    dfs(add, del, query, 1, 0, segsz);\n\
    \  }\n\n private:\n  void segment(pair<int, int>& e, int l, int r) {\n    int\
    \ L = l + segsz;\n    int R = r + segsz;\n    while (L < R) {\n      if (L & 1)\
    \ seg[L++].push_back(e);\n      if (R & 1) seg[--R].push_back(e);\n      L >>=\
    \ 1, R >>= 1;\n    }\n  }\n};\n"
  code: "#pragma once\n\n#include \"../data-structure/rollback-union-find.hpp\"\n\
    #include \"../hashmap/hashmap.hpp\"\n\nstruct OffLineDynamicConnectivity {\n \
    \ int N, Q, segsz;\n  RollbackUnionFind uf;\n  vector<vector<pair<int, int>>>\
    \ seg, qadd, qdel;\n  HashMap<pair<int, int>, pair<int, int>> cnt;\n\n  OffLineDynamicConnectivity(int\
    \ n, int q)\n      : N(n), Q(q), uf(n), qadd(q), qdel(q) {\n    segsz = 1;\n \
    \   while (segsz < Q) segsz *= 2;\n    seg.resize(segsz * 2);\n  }\n\n  void add_edge(int\
    \ t, int u, int v) { qadd[t].emplace_back(u, v); }\n  void del_edge(int t, int\
    \ u, int v) { qdel[t].emplace_back(u, v); }\n\n  void build() {\n    for (int\
    \ i = 0; i < Q; i++) {\n      for (auto& e : qadd[i]) {\n        auto& dat = cnt[e];\n\
    \        if (dat.second++ == 0) dat.first = i;\n      }\n      for (auto& e :\
    \ qdel[i]) {\n        auto& dat = cnt[e];\n        if (--dat.second == 0) segment(e,\
    \ dat.first, i);\n      }\n    }\n    for (auto& [e, dat] : cnt) {\n      if (dat.second\
    \ != 0) segment(e, dat.first, Q);\n    }\n  }\n\n  template <typename ADD, typename\
    \ DEL, typename QUERY>\n  void dfs(const ADD& add, const DEL& del, const QUERY&\
    \ query, int id, int l,\n           int r) {\n    if (Q <= l) return;\n    int\
    \ state = uf.get_state();\n    vector<pair<int, int>> es;\n    for (auto& [u,\
    \ v] : seg[id]) {\n      if (!uf.same(u, v)) {\n        uf.unite(u, v);\n    \
    \    add(u, v);\n        es.emplace_back(u, v);\n      }\n    }\n    if (l + 1\
    \ == r) {\n      query(l);\n    } else {\n      dfs(add, del, query, id * 2 +\
    \ 0, l, (l + r) >> 1);\n      dfs(add, del, query, id * 2 + 1, (l + r) >> 1, r);\n\
    \    }\n    for (auto& [u, v] : es) del(u, v);\n    uf.rollback(state);\n  }\n\
    \n  template <typename ADD, typename DEL, typename QUERY>\n  void run(const ADD&\
    \ add, const DEL& del, const QUERY& query) {\n    dfs(add, del, query, 1, 0, segsz);\n\
    \  }\n\n private:\n  void segment(pair<int, int>& e, int l, int r) {\n    int\
    \ L = l + segsz;\n    int R = r + segsz;\n    while (L < R) {\n      if (L & 1)\
    \ seg[L++].push_back(e);\n      if (R & 1) seg[--R].push_back(e);\n      L >>=\
    \ 1, R >>= 1;\n    }\n  }\n};"
  dependsOn:
  - data-structure/rollback-union-find.hpp
  - hashmap/hashmap.hpp
  - hashmap/hashmap-base.hpp
  isVerificationFile: false
  path: graph/offline-dynamic-connectivity.hpp
  requiredBy: []
  timestamp: '2023-03-25 00:28:17+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-yosupo-ds/yosupo-offline-dynamic-connectivity.test.cpp
documentation_of: graph/offline-dynamic-connectivity.hpp
layout: document
redirect_from:
- /library/graph/offline-dynamic-connectivity.hpp
- /library/graph/offline-dynamic-connectivity.hpp.html
title: graph/offline-dynamic-connectivity.hpp
---
