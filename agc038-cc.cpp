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
  ll n;
  cin >> n;
  vector<ll> a(n);
  ll maxv = 1;
  rep(i, n)
  {
    cin >> a[i];
    if (maxv < a[i])
      maxv = a[i];
  }
  vector<ll> r(maxv + 1);
  rep(i, n) r[a[i]]++;

  auto mod = [](ll modx) {modx%=mo;modx+=mo;modx%=mo;return modx; };
  vector<ll> v(maxv + 1);
  rep(i, maxv) v[i + 1] = mypow(i + 1, mo - 2);
  for (ll i = 1; i <= maxv; i++)
  {
    for (ll j = i * 2; j <= maxv; j += i)
    {
      v[j] = mod(v[j] - v[i]);
    }
  }

  vector<ll> sum(maxv + 1);
  vector<ll> sum2(maxv + 1);
  for (ll i = 1; i <= maxv; i++)
  {
    for (ll j = i; j <= maxv; j += i)
    {
      sum[i] = mod(sum[i] + r[j] * j);
      sum2[i] = mod(sum2[i] + r[j] * mod(j * j));
    }
  }
  rep(i, maxv) ans = mod(ans + mod(v[i + 1] * (mod(sum[i + 1] * sum[i + 1]) - sum2[i + 1])) * mypow(2, mo - 2));
  cout << ans << endl;
  return 0;
}
