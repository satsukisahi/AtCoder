#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define repf(i, a, b) for(ll i = (a); i < (b) ; i++ )
const ll mo = 1000000007;
const ll INF = 1LL << 60; //MAX 9223372036854775807
ll ans = 0;

int main()
{
ll n,m;
cin >> n>>m;
ll s[n] = {};
rep(i, n){
    cin >> s[i];
}
ll t[m] = {};
rep(i, m){
    cin >> t[i];
}
ll dp[m+1][n+1]={};

rep(i,m+1){
    dp[i][0]=1;
}
rep(i,n+1){
    dp[0][i]=1;
}
rep(i,m)rep(j,n){
    dp[i+1][j+1]=dp[i][j+1]+dp[i+1][j]-dp[i][j];
    if(s[j]==t[i]){
        dp[i+1][j+1]+=dp[i][j];
        
    }
    if(dp[i+1][j+1]<0)dp[i+1][j+1]+=mo;
    dp[i+1][j+1]%=mo;
}
cout << dp[m][n] << endl;

/* //2次元配列の中身を見る

for (int i = 0; i < m+1; ++i){
for (int j = 0; j < n+1; ++j) {
    cout << dp[i][j] << " ";
}cout  << endl;}
 */
return 0;
}