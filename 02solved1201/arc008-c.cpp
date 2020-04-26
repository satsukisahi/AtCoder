#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
double ans = 0;
const ll INF = 1LL << 60; //MAX 9223372036854775807

struct edge
{
  ll to;
  double cost;
  edge() {}
  edge(ll to, double cost) : to(to), cost(cost){};
};
vector<double> dijkstra(ll s, vector<vector<edge>> &g)
{
  //pair.first=距離,pair.second=点
  priority_queue<pair<double, ll>, vector<pair<double, ll>>, greater<pair<double, ll>>> q;
  vector<double> dist(g.size(), INF);
  dist[s] = 0;
  q.push({0, s});

  while (!q.empty())
  {
    pair<double, ll> p = q.top();
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
ll n ;
cin >> n ;
vector<vector<ll>> v(n, vector<ll>(4,0) );
vector<vector<edge>> g(n);
rep(i, n)
{
  rep(j,4)cin >> v[i][j];
}
if(n==1){cout <<0 <<endl;return 0;}
rep(i,n-1)for (ll j = i+1; j < n; j++)
{
  double d=sqrt((v[i][0]-v[j][0])*(v[i][0]-v[j][0])+(v[i][1]-v[j][1])*(v[i][1]-v[j][1]));
  g[i].emplace_back(j,d/min(v[i][2],v[j][3]));
  g[j].emplace_back(i,d/min(v[i][3],v[j][2]));
}
vector<double> d = dijkstra(0, g);
sort(d.begin(),d.end());
rep(i,n-1)ans=max(ans,d[n-1-i]+i);
cout<<fixed<<setprecision(12)<<ans<<endl;
return 0;
}