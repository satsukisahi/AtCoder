#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
ll ans = 0;

int main()
{
string n ;
ll k ;
cin >> n >> k ;
ll dp[n.size()][k+1][2]={};
dp[0][0][0]=1;
dp[0][1][1]=1;
dp[0][1][0]=n[0]-'1';
rep(i,n.size())rep(j,k+1){
dp[i+1][j][0]+=dp[i][j][0];
if(n[i+1]=='0')dp[i+1][j][1]+=dp[i][j][1];
else {
  if(j!=k)dp[i+1][j+1][1]+=dp[i][j][1];
  if(j!=k)dp[i+1][j+1][0]+=dp[i][j][1]*(n[i+1]-'1');
  dp[i+1][j][0]+=dp[i][j][1];
}
if(j!=k)dp[i+1][j+1][0]+=dp[i][j][0]*9;
}
cout << dp[n.size()-1][k][0]+dp[n.size()-1][k][1] << endl;
return 0;
}