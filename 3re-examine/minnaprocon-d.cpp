#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)

int main()
{
ll n ;
cin >> n ;
vector<ll> a(n);
rep(i, n){
  cin >> a[i];
}
vector<vector<ll>> dp(n+1, vector<ll>(5,0) );
rep(i,n){
  dp[i+1][0]=dp[i][0]+a[i];
  ll r1=0;
  if(a[i]==0)r1=2;
  else r1=a[i]%2;
  dp[i+1][1]=min(dp[i][1]+r1,dp[i][0]+r1);
  ll r2=(a[i]+1)%2;
  dp[i+1][2]=min({dp[i][0]+r2,dp[i][1]+r2,dp[i][2]+r2});
  dp[i+1][3]=min({dp[i][0]+r1,dp[i][1]+r1,dp[i][2]+r1,dp[i][3]+r1});
  dp[i+1][4]=min({dp[i][0]+a[i],dp[i][1]+a[i],dp[i][2]+a[i],dp[i][3]+a[i],dp[i][4]+a[i]});
}
cout << *min_element(dp[n].begin(),dp[n].end()) << endl;
return 0;
}