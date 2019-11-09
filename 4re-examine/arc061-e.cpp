#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
const ll INF = 1LL << 60; //MAX 9223372036854775807
ll n, m;

struct edge
{
  pair<ll, ll> to;
  ll cost;
  edge() {}
  edge(pair<ll, ll> to, ll cost) : to(to), cost(cost){};
};
ll dijkstra(pair<ll, ll> s, map<pair<ll, ll>, vector<edge>> &g)
{
  priority_queue<pair<ll, pair<ll, ll>>, vector<pair<ll, pair<ll, ll>>>, greater<pair<ll, pair<ll, ll>>>> q;
  map<pair<ll, ll>,ll> dist;
  dist[s] = 1;
  q.push({0, s});

  while (!q.empty())
  {
    pair<ll, pair<ll, ll>> p = q.top();
    q.pop();
    pair<ll, ll> v = p.second;
    if (dist[v] < p.first)
      continue;
    rep(i, g[v].size())
    {
      edge e = g[v][i];
      if(dist[e.to]==0)dist[e.to]=INF;
      if (dist[e.to] > dist[v] + e.cost)
      {
        dist[e.to] = dist[v] + e.cost;
        q.push({dist[e.to], e.to});
      }
    }
  }
  pair<ll, ll> pp={n-1,-1};
  return dist[pp];
}
int main()
{
cin >> n >> m;
map<pair<ll, ll>, vector<edge>> g;
set<ll> s[n];
rep(i, m)
{
  ll a, b, c;
  cin >> a >> b >> c;
  pair<ll, ll> p = {b - 1, c};
  g[{a - 1, c}].emplace_back(p, 0);
  p = {a - 1, c};
  g[{b - 1, c}].emplace_back(p, 0);
  s[a-1].insert(c);
  s[b-1].insert(c);
}
rep(i,n){
  for(auto c:s[i]){
    pair<ll, ll> p = {i , c};
    g[{i , -1}].emplace_back(p, 1);
    p = {i , -1};
    g[{i , c}].emplace_back(p, 0);
  }
}
pair<ll, ll> pp={0,-1};
cout << dijkstra(pp,g)-1 << endl;
return 0;
}