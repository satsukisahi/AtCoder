#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
ll ans = 0;
const ll mo = 1000000007;
auto mod = [](ll modx) {modx%=mo;modx+=mo;modx%=mo;return modx; };
vector<ll> factorial(ll n)
{
  vector<ll> fac;
  fac.push_back(1);
  for (ll i = 1; i < n + 10; i++)
  {
    fac.push_back((fac[i - 1] * i) % mo);
  }
  return fac;
}
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
vector<ll> fac = factorial(100000);
ll sum=fac[n-1];
rep(i,n-1){
  ans=mod(ans+(a[i+1]-a[i])*sum);
  sum=mod(sum+fac[n-1]*mypow(i+2,mo-2));
}
cout << ans << endl;
return 0;
}