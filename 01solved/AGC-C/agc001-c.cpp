#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
ll ans = 2001;
ll dfs(ll now,ll par,ll k,vector<vector<ll>> &g){
  if(k==0)return 1;
  else {
    ll a=1;
    rep(i,g[now].size()){
      if(g[now][i]==par)continue;
      a+=dfs(g[now][i],now,k-1,g);
    }
    return a;
  }
}

int main()
{
ll n,k;
cin >> n >> k;
if(k==1){
cout << n-2 << endl;
return 0;
}
vector<vector<ll>> g(n);
rep(i, n-1)
{
    ll a,b;
    cin >> a>>b;
    g[a-1].push_back(b-1);
    g[b-1].push_back(a-1); //無向辺
}

if(k%2){
  rep(i,n)rep(j,g[i].size()){
    ans=min(ans,n-dfs(i,g[i][j],k/2,g)-dfs(g[i][j],i,k/2,g));
  }
}
else{
  rep(i,n){
    ans=min(ans,n-dfs(i,-1,k/2,g));
  }
}

cout << ans << endl;
return 0;
}