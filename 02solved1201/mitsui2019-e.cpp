#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
ll ans = 1;
const ll mo = 1000000007;

int main()
{
ll n ;
cin >> n ;
vector<ll> a(n);
rep(i, n){
  cin >> a[i];
}
vector<ll> v(3);
rep(i,n){
  ll cnt=0;
  rep(j,3)if(v[j]==a[i])cnt++;
  if(cnt==0){
    cout << 0 << endl;
    return 0;
  }
  ans*=cnt;
  ans%=mo;
  rep(j,3)if(v[j]==a[i]){
    v[j]++;
    break;
    }
}

cout << ans << endl;
return 0;
}