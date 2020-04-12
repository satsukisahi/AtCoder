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
int main()
{
ll n , k ;
cin >> n >> k ;
vector<ll> v(k+1,0);
for (ll i = 1; i < k+1; i++)
{
  for (ll j = i+i; j < k+1; j+=i)
  {
    v[j]+=i;
  }
  ans=mod(ans+i*mypow(k/i,n));
  ans=mod(ans-(v[i]*mypow(k/i,n)));
  for (ll j = i+i; j < k+1; j+=i)
  {
    v[j]-=v[i];
  }
}

cout << ans << endl;
return 0;
}