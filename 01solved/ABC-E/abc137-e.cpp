#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
ll ans = 0;
const ll INF = 1LL << 60; //MAX 9223372036854775807

struct edge {
    ll to;
    ll cost;
    edge() {}
    edge(ll to, ll cost) : to(to), cost(cost) {};
};
void dfs(ll x, vector<vector<edge>> &g, bool *see)
{
  //点xに対する処理
  see[x] = 1;
  for (auto p : g[x])
  {
    if (see[p.to])
        continue;
    //進む辺に対する処理
    dfs(p.to, g, see);
    //戻る辺に対する処理
  }
}
vector<ll> bellman_ford(ll s, vector<vector<edge>> &g)
{
  //pair.first=距離,pair.second=点
  vector<ll> dist(g.size(), INF);
  dist[s] = 0;
  //頂点数-1回全ての辺を見る操作を繰り返す
  rep(i,g.size()-1){
    rep(j,g.size()){
      if(dist[j]==INF)continue;
      rep(k,g[j].size()){
        dist[g[j][k].to]=min(dist[g[j][k].to],dist[j]+g[j][k].cost);
      }
    }
  }
  //ここで更新があったら負のサイクルがある
  rep(j,g.size()){
    if(dist[j]==INF)continue;
    rep(k,g[j].size()){
      if(dist[g[j][k].to]>dist[j]+g[j][k].cost) return vector<ll>();
    }
  }
  return dist;
}
int main()
{
ll n , m , p ;
cin >> n >> m >> p ;
vector<vector<edge>> g(n);
vector<vector<edge>> gg(n);
rep(i, m)
{
    ll a,b,c;
    cin >> a>>b>>c;
    g[a-1].emplace_back(b-1, -(c-p));
    gg[b-1].emplace_back(a-1, 0);
}
bool see[n]={};
bool see2[n]={};
dfs(0,g,see);
dfs(n-1,gg,see2);
rep(i,n){
  if(!(see[i]==1&&see2[i]==1)){
    g[i].clear();
  }
}
auto v=bellman_ford(0,g);
if(v.size()==0){
  cout << -1 << endl;
  return 0;
}
ans=-v[n-1];
if(ans<0)ans=0;
cout << ans << endl;
return 0;
}
