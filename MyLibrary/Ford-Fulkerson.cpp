#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
ll ans = 0;

template <typename flow_t>
struct FordFulkerson
{
  struct edge
  {
    ll to;
    flow_t cap;
    ll rev;
    bool isrev;
  };

  vector<vector<edge>> graph;
  vector<ll> used;
  const flow_t INF;
  ll timestamp;

  FordFulkerson(ll n) : INF(numeric_limits<flow_t>::max()), timestamp(0)
  {
    graph.resize(n);
    used.assign(n, -1);
  }

  void add_edge(ll from, ll to, flow_t cap)
  {
    graph[from].emplace_back((edge){to, cap, (ll)graph[to].size(), false});
    graph[to].emplace_back((edge){from, 0, (ll)graph[from].size() - 1, true});
  }

  flow_t dfs(ll idx, const ll t, flow_t flow)
  {
    if (idx == t)
      return flow;
    used[idx] = timestamp;
    for (auto &e : graph[idx])
    {
      if (e.cap > 0 && used[e.to] != timestamp)
      {
        flow_t d = dfs(e.to, t, min(flow, e.cap));
        if (d > 0)
        {
          e.cap -= d;
          graph[e.to][e.rev].cap += d;
          return d;
        }
      }
    }
    return 0;
  }

  flow_t max_flow(ll s, ll t)
  {
    flow_t flow = 0;
    for (flow_t f; (f = dfs(s, t, INF)) > 0; timestamp++)
    {
      flow += f;
    }
    return flow;
  }

  void output()
  {
    for (ll i = 0; i < graph.size(); i++)
    {
      for (auto &e : graph[i])
      {
        if (e.isrev)
          continue;
        auto &rev_e = graph[e.to][e.rev];
        cout << i << "->" << e.to << " (flow: " << rev_e.cap << "/" << e.cap + rev_e.cap << ")" << endl;
      }
    }
  }
};

int main()
{
  //宣言 FordFulkerson< ll > g(V);
  //追加 g.add_edge(from,to,cap);
  //結果 g.max_flow(to,from);
  ll v, e;
  cin >> v >> e;
  FordFulkerson<ll> g(v);
  rep(i, e)
  {
    ll a, b, c;
    cin >> a >> b >> c;
    g.add_edge(a, b, c);
  }

  cout << g.max_flow(0, v - 1) << endl;
  return 0;
}
