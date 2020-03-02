#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
ll ans = 0;
const ll mo = 1000000007;
auto mod = [](ll modx) {modx%=mo;modx+=mo;modx%=mo;return modx; };
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
const ll MAX = 510000;
const ll MOD = 1000000007;
long long fac[MAX], finv[MAX], inv[MAX];
void COMinit()
{
  fac[0] = fac[1] = 1;
  finv[0] = finv[1] = 1;
  inv[1] = 1;
  for (ll i = 2; i < MAX; i++)
  {
    fac[i] = fac[i - 1] * i % MOD;
    inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
    finv[i] = finv[i - 1] * inv[i] % MOD;
  }
}
long long COM(ll n, ll k)
{
  if (n < k)
    return 0;
  if (n < 0 || k < 0)
    return 0;
  return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}
int main()
{
ll n ;
cin >> n ;
vector<ll> c(n);
ll summ=0;
rep(i, n){
  cin >> c[i];
}
sort(c.begin(),c.end());
vector<ll> v;
v.push_back(1);
rep(i,3*n){
  v.push_back(mod(v[i]*2));
}
vector<ll> sum;
sum.push_back(0);
rep(i,3*n)
{
  sum.push_back(v[i] + sum[i]);
}
COMinit();
rep(i,n){
  ans=mod(ans+mod(v[i]*c[i])*mod(v[n-1-i]+mod(v[n-1-i]*(n-1-i))*mypow(2,mo-2)));
}
ans=mod(ans*v[n]);
cout << ans << endl;
return 0;
}