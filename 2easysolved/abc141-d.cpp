#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
ll ans = 0;

int main()
{
ll n , m ;
cin >> n >> m ;
multiset<ll> a;
rep(i, n){
  ll aa;
  cin >>aa ;
  a.insert(aa);
}
rep(i,m){
  auto t=a.end();
  t--;
  a.erase(t);
  a.insert(*t/2);
}
for(auto r:a){
  ans+=r;
}
cout << ans << endl;
return 0;
}