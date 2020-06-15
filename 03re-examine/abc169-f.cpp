#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
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
vector<vector<ll>> dp(n+1, vector<ll>(s+1,0) );
dp[0][0]=1;
rep(i,n)rep(j,s+1){
  dp[i+1][j]+=mod(dp[i][j]*2);
  if(j+a[i]<=s)dp[i+1][j+a[i]]+=mod(dp[i][j]);
}
cout << mod(dp[n][s]) << endl;
return 0;
}