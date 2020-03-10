#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
const ll INF = 1LL << 60;
ll ans = 0;

int main()
{
ll n , t ;
cin >> n >> t ;
vector<pair<ll,ll>> v;
vector<pair<double,ll>> k;
vector<ll> z;
rep(i,n){
  ll a , b ;
  cin >> a >> b ;
  v.emplace_back(a,b);
  if(a!=0)k.emplace_back((double)a/(b+1),i);
  else z.push_back(b);
}
sort(k.begin(),k.end());
reverse(k.begin(),k.end());
sort(z.begin(),z.end());
vector<vector<ll>> dp(30, vector<ll>(k.size()+1,INF) );
dp[0][0]=0;
rep(i,k.size()){
  rep(j,29){
    if(dp[j][i]==INF)continue;
    dp[j][i+1]=min(dp[j][i+1],dp[j][i]);
    if(dp[j][i+1]>t)dp[j][i+1]=t+1;
    dp[j+1][i+1]=min(dp[j+1][i+1],1+v[k[i].second].first*(1+dp[j][i])+v[k[i].second].second+dp[j][i]);
    if(dp[j+1][i+1]>t)dp[j+1][i+1]=t+1;
  }
}
rep(i,30){
  if(dp[i][k.size()]>t)continue;
  ll an=i;
  for(auto r:z){
    if(dp[i][k.size()]+1+r<=t){
      dp[i][k.size()]+=1+r;
      an++;
    }
    else break;
  }
  ans=max(ans,an);
}
cout << ans << endl;

return 0;
}