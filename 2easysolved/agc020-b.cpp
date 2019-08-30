#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
ll ans = 0;

int main()
{
ll k ;
cin >> k ;
vector<ll> a(k);
rep(i, k){
  cin >> a[k-1-i];
}
if(a[0]!=2){
cout << -1 << endl;
return 0;
}
ll mx=3,mi=2;
rep(i,k-1){
  if((mi+a[i+1]-1)/a[i+1] *a[i+1]>mx){
    cout << -1 << endl;
    return 0;
  }
  mi=(mi+a[i+1]-1)/a[i+1] *a[i+1];
  mx=mx/a[i+1] *a[i+1]+a[i+1]-1;
}

cout << mi << " " << mx << endl;
return 0;
}
