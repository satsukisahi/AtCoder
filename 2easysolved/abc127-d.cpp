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
ll n,m;
cin >> n>>m;
ll a[n] = {};
rep(i, n)
{
    cin >> a[i];
}
pair<ll, ll> p[m];
rep(i,m){
    ll aa,bb;
    cin >> aa>>bb;
    p[i].first=(-1)*bb;
    p[i].second=aa;
}
sort(p,p+m);
ll sum=0;
vector<ll> v;
rep(i,m){
    if(sum+p[i].second<n){
        rep(j,p[i].second){
            v.push_back((-1)*p[i].first);
        }
        sum+=p[i].second;
        }
    else{
        rep(j,n-sum){
            v.push_back((-1)*p[i].first);
        }
        break;
    }
}
rep(i,n){
    v.push_back(a[i]);
}
sort(v.rbegin(), v.rend());
rep(i,n){
    ans+=v[i];
}
cout << ans << endl;
return 0;
}