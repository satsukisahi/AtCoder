#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
ll ans = 0;
const ll INF = 1LL << 60; //MAX 9223372036854775807

int main()
{
ll h , n ;
cin >> h >> n ;
vector<ll> a(n);
vector<ll> b(n);
rep(i, n){
  cin >> a[i] >> b[i];
}
vector<ll> dp(h+1,INF);
dp[0]=0;
rep(i,n){
  rep(j,h+1){
    if(j-a[i]<0)dp[j]=min(dp[j],b[i]);
    else dp[j]=min(dp[j],b[i]+dp[j-a[i]]);
  }
}

cout << dp[h] << endl;
return 0;
}