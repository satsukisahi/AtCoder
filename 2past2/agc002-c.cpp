#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)


int main()
{
ll n , l ;
cin >> n >> l ;
vector<ll> a(n+1);
vector<ll> ans;

rep(i, n){
  cin >> a[i+1];
}
rep(i,n){
  if(a[i]+a[i+1]>=l){
    for(ll j=i;j>0;j--)ans.push_back(j);
    for(ll j=i+1;j<n;j++)ans.push_back(j);
    cout << "Possible" << endl;
    rep(i,n-1){
      cout << ans[n-i-2] << endl;
    }
    return 0;
  }
}
cout << "Impossible" << endl;

return 0;
}
