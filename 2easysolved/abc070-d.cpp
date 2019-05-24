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
vector<pair<ll,ll> > G[n+1];

rep(i, n-1)
{
    ll a,b,c;
    cin >> a>>b>>c;
    G[a].push_back(pair<ll,ll>(b, c));
    G[b].push_back(pair<ll,ll>(a, c));
}
ll cost[n+1];
rep(i,n+1){
    cost[i]=INF;
}
ll q,k;
cin >> q>>k;
queue<ll> qq;
qq.push(k);
cost[k]=0;

while(!qq.empty()){
    ll p = qq.front();
    qq.pop();
    rep(i,G[p].size()){
        if(cost[G[p][i].first]==INF){
            cost[G[p][i].first]=G[p][i].second+cost[p];
            qq.push(G[p][i].first);
        }
    }
}
rep(i,q){
    ll x,y;
    cin >> x>>y;
    cout << cost[x]+cost[y] << endl;
}
return 0;
}
