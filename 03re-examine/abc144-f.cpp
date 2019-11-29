#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
double ans = 0;

int main()
{
ll n , m ;
cin >> n >> m ;
vector<vector<ll>> g(n);
rep(i, m)
{
  ll a, b;
  cin >> a >> b;
  g[a - 1].push_back(b - 1);
}
vector<double> dp(n);
for (ll i = n-2; i >= 0; i--)
{
  for(auto r:g[i]){
    dp[i]+=(dp[r]+1)/g[i].size();
  }
}
ans=dp[0];
rep(i,n-1){
  ll to;
  double e=0;
  if(g[i].size()==1)continue;
  for(auto r:g[i]){
    if(dp[r]>e){
      e=dp[r];
      to=r;
    }
  }
  vector<double> dpp(n);
  for (ll j = n-2; j >= 0; j--)
  {
    if(i==j)for(auto r:g[j]){
      if(to==r)continue;
      dpp[j]+=(dpp[r]+1)/(g[j].size()-1);
    }
    else for(auto r:g[j]){
      dpp[j]+=(dpp[r]+1)/g[j].size();
    }
  }
  ans=min(ans,dpp[0]);
}
cout<<fixed<<setprecision(12)<<ans<<endl;
return 0;
}