#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
ll ans = 0;
const ll mo = 1000000007;
auto mod = [](ll modx) {modx%=mo;modx+=mo;modx%=mo;return modx; };
const ll MAX = 2000100;
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
ll r , c , t , v ;
cin >> r >> c >> t >> v ;
COMinit();
ans+=COM(t+1+v+1,v+1)-1;
ans-=COM(r+v+1,v+1)-1;
ans-=COM(t+1+c,c)-1;
ans+=COM(r+c,c)-1;
cout << mod(ans) << endl;
return 0;
}