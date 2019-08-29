#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
ll ans = 0;
const ll mo = 998244353;
vector<ll> factorial(ll n){
  vector<ll> fac;
  fac.push_back(1);
  for(ll i = 1; i < 100000; i++){
      fac.push_back((fac[i-1]*i)%mo);
  }
  return fac;
}
ll mypow(ll a, ll b){
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
ll k , n ;
cin >> k >> n ;
auto mod = [](ll modx){modx%=mo;modx+=mo;modx%=mo;return modx;};
vector<ll> fac=factorial(k+n);
ll a=fac[k-1]*fac[n];
a%=mo;
ll al=fac[k+n-1]*mypow(a,mo-2);
al%=mo;

ll ab=fac[k-2]*fac[n];
ab%=mo;
ll alb=fac[k+n-2]*mypow(ab,mo-2);
alb%=mo;

ll ac=fac[k-1]*fac[n-2];
ac%=mo;
ll alc=fac[k+n-3]*mypow(ac,mo-2);
alc%=mo;

cout << alb << " "<<alc << endl;
return 0;
}
