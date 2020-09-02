#define PROBLEM "https://judge.yosupo.jp/problem/two_edge_connected_components"

#include "../../competitive-template.hpp"
#include "../../graph/graph-template.hpp"
#include "../../graph/lowlink.hpp"
#include "../../graph/two-edge-connected-components.hpp"

void solve() {
  ini(N, M);
  auto g = graph(N, M, false, false);
  TwoEdgeConnectedComponents<vvi> low(g);
  int s = low.groups.size();
  out(s);
  rep(i, s) {
    cout << (low.groups[i].size()) << " ";
    out(low.groups[i]);
  }
}