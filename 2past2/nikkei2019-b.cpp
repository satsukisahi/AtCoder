#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
ll ans = 0;
const ll mo = 998244353;
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
vector<ll> d(n);
rep(i, n){
  cin >> d[i];
}
vector<ll> a(n+10);
rep(i,n){
  a[d[i]]++;
}
if(d[0]!=0){
cout << ans << endl;
return 0;
}
if(a[0]!=1){
cout << ans << endl;
return 0;
}
ll en=0;
rep(i,n){
  if(a[i]==0&&en==0)en++;
  else if(a[i]!=0&&en==1){
    cout << ans << endl;
    return 0;
  }
}
ans=1;
rep(i,n-1){
  if(a[i+1]==0)break;
  ans*=mypow(a[i],a[i+1]);
  ans%=mo;
}

cout << ans << endl;
return 0;
}
