#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
const ll INF = 1LL << 60; //MAX 9223372036854775807

int main()
{
ll n;
cin >> n ;
vector<vector<ll>> g(n);
vector<pair<ll,ll>> v(n);
rep(i, n)
{
  ll a, b;
  cin >> a >> b;
  v[i].first=a;
  v[i].second=b;
  if(i==0)continue;
  g[i].push_back((i-1)/2);
  g[(i-1)/2].push_back(i);
}
vector<ll> par(n);
vector<ll> d(n);
vector<bool> see(n);
{
queue<ll> q;
par[0]=-1;
see[0]=1;
d[0]=1;
q.push(0);
while(!q.empty()){
  auto p=q.front();
  q.pop();
  for(auto r:g[p]){
    if(see[r]!=0)continue;
    par[r]=p;
    d[r]=d[p]+1;
    see[r]=1;
    q.push(r);
  }
}
}
vector<vector<ll>> dp(min(n,(1LL<<9) -1), vector<ll>(100010,INF) );
rep(i,100010)if(i<v[0].second)dp[0][i]=0; else dp[0][i]=v[0].first; 
rep(i,min(n,(1LL<<9) -1)){
  if(i==0)continue;
  rep(j,100010)dp[i][j]=dp[(i-1)/2][j];
  rep(j,100010)if(j-v[i].second>=0)dp[i][j]=max(dp[i][j], dp[(i-1)/2][j-v[i].second]+v[i].first);
}
ll q ;
cin >> q ;
vector<ll> ans(q,0);
rep(i,q){
  ll u , l ;
  cin >> u >>l  ;
  if(u< 1LL<<9)ans[i]=dp[u-1][l];
  else{
    vector<pair<ll,ll>> t;
    ll w=u-1;
    rep(j,d[u-1]-9){
      t.push_back(v[w]);
      w=(w-1)/2;
    }
    ans[i]=dp[w][l];
    ll vv=0,ww=0;
    rep(j,1LL<<t.size()){
      if(j==0)continue;
      ll c=j^(j>>1);
      if(c>>__builtin_ctzll(j) &1LL){vv+=t[__builtin_ctzll(j)].first;ww+=t[__builtin_ctzll(j)].second;}
      else {vv-=t[__builtin_ctzll(j)].first;ww-=t[__builtin_ctzll(j)].second;}
      if(l-ww>=0)ans[i]=max(ans[i],dp[w][l-ww]+vv);
    }
  }
}
for(auto r:ans)cout << r << endl;
return 0;
}