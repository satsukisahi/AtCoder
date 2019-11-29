#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
ll ans = 0;

int main()
{
ll a , b , x ;
cin >> a >> b >> x ;
ll r=1;
rep(i,19){
  r*=10;
  ll xx=x-b*(i+1);
  ll t=xx/a;
  if(t>=r)t=r-1;
  ans=max(ans,t);
}
if(ans>1000000000)ans=1000000000;
cout << ans << endl;
return 0;
}