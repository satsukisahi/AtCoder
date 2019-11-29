#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
ll ans = 0;

int main()
{
ll n , k ;
cin >> n >> k ;
vector<ll> a(n);
rep(i, n){
  cin >> a[i];
  a[i]%=k;
}
vector<ll> sum;
sum.push_back(0);
rep(i, n)
{
  sum.push_back(a[i] + sum[i]);
}
rep(i,n+1){
  sum[i]-=i;
}
rep(i,n+1){
  sum[i]%=k;
  sum[i]+=k;
  sum[i]%=k;
}
map<ll,ll> m;
rep(i,k-1){
  if(i>=n+1)break;
  m[sum[i]]++;
  ans+=m[sum[i]]-1;
}
for (ll i = k-1; i < n+1; i++)
{
  m[sum[i]]++;
  ans+=m[sum[i]]-1;
  m[sum[i-k+1]]--;
}
cout << ans << endl;
return 0;
}