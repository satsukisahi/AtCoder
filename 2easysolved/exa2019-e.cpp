#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
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
ll b , w ;
cin >> b >> w ;
vector<vector<ll>> v(b+w, vector<ll>(2,0) );
ll buf=0;
ll half=mypow(2,mo-2);
COMinit();
for (ll i = w; i < b+w; i++)
{
  v[i][0]=(buf*half)%mo+(mypow(mypow(2,i),mo-2)*COM(i,w))%mo;
  v[i][0]%=mo;
  buf=(buf*half)%mo;
  buf+=v[i][0];
  buf%=mo;
}
buf=0;
for (ll i = b; i < b+w; i++)
{
  v[i][1]=(buf*half)%mo+(mypow(mypow(2,i),mo-2)*COM(i,b))%mo;
  v[i][1]%=mo;
  buf=(buf*half)%mo;
  buf+=v[i][1];
  buf%=mo;
}
rep(i,b+w){
  cout << ((half+half*(v[i][0]-v[i][1]))%mo+mo)%mo << endl;
}
return 0;
}