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
rep(i,n-1){
  if(a[i]%2&&a[i+1]>0){
    ans++;
    a[i+1]--;
  }
  ans+=a[i]/2;
}
ans+=a[n-1]/2;
cout << ans << endl;
return 0;
}