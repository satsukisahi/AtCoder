#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
const ll mo = 1000000007;
const ll INF = 1LL << 59; //MAX 9223372036854775807
ll dp[51][51][2510]={};

int main()
{
ll n , k;
cin >> n >> k ;
if(k%2==1){
  cout << 0 << endl;
  return 0;
}
k/=2;
dp[0][0][0]=1;
rep(i,n)rep(j,n)rep(l,k+1){
  if(l-j<0)continue;
  dp[i+1][j][l]+=dp[i][j][l-j]*(1+2*j)+dp[i][j+1][l-j]*(j+1)*(j+1);
  if(j>0)dp[i+1][j][l]+=dp[i][j-1][l-j];
  dp[i+1][j][l]%=mo;
}

cout << dp[n][0][k] << endl;
return 0;
}
