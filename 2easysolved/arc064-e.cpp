#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
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
ll xs , ys , xt , yt ;
cin >> xs >> ys >> xt >> yt ;
ll n ;
cin >> n ;
vector<vector<ll>> v(n+2, vector<ll>(3,0) );
v[0][0]=xs;
v[0][1]=ys;
v[n+1][0]=xt;
v[n+1][1]=yt;
rep(i, n)
{
  ll a, b, c;
  cin >> a >> b >> c;
  v[i+1][0]=a;
  v[i+1][1]=b;
  v[i+1][2]=c;
}
vector<vector<edge>> g(n+2);
for (ll i = 0; i < n+1; i++)
{
  for (ll j = i; j < n+2; j++)
  {
    double di=sqrt((v[i][0]-v[j][0])*(v[i][0]-v[j][0])+(v[i][1]-v[j][1])*(v[i][1]-v[j][1]))-v[i][2]-v[j][2];
    if(di<0)di=0;
    g[i].emplace_back(j,di);
    g[j].emplace_back(i,di);
  }
}

vector<double> ans = dijkstra(0, g);
cout<<fixed<<setprecision(12)<<ans[n+1]<<endl;
return 0;
}