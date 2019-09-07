#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
ll ans = 0;

int main()
{
ll n ;
cin >> n ;
vector<ll> p(n);
vector<ll> ind(n+1);
rep(i, n){
  cin >> p[i];
  ind[p[i]]=i;
}
vector<ll> s;
s.push_back(0);
rep(i,n){
  s.push_back(p[i]+s[i]);
}
ll mx;


cout << ans << endl;
return 0;
}
