#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
ll ans = 0;
ll n ;
const ll INF = 1LL << 60; //MAX 9223372036854775807
struct edge
{
  ll to;
  ll cost;
  edge() {}
  edge(ll to, ll cost) : to(to), cost(cost){};
};
void dfs(ll x, vector<vector<edge>> &g,vector<vector<ll>> &v, vector<bool> &see)
{
  //点xに対する処理
  see[x] = 1;
  for (auto p : g[x])
  {
    if (see[p.to])continue;
    //進む辺に対する処理（これは木構造でオイラーツアーするために使う）
    dfs(p.to, g,v, see);
    //戻る辺に対する処理
    for (ll i = 1; i < n; i++)
    {
      
    }
  }
  //点xの親に戻る時の処理
}
int main()
{
cin >> n ;
vector<vector<edge>> g(n);
rep(i, n-1)
{
  ll a, c;
  cin >> a >> c;
  g[a].emplace_back(i+1, c);
  g[i+1].emplace_back(a, c);
}
vector<vector<ll>> v(n, vector<ll>(n,INF) );
vector<bool> see(n);

rep(i,n)v[i][0]=0;
dfs(0,g,v,see);
rep(i,n){
  if(v[0][i]>=INF)break;
  else ans=i+1;
}
cout << ans << endl;
return 0;
}