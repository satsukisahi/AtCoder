#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
ll ans = 0;
const ll mo = 1000000007;
auto mod = [](ll modx) {modx%=mo;modx+=mo;modx%=mo;return modx; };
map<ll, ll> primefactor(ll n)
{
  map<ll, ll> div;
  ll nn = n;
  for (ll i = 2; i * i <= nn; i++)
  {
    if (n % i == 0)
    {
      div[i]++;
      n /= i;
      i--;
    }
  }
  if (n != 1)
    div[n]++;
  return div;
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
map<ll,ll> m;
rep(i, n){
  cin >> a[i];
  auto r=primefactor(a[i]);
  for (auto i = r.begin(); i != r.end(); ++i)
  {
    if(m[i->first]<i->second)m[i->first]=i->second;
  }
}
ll k=1;
for (auto i = m.begin(); i != m.end(); ++i)
{
  rep(j,i->second)k=mod(k*i->first);
}
rep(i,n){
  ans=mod(ans+k*mypow(a[i],mo-2));
}
cout << ans << endl;
return 0;
}