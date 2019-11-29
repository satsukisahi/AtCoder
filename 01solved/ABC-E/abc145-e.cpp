#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
ll ans = 0;
int main()
{
ll n , t ;
cin >> n >> t ;
vector<pair<ll,ll>> v(n);
rep(i,n){
  ll a , b ;
  cin >> a >> b ;
  v[i].first=a;
  v[i].second=b;
}
sort(v.begin(),v.end());
vector<vector<ll>> dp(n+1 ,vector<ll>(t+3010) );
rep(i,n){
  rep(j,t){
    dp[i+1][j]=dp[i][j];
  }
  rep(j,t){
    dp[i+1][j+v[i].first]=max(dp[i+1][j+v[i].first],dp[i][j]+v[i].second);
  }
}
rep(i,n+1)rep(j,t+3010){
  ans=max(ans,dp[i][j]);
}
cout << ans << endl;
return 0;
}