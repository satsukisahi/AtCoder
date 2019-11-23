#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
ll ans = 0;

int main()
{
ll n ;
cin >> n ;
vector<ll> a(n);
rep(i, n){
  cin >> a[i];
}
ll mx=0;
rep(i,n){
  if(a[i]>mx+1){
    ans+=(a[i]-1)/(mx+1);
    if(mx==0)mx=1;
  }
  else if(a[i]>mx)mx=a[i];
}
cout << ans << endl;
return 0;
}