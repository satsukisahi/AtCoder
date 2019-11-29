#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep1(i, n) for (ll i = 1; i < (ll)(n); i++)
const ll mo = 1000000007;
const ll INF = 1LL << 60; //MAX 9223372036854775807
ll ans = 0;

int main()
{
ll n,m;
cin >> n>>m;
ll t[n] = {};
rep(i, m){
    cin >> t[i];
}
ll co=0;
ll dp[n+1]={};
//初期
dp[0]=1;
if(t[0]==1){
  co++;
}
else{
  dp[1]=1;
}

//loop
for(ll i=2;i<=n;i++){
  if(i==t[co]){
    co++;
    continue;
  }
  dp[i]=dp[i-1]+dp[i-2];
  dp[i]%=mo;
}
cout << dp[n] << endl;
return 0;
}