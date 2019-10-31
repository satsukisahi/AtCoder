#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
const ll INF = 1LL << 60; //MAX 9223372036854775807

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
ll n, m,s,t;
cin >> n >> m >> s >> t ;
vector<vector<edge>> g(n);
vector<vector<edge>> gg(n);
rep(i, m)
{
  ll a, b, c , d;
  cin >> a >> b >> c >> d;
  g[a - 1].emplace_back(b - 1, c);
  g[b - 1].emplace_back(a - 1, c);
  gg[a - 1].emplace_back(b - 1, d);
  gg[b - 1].emplace_back(a - 1, d);
}
auto v=dijkstra(s-1,g);
auto vv=dijkstra(t-1,gg);
vector<pair<ll,ll>> p;
rep(i,n){
  p.emplace_back(v[i]+vv[i],i);
}
sort(p.begin(),p.end());
ll itr=0;
rep(i,n){
  while(p[itr].second<i)itr++;
  cout << 1000000000000000-p[itr].first << endl;
  
}
return 0;
}