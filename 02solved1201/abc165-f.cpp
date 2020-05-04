#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)

const ll INF = 1LL << 60; //MAX 9223372036854775807

void dfs(ll x, vector<vector<ll>> &g, vector<bool> &see,vector<vector<ll>> &re,vector<ll> &dp,vector<ll> &a,vector<ll> &ans)
{
  //点xに対する処理
  see[x] = 1;
  auto itr=lower_bound(dp.begin(),dp.end(),a[x]);
  re[x][0]=itr-dp.begin();
  re[x][1]=dp[itr-dp.begin()];
  dp[itr-dp.begin()]=min(dp[itr-dp.begin()],a[x]);
  ans[x]=lower_bound(dp.begin(),dp.end(),INF-1)-dp.begin();
  for (auto p : g[x])
  {
    if (see[p])continue;
    //進む辺に対する処理（これは木構造でオイラーツアーするために使う）
    dfs(p, g, see,re,dp,a,ans);
    //戻る辺に対する処理
  }
  //点xの親に戻る時の処理
  dp[re[x][0]]=re[x][1];
}

int main()
{
ll n ;
cin >> n ;
vector<ll> a(n);
rep(i, n){
  cin >> a[i];
}
vector<vector<ll>> g(n);
rep(i, n-1)
{
  ll a, b;
  cin >> a >> b;
  g[a - 1].push_back(b - 1);
  g[b - 1].push_back(a - 1); 
}
vector<ll> dp(n,INF);
vector<bool> see(n);
vector<ll> ans(n,0);
vector<vector<ll>> re(n, vector<ll>(2,0) );

dfs(0,g,see,re,dp,a,ans);

for(auto an:ans)cout << an << endl;
return 0;
}