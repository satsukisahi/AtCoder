#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
const ll mo = 1000000007;
const ll INF = 1LL << 59; //MAX 9223372036854775807
ll ans = 0;
ll w,h,n;
ll x[31],y[31];
map<vector<ll>,ll> m{};

ll dfs(ll l,ll r,ll t,ll b){
    if(r<l||b<t)return 0;
    vector<ll> v={l,r,t,b};
    if(m.find(v)!=m.end())return m[v];

    m[v]=0;
    rep(i,n){
        if(l <= x[i] && x[i] <= r && t <= y[i] && y[i] <= b){
            m[v]=max(m[v],r-l+b-t+1+
            dfs(l,x[i]-1,t,y[i]-1)+
            dfs(x[i]+1,r,t,y[i]-1)+
            dfs(l,x[i]-1,y[i]+1,b)+
            dfs(x[i]+1,r,y[i]+1,b)
            );
        }
    }
    return m[v];
}

int main()
{
cin >>w>>h>> n;

rep(i, n){
    cin >> x[i]>>y[i];
}

cout << dfs(1,w,1,h) << endl;
return 0;
}
