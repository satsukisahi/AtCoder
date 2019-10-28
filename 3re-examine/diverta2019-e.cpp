#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
ll ans = 0;
const ll mo = 1000000007;
ll mypow(ll a, ll b)
{
  ll res = 1;
  a %= mo;
  while (b)
  {
    if (b & 1)
      res = res * a % mo;
    a = a * a % mo;
    b >>= 1;
  }
  return res;
}
int main()
{
ll n ;
cin >> n ;
vector<ll> a(n);
rep(i, n){
  cin >> a[i];
}
ll t=0;
rep(i,n){
  t^=a[i];
}
vector<ll> sum;
sum.push_back(0);
rep(i, n)
{
  sum.push_back(a[i] ^ sum[i]);
}
if(t!=0){
  vector<vector<ll>> dp(n+1, vector<ll>(2,0) );
  dp[0][0]=1;
  rep(i,n){
    dp[i+1][0]+=dp[i][0];
    dp[i+1][1]+=dp[i][1];
    if(sum[i+1]==0)dp[i+1][0]+=dp[i][1];
    if(sum[i+1]==t)dp[i+1][1]+=dp[i][0];
    dp[i+1][0]%=mo;
    dp[i+1][1]%=mo;
  }
  ans=dp[n-1][0];
}
else{
  ll tt=0,num=0;
  rep(i,n){
    tt^=a[i];
    if(tt==0)num++;
  }
  ans=mypow(2,num-1);
  vector<ll> z;
  z.push_back(1);
  rep(i,n){
    if(sum[i+1]==0)z.push_back(z.back()+1);
    else z.push_back(z.back());
  }
  map<ll,ll> pre;
  map<ll,pair<ll,ll>> m;
  rep(i,n){
    if(sum[i+1]==0)continue;
    if(m[sum[i+1]].first==0&&m[sum[i+1]].second==0)m[sum[i+1]]={1,i};
    else {
      pre[sum[i+1]]+=m[sum[i+1]].first;
      m[sum[i+1]].first+=(z[i]-z[m[sum[i+1]].second])*pre[sum[i+1]];
      m[sum[i+1]].first%=mo;
      m[sum[i+1]].second=i;
    }
  }
  for (auto i = m.begin(); i != m.end(); ++i) {
    ans+=i->second.first;
    ans%=mo;
  }
  for (auto i = pre.begin(); i != pre.end(); ++i) {
    ans+=i->second;
    ans%=mo;
  }
}
cout << ans%mo << endl;
return 0;
}