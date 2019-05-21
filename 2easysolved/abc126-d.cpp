#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep1(i, n) for (ll i = 1; i < (ll)(n); i++)
const ll mo = 1000000007;
const ll INF = 1LL << 60; //MAX 9223372036854775807


int main()
{
int ans[100010]={};
queue<ll> q;
ll n;
cin >> n;
vector<pair<ll,ll> > G[n];

ans[0]=1;
rep(i, n-1)
{
    ll a,b,c;
    cin >> a>>b>>c;
    G[a-1].push_back(pair<ll,ll>(b-1, c));
    G[b-1].push_back(pair<ll,ll>(a-1, c));
}
q.push(0);
while(!q.empty()){
    ll aa=q.front();
    //cout << "aa"<<aa+1 << endl;
    q.pop();
    rep(i,G[aa].size()){
        if(ans[G[aa][i].first]>0)continue;
        q.push(G[aa][i].first);
        if(G[aa][i].second%2==0)ans[G[aa][i].first]=ans[aa];
        else ans[G[aa][i].first]=((ans[aa])%2)+1;
    }
}
rep(i,n){
    cout << ans[i] -1<< endl;
}

return 0;
}