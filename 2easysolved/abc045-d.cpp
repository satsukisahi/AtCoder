#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
const ll mo = 1000000007;
const ll INF = 1LL << 60; //MAX 9223372036854775807
ll ans[10] = {};

int main()
{
ll h,w,n;
cin >> h>>w>>n;
map<pair<ll,ll>,ll> m{};
rep(i, n){
    ll x,y;
    cin >> x>>y;
    rep(j,3)rep(k,3){
        if(x+j-1>1&&x+j-1<h&&y+k-1>1&&y+k-1<w)
        m[{x+j-1,y+k-1}]+=1;
    }
}
ans[0]=(h-2)*(w-2);

for (auto i = m.begin(); i != m.end(); ++i) {
    ans[i->second]++;
    ans[0]--;
}

rep(i,10)cout << ans[i] << endl;
return 0;
}
