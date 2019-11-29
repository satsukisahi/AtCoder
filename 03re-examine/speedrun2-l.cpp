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
    ll aa,bb;
    cin >> aa>>bb;
    a[i]=max(aa,bb);
    b[i]=min(aa,bb);
}
pair<ll, ll> p[n];
rep(i,n){
    p[i]=make_pair(a[i],-b[i] );
}
sort(p,p+n);
vector<ll> v(n, INF);
rep(i,n){
    auto itr = lower_bound(v.begin(),v.end(), -p[i].second);
    v[itr - v.begin()]=-p[i].second;
    if(ans<itr - v.begin())ans=itr - v.begin();
}

/* 
 */

cout << ans +1<< endl;
return 0;
}