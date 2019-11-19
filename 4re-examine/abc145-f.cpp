#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
const ll INF = 1LL << 60; //MAX 9223372036854775807
ll ans = INF;

int main()
{
ll n , k ;
cin >> n >> k ;
vector<ll> h(n+1);
rep(i, n){
  cin >> h[i+1];
}
vector<vector<ll>> dp(n-k+1, vector<ll>(n+1,INF) );
dp[0][0]=0;
rep(i,n){
  rep(j,n-k){
    rep(l,i+1){
      dp[j+1][i+1]=min(dp[j+1][i+1],dp[j][l]+max(0LL,h[i+1]-h[l]));
    }
  }
}
rep(i,n+1){
  ans=min(ans,dp[n-k][i]);
}
cout << ans << endl;
return 0;
}