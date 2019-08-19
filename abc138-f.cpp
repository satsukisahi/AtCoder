#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
ll ans = 0;
const ll mo = 1000000007;

int main()
{
ll l , r ;
cin >> l >> r ;

rep(i,63){
  ll dp[i+1][2][2]={};
  if((1LL<<i+1)<=l||(1LL<<i)>r)continue;
  if(r>>i==1LL&&l>>i==1LL)dp[i][1][1]=1;
  else if(l>>i==1LL)dp[i][1][0]=1;
  else if(r>>i==1LL)dp[i][0][1]=1;
  else dp[i][0][0]=1;
  rep(j,i){
    ll k=i-j;
    dp[k-1][0][0]+=dp[k][0][0]*3;
    if(r>>(k-1)&1LL && l>>(k-1)&1LL){
      dp[k-1][1][1]+=dp[k][1][1];

      dp[k-1][0][1]+=dp[k][0][1]*2;
      dp[k-1][0][0]+=dp[k][0][1];

      dp[k-1][1][0]+=dp[k][1][0];
    }
    else if(r>>(k-1)&1LL){
      dp[k-1][1][1]+=dp[k][1][1];
      dp[k-1][0][1]+=dp[k][1][1];
      dp[k-1][1][0]+=dp[k][1][1];

      dp[k-1][0][1]+=dp[k][0][1]*2;
      dp[k-1][0][0]+=dp[k][0][1];

      dp[k-1][1][0]+=dp[k][1][0]*2;
      dp[k-1][0][0]+=dp[k][1][0];
    }
    else if(l>>(k-1)&1LL){
      dp[k-1][0][1]+=dp[k][0][1];

      dp[k-1][1][0]+=dp[k][1][0];
    }
    else{
      dp[k-1][1][1]+=dp[k][1][1];

      dp[k-1][0][1]+=dp[k][0][1];

      dp[k-1][1][0]+=dp[k][1][0]*2;
      dp[k-1][0][0]+=dp[k][1][0];
    }
    rep(x,2)rep(y,2)dp[k-1][x][y]%=mo;
  }
  ans+=dp[0][0][0]+dp[0][0][1]+dp[0][1][0]+dp[0][1][1];
  ans%=mo;
}

cout << ans << endl;
return 0;
}
