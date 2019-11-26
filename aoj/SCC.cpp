#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
//http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_C&lang=jp

template <typename G>
struct StronglyConnectedComponents
{
  const G &g;
  vector<vector<ll>> ng, rg;      // normal-graphとreversed-graph
  vector<ll> compo, order, used; // compo…頂点がどの成分に属しているか、order…帰りがけ順で何番目か

  StronglyConnectedComponents(G &g) : g(g), ng(g.size()), rg(g.size()), compo(g.size(), -1), used(g.size())
  {
    for (ll i = 0; i < g.size(); i++)
      for (auto t : g[i])
      {
        ng[i].emplace_back((ll)t);
        rg[(ll)t].emplace_back(i); // 逆辺
      }
  }

  // []で聞かれたときは成分番号を返す
  ll operator[](ll k) { return compo[k]; }

  void dfs(ll now)
  {
    if (used[now])
      return;
    used[now] = true;
    for (auto to : ng[now])
      dfs(to);
    order.emplace_back(now);
  }

  void rdfs(ll now, ll count)
  {
    // used代わりに結果を入れていく
    if (compo[now] != -1)
      return;
    compo[now] = count;
    for (auto to : rg[now])
      rdfs(to, count);
  }

  void build(vector<vector<ll>> &ret)
  {
    // 普通にDFS、辺の向きを変えてもう一度DFS
    for (ll i = 0; i < ng.size(); i++)
      dfs(i);
    reverse(order.begin(), order.end());
    ll group = 0;
    for (auto i : order)
      if (compo[i] == -1)
        rdfs(i, group), group++;

    // 縮めたグラフを構築する
    ret.resize(group);
    for (ll i = 0; i < g.size(); i++)
    { // 全ての辺について
      for (auto &to : g[i])
      {
        ll s = compo[i], t = compo[to];
        if (s != t)
          ret[s].emplace_back(t);
      }
    }
  }
};
int main()
{
ll n, m;
cin >> n >> m;
vector<vector<ll>> g(n); //最初の有向グラフ
vector<vector<ll>> gg;   //閉路をつぶしたDAG
rep(i, m)
{
  ll a, b;
  cin >> a >> b;
  g[a].push_back(b);
}
StronglyConnectedComponents<vector<vector<ll>>> scc(g);
scc.build(gg);

//scc[頂点番号]が同じなら同じ閉路に属す
ll q;
cin >> q;
rep(i, q)
{
  ll u, v;
  cin >> u >> v;
  cout << (scc[u] == scc[v]) << endl;
}

return 0;
}