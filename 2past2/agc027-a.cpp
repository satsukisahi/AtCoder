#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
ll ans = 0;

int main()
{
ll n , x ;
cin >> n >> x ;
vector<ll> a(n);
rep(i, n){
  cin >> a[i];
}
sort(a.begin(),a.end());
rep(i,n){
  if(x>=a[i]){
    ans++;
    x-=a[i];
  }
  else x=0;
}
if(x!=0)ans--;
cout << ans << endl;
return 0;
}
