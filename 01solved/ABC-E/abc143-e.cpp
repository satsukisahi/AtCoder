#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
const ll INF = 1LL << 60; //MAX 9223372036854775807
ll n , m , l ;

ll w=100000000000;
struct edge {
    ll to;
    ll cost;
    edge() {}
    edge(ll to, ll cost) : to(to), cost(cost) {};
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
      ll dd;
      if(e.cost>l)continue;
      if(dist[v]%w+e.cost>l)dd=(dist[v]/w)*w+w+e.cost;
      else dd=dist[v]+e.cost;
      if (dist[e.to] > dd)
      {
        dist[e.to] = dd;
        q.push({dist[e.to], e.to});
      }
    }
  }
  return dist;
}
int main()
{
cin >> n >> m >> l ;
vector<vector<edge>> g(n);
rep(i,m){
  ll a , b , c ;
  cin >> a >> b >> c ;
  g[a-1].emplace_back(b-1,c);
  g[b-1].emplace_back(a-1,c);
}
ll q ;
cin >> q ;
vector<vector<ll>> v(n);
rep(i,n)v[i]=dijkstra(i, g);
rep(i,q){
  ll s , t ;
  cin >> s >> t ;
  cout <<(( (v[s-1][t-1]/w)>100000 ) ? -1 : (v[s-1][t-1]/w) )<< endl;
  
}

return 0;
}