#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
ll ans = 0;
const ll mo = 1000000007;
auto mod = [](ll modx) {modx%=mo;modx+=mo;modx%=mo;return modx; };
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
auto modmul = [](auto... modx) {
  ll res = 1;
  for (auto modx_ : {modx...})
  {
    res *= modx_;
    res %= mo;
    res += mo;
    res %= mo;
  }
  return res;
};
int main()
{
ll n , m ;
cin >> n >> m ;
COMinit();
vector<ll> fac = factorial(510000);
rep(i,n+1)ans=mod(ans+(i%2?-1:1)*modmul(COM(n,i),COM(m,i),fac[i],COM(m-i,n-i),fac[n-i],COM(m-i,n-i),fac[n-i]));
cout << ans << endl;
return 0;
}