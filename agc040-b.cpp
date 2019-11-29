#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
ll ans = 0;

int main()
{
ll n ;
cin >> n ;
vector<pair<ll,ll>> v(n);
rep(i, n){
  cin >> v[i].first >> v[i].second;
}

cout << ans << endl;
return 0;
}