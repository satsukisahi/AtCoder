#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
ll ans = 0;
const ll mo = 998244353;
auto mod = [](ll modx) {modx%=mo;modx+=mo;modx%=mo;return modx; };

int main()
{
ll n , s ;
cin >> n >> s ;
vector<ll> a(n);
rep(i, n){
  cin >> a[i];
}
ll dp[n+1][s+1][3]={};
dp[0][0][0]=1;
dp[0][0][1]=1;
rep(i,n)rep(j,s+1)rep(k,3){
  (dp[i+1][j][k]+=dp[i][j][k] )%=mo;
  if(k!=2){
    (dp[i+1][j][k+1]+=dp[i][j][k] )%=mo;
  }
  if(j+a[i]<=s&&k==1){
    (dp[i+1][j+a[i]][k]+=dp[i][j][k] )%=mo;
    (dp[i+1][j+a[i]][k+1]+=dp[i][j][k] )%=mo;
  }
}
cout << dp[n][s][2] << endl;
return 0;
}
