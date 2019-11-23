#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
ll ans = 1;
const ll mo = 1000000007;
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
int main()
{
ll n ;
cin >> n ;
vector<ll> x(n);
rep(i, n){
  cin >> x[i];
}
vector<ll> fac = factorial(100000);
ll a=1,cnt=0;
rep(i,n){
  if(x[i]<a){
    ans*=i+1-cnt;
    ans%=mo;
    cnt++;
  }
  else{
    a+=2;
  }
}
ans*=fac[n-cnt];
ans%=mo;
cout << ans << endl;
return 0;
}