#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
const ll mo = 1000000007;
const ll INF = 1LL << 59; //MAX 9223372036854775807
ll ans = 0;

int main()
{
ll n,m,p,q,r;
cin >>n>>m>>p>>q>>r;
ll t[r][3] = {};
rep(i, r){
    cin >> t[i][0]>> t[i][1]>> t[i][2];
}
rep(i,1LL<<n){
    ll sum=0;
    if(__builtin_popcountll(i)!=p)continue;
    vector<ll> v(m,0);
    rep(j,r){
        if(i>>(t[j][0]-1)&1LL)v[t[j][1]-1]+=t[j][2];
    }
    sort(v.rbegin(),v.rend());
    rep(j,q){
        sum+=v[j];
    }
    if(sum>ans)ans=sum;
}
cout << ans << endl;
return 0;
}
