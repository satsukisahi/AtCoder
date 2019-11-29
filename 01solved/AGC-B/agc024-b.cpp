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
rep(i, n){
  cin >> p[i];
}
vector<ll> v(n+2);
rep(i,n){
    v[p[i]+1]=v[p[i]]+1;
}
ans=n-*max_element(v.begin(),v.end());
cout << ans << endl;
return 0;
}
