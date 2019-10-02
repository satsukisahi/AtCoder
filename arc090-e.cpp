#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
ll ans = 0;
const ll mo = 1000000007;
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
struct edge {
    ll to;
    ll cost;
    edge() {}
    edge(ll to, ll cost) : to(to), cost(cost) {};
};
int main()
{
ll n,m;
cin >> n >> m ;
ll s , t ;
cin >> s >> t ;s--;t--;
vector<vector<edge>> g(n);
rep(i, m)
{
    ll a,b,c;
    cin >> a>>b>>c;
    g[a-1].emplace_back(b-1, c);
    g[b-1].emplace_back(a-1, c); 
}
vector<ll> dist = dijkstra(s, g);


cout << ans << endl;
return 0;
}