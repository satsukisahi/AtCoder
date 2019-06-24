#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define repf(i, a, b) for(ll i = (a); i < (b) ; i++ )
const ll mo = 1000000007;
const ll INF = 1LL << 60; //MAX 9223372036854775807
ll ans = 0;

int main()
{
ll n;
cin >> n;
ll a[n] = {};
rep(i, n){
    cin >> a[i];
}
ll b[n] = {};
rep(i, n){
    cin >> b[i];
}
vector<ll> c(n);
vector<ll> d(n);
rep(i,30){
    rep(j,n){
        c[j]=b[j]&((1LL<<i+1)-1);
        d[j]=a[j]&((1LL<<i+1)-1);
    }
    sort(c.begin(),c.end());
    ll co=0;
    rep(j,n){
        ll k=1LL<<i;
        co+=upper_bound(c.begin(),c.end(), 2*k-1-d[j])-lower_bound(c.begin(),c.end(), k-d[j]);
        co+=upper_bound(c.begin(),c.end(),  4*k-1-d[j])-lower_bound(c.begin(),c.end(), 3*k-d[j]);
    }
    if(co%2)ans+=1LL<<i;
}

cout << ans << endl;
return 0;
}