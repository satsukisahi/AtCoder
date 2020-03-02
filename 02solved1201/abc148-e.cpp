#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
ll ans = 0;

int main()
{
ll n ;
cin >> n ;
if(n%2){
  cout << 0 << endl;
  return 0;
}
n/=2;
ll a=5;
while(a<=n){
  ans+=n/a;
  a*=5;
}
cout << ans << endl;
return 0;
}