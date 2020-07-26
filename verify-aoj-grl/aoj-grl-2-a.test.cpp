#define PROBLEM \
  "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_A"

#include "../competitive-template.cpp"
#include "../graph/kruskal.cpp"

void solve() {
  ini(N, E);
  auto es = esgraph<int>(N, E, true, false);
  auto mst = kruskal(N, es);
  out(mst);
}