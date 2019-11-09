#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
const ll INF = 1LL << 60; //MAX 9223372036854775807

int main()
{
ll n , m ;
cin >> n >> m ;
pair<ll,vector<ll>> p[m];
rep(i,m){
  ll a , b ;
  cin >> a >> b ;
  p[i].first=a;
  rep(j,b){
    ll c ;
    cin >> c ;
    p[i].second.push_back(c);
  }
}
vector<vector<ll>> dp(m+1, vector<ll>(1LL<<n,INF) );
dp[0][0]=0;

rep(i,m){
  ll key=0;
  for(auto aa:p[i].second)key+=(1LL<<(aa-1));
  rep(j,1LL<<n){
    dp[i+1][j]=min(dp[i][j],dp[i+1][j]);//使わない
    dp[i+1][j|key]=min(dp[i][j]+p[i].first,dp[i+1][j|key]);//使う
  }
}
if(dp[m][(1LL<<n)-1]<(1LL << 59))cout << dp[m][(1LL<<n)-1] << endl;
else cout << -1 << endl;
return 0;
}