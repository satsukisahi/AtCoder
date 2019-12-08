#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
ll ans = 0;
const ll mo = 1000000007;

int main()
{
ll n ;
cin >> n ;
vector<ll> v(n);
rep(i, n){
  cin >> v[i];
}
rep(j,60){
  ll a=0,b=0;
  rep(i,n){
    if(((v[i])>>j)&1LL)a++;
    else b++;
  }
  ll c=a*b;
  c%=mo;
  ll d=(1LL<<j)%mo;
  ans+=(c*d);
  ans%=mo;
}
cout << ans << endl;
return 0;
}