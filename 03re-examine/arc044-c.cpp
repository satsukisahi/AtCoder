#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
ll ans = 0;
const ll INF = 1LL << 60; //MAX 9223372036854775807

int main()
{
ll w , h , q ;
cin >> w >> h >> q ;
vector<vector<ll>> x(100000);
vector<vector<ll>> y(100000);
rep(i,q){
  ll t , d , xx ;
  cin >> t >> d >> xx ;
  if(d==0)x[t-1].push_back(xx-1);
  else y[t-1].push_back(xx-1);
}
vector<ll> dp(w);
vector<ll> dpp(h);
rep(i,100000){
  sort(x[i].begin(),x[i].end());
  rep(j,x[i].size()){
    if(x[i][j]!=w-1){
      dp[x[i][j]+1]=min(dp[x[i][j]+1],dp[x[i][j]]+1);
    }
  }
  reverse(x[i].begin(),x[i].end());
  rep(j,x[i].size()){
    if(x[i][j]!=0){
      dp[x[i][j]-1]=min(dp[x[i][j]-1],dp[x[i][j]]+1);
    }
  }
  rep(j,x[i].size()){
    dp[x[i][j]]=INF;
  }
}
ans+=*min_element(dp.begin(),dp.end());
rep(i,100000){
  sort(y[i].begin(),y[i].end());
  rep(j,y[i].size()){
    if(y[i][j]!=h-1){
      dpp[y[i][j]+1]=min(dpp[y[i][j]+1],dpp[y[i][j]]+1);
    }
  }
  reverse(y[i].begin(),y[i].end());
  rep(j,y[i].size()){
    if(y[i][j]!=0){
      dpp[y[i][j]-1]=min(dpp[y[i][j]-1],dpp[y[i][j]]+1);
    }
  }
  rep(j,y[i].size()){
    dpp[y[i][j]]=INF;
  }
}
ans+=*min_element(dpp.begin(),dpp.end());
if(ans>(1LL<<40))ans=-1;
cout << ans << endl;
return 0;
}