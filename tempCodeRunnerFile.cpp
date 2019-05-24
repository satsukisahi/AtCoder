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
vector<pair<ll,ll> > G[n+1];
rep(i, m)
{
    ll a,b,c;
    cin >> a>>b>>c;
    G[a].push_back(pair<ll,ll>(b, c));
}
ll cost[n+1];
rep(i,n+1){
    cost[i]=INF;
}

queue<ll> qq;
qq.push(1);
cost[1]=0;
ll cou=0;
while(!qq.empty()){
    ll p = qq.front();
    qq.pop();
    rep(i,G[p].size()){
        if(cost[G[p][i].first]==INF){
            cost[G[p][i].first]=G[p][i].second+cost[p];
            qq.push(G[p][i].first);
        }
        else{
            cost[G[p][i].first]=max(G[p][i].second+cost[p],cost[G[p][i].first]);
            qq.push(G[p][i].first);
            cou++;
            if(2000<cou){
                cout << "inf" << endl;
                return 0;
            }
        }
    }
}
cout << cost[n] << endl;
return 0;
}