#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
ll ans = 0;
const ll mo = 1000000007;

ll mypow(ll a, ll b){
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
vector<ll> v(n);
rep(i,n){
  v[i]=mypow(i+1,mo-2);
  if(i!=0)v[i]+=v[i-1];
  v[i]%=mo;
}
rep(i,n){
  ans+=(v[i]+v[n-i-1]-1)*a[i];
  ans%=mo;
}
rep(i,n){
  ans*=(i+1);
  ans%=mo;
}
cout << ans << endl;
return 0;
}
