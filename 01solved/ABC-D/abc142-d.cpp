#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
ll ans = 0;
map<ll,ll> primefactor(ll n){
  map<ll,ll> div;
  ll nn=n;
  for (ll i = 2; i*i <= nn; i++)
  {
    if (n % i == 0)
    {
      div[i]++;
      n/=i;
      i--;
    }
  }
  if(n!=1)div[n]++;
  return div;
}
int main()
{
ll a , b ;
cin >> a >> b ;
map<ll,ll> p=primefactor(a);
map<ll,ll> pb=primefactor(b);
for (auto i = p.begin(); i != p.end(); ++i) {
  if(pb[i->first]!=0)ans++;
}
cout << ans+1 << endl;
return 0;
}
