#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
const ll INF = 1LL << 60; //MAX 9223372036854775807
//http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A
struct edge
{
  ll to;
  ll cost;
  edge() {}
  edge(ll to, ll cost) : to(to), cost(cost){};
};

vector<ll> dijkstra(ll s, vector<vector<edge>> &g)
{
  //pair.first=距離,pair.second=点
  priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> q;
  vector<ll> dist(g.size(), INF);
  dist[s] = 0;
  q.push({0, s});

  while (!q.empty())
  {
    pair<ll, ll> p = q.top();
    q.pop();
    ll v = p.second;
    if (dist[v] < p.first)
      continue;
    rep(i, g[v].size())
    {
      edge e = g[v][i];
      if (dist[e.to] > dist[v] + e.cost)
      {
        dist[e.to] = dist[v] + e.cost;
        q.push({dist[e.to], e.to});
      }
    }
  }
  return dist;
}

int main()
{
ll n, m, r;
cin >> n >> m >> r; //頂点数,辺数,始点

vector<vector<edge>> g(n);
rep(i, m)
{
  ll a, b, c;
  cin >> a >> b >> c;
  g[a].emplace_back(b, c);
}

vector<ll> ans = dijkstra(r, g);
for (int i = 0; i < ans.size(); ++i)
{
  if (ans[i] < INF / 2)
    cout << ans[i] << endl;
  else
    cout << "INF" << endl;
}
return 0;
}
