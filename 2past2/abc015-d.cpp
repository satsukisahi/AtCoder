#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
const ll mo = 1000000007;
const ll INF = 1LL << 59; //MAX 9223372036854775807
ll ans = 0;
ll dp[51][10001][51]={};


int main()
{
ll w,n,k;
cin >> w >> n >> k;
pair<ll,ll> t[n];
rep(i, n){
    cin >> t[i].first >> t[i].second;
}
rep(i,n){
    rep(j,w+1)rep(l,k+1){
        if(dp[i][j][l]!=0){
            dp[i+1][j][l]=max(dp[i+1][j][l],dp[i][j][l]);
            if(j+t[i].first<=w&&l+1<=k)dp[i+1][j+t[i].first][l+1]=max(dp[i][j][l]+t[i].second,dp[i+1][j+t[i].first][l+1]);
            }
        }
    dp[i+1][t[i].first][1]=max(dp[i+1][t[i].first][1],t[i].second);
}
rep(j,w+1)rep(l,n+1){
    ans=max(dp[n][j][l],ans);
}
cout << ans << endl;
return 0;
}
