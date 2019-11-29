#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep1(i, n) for (ll i = 1; i < (ll)(n); i++)
const ll mo = 1000000007;
const ll INF = 1LL << 60; //MAX 9223372036854775807
ll ans = 0;

int main()
{
ll n;
cin >> n;
ll a[n] = {};
ll b[n] = {};
rep(i, n)
{
    cin >> a[i]>>b[i];
}

vector<ll> v;
v.push_back(a[0]);
v.push_back(b[0]);

rep1(i,n){
    ll s=v.size();
    rep(j,s){
        ll k=__gcd(a[i],v[j]),l=__gcd(b[i],v[j]);
        if(max(k,l)%min(k,l)==0)v[j]=max(k,l);
        else{
            v[j]=max(k,l);
            v.push_back(min(k,l));
        }
    }
}
rep(i,v.size()){
    ans=max(v[i],ans);
}
cout << ans << endl;
return 0;
}