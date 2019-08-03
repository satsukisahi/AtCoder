#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
ll ans = 0;
const ll mo = 1000000007;
ll dp[100][3]={};
int main()
{
ll n ;
cin >> n ;
dp[0][0]=1;
ll keta=64-__builtin_clzll(n);
rep(i,keta){
  if((n>>(keta-1-i)) & 1LL){
    dp[i+1][0]+=dp[i][0];
    dp[i+1][1]+=dp[i][0];
    dp[i+1][1]+=dp[i][1];
    dp[i+1][2]+=2*dp[i][1];
  }
  else{
    dp[i+1][0]+=dp[i][0];
    dp[i+1][0]+=dp[i][1];
    dp[i+1][1]+=dp[i][1];
    dp[i+1][2]+=dp[i][1];
  }
  dp[i+1][2]+=3*dp[i][2];
  rep(j,3)dp[i+1][j]%=mo;
}

cout << (dp[keta][0]+dp[keta][1]+dp[keta][2])%mo << endl;
return 0;
}
