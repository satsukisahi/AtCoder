#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
ll ans = 0;
void dfs(ll x, vector<vector<ll>> &g, vector<bool> &see,bool &ok,vector<ll> &dist)
{
  //点xに対する処理
  see[x] = 1;
  for (auto p : g[x])
  {
    if (see[p]){
      if(dist[p]%2!=(dist[x]+1)%2)ok=0;
      continue;
    }
    //進む辺に対する処理（これは木構造でオイラーツアーするために使う）
    dist[p]=dist[x]+1;
    dfs(p,g,see,ok,dist);
    //戻る辺に対する処理
  }
  //点xの親に戻る時の処理
}
int main()
{
ll n, m;
cin >> n >> m;
vector<vector<ll>> g(n);
//多重辺がないならsetでもよい（辺を消去したいときなど）この場合はinsert
//set<ll> g[n];
rep(i, m)
{
  ll a, b;
  cin >> a >> b;
  g[a - 1].push_back(b - 1);
  g[b - 1].push_back(a - 1); //無向辺
}
bool ok=1;
vector<ll> dist(n);
vector<bool> see(n);
dfs(0,g,see,ok,dist);
if(ok){
  ll nu=0;
  for(auto p:dist)if(p%2)nu++;
  ans=nu*(n-nu) - m;
}
else{
  ans=n*(n-1)/2-m;
}
cout << ans << endl;
return 0;
}