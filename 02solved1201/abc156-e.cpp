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
int main()
{
ll n , k ;
cin >> n >> k ;
COMinit();
if(n<k+1)k=n-1;
ans=COM(2*n-1,n-1);
rep(i,n-k-1){
  ll an=COM(n,i+1);
  an=mod(an*COM(n-1,i));
  ans=mod(ans-an);
}
cout << ans << endl;
return 0;
}