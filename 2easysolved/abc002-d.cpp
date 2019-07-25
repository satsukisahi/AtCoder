#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
const ll mo = 1000000007;
const ll INF = 1LL << 59; //MAX 9223372036854775807
ll ans = 0;
ll n,m;

ll ch(ll i,set<ll> *G){
    rep(j,n){
        if(i>>j & 1LL ){
            for (ll k = j+1; k < n; k++)
            {
                if(i>>k & 1LL && G[j].find(k)==G[j].end())return 1;
            }
            
        }
    }
    return __builtin_popcountll(i);
}

int main()
{
cin >> n>>m;

set<ll> G[n];
rep(i, m)
{
    ll a,b;
    cin >> a>>b;
    G[a-1].insert(b-1);
    G[b-1].insert(a-1);
}
rep(i,1LL<<n){
    ans=max(ch(i,G),ans);
}
cout << ans << endl;
return 0;
}
