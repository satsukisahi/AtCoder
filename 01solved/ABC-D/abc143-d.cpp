#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
ll ans = 0;

int main()
{
ll n ;
cin >> n ;
vector<ll> l(n);
rep(i, n){
  cin >> l[i];
}
vector<ll> a(2010);
vector<ll> sum(2010);
rep(i,n){
  a[l[i]]++;
}
rep(i,a.size()-1){
  sum[i+1]=sum[i]+a[i+1];
}
for (ll i = 0; i < n-1; i++)
{
  for (ll j = i+1; j < n; j++)
  {
    ll a=l[i];
    ll b=l[j];
    if(b>a)swap(a,b);
    ans+=sum[a+b-1]-sum[a-b];
    if(a-b<a)ans--;
    if(a-b<b)ans--;
  }
}


cout << ans/3 << endl;
return 0;
}