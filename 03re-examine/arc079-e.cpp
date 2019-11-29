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
rep(i,1000000)rep(j,n){
  if(a[j]>=n){
    ll te=a[j]/n;
    a[j]-=n*te;
    ans+=te;
    rep(k,n)if(j!=k)a[k]+=te;
  }
}
cout << ans << endl;
return 0;
}
