#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
ll ans = 1;
const ll mo = 1000000007;

int main()
{
ll n , x , y , z ;
cin >> n >> x >> y >> z ;
vector<vector<ll>> dp(n+1, vector<ll>(1LL<<(x+y+z-1),0) );
dp[0][0]=1;
rep(i,n)rep(j,dp[i].size()){
  for(ll k=1;k<=10;k++){
    ll te=(j<<k)|(1LL<<(k-1));
    if(!(((te>>(x+y+z-1))&1LL)&&((te>>(x+y-1))&1LL)&&((te>>(x-1))&1LL))){
      dp[i+1][te&((1LL<<(x+y+z-1))-1LL)]+=dp[i][j];
      dp[i+1][te&((1LL<<(x+y+z-1))-1LL)]%=mo;
    }
  }
}
rep(i,n){
  ans*=10;
  ans%=mo;
}
for(auto i:dp[n]){
  ans-=i;
  ans%=mo;
}
cout << (ans+mo)%mo << endl;
return 0;
}