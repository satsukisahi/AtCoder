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
if(a[0]!=0){
  cout << -1 << endl;
  return 0;
}
bool tik=0;
rep(i,n-1){
  if(a[n-i-2]+2<=a[n-i-1]){
    cout << -1 << endl;
    return 0;
  }
  else{
    if(!tik)ans+=a[n-i-1];
    if(a[n-i-2]+1==a[n-i-1])tik=1;
    else tik=0;
  }
}
cout << ans << endl;
return 0;
}