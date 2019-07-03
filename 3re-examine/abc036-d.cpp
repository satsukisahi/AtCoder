#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
const ll mo = 1000000007;
const ll INF = 1LL << 60; //MAX 9223372036854775807
vector<ll> G[100000];
bool v[100000]={};

pair<ll,ll> dfs(ll p){
    v[p]=1;
    pair<ll,ll> pa;
    pair<ll,ll> src;
    ll b=1,w=1;
    rep(i,G[p].size()){
        if(v[G[p][i]]==1)continue;
        src=dfs(G[p][i]);
        b*=src.second;
        b%=mo;
        w*=(src.first+src.second)%mo;
        w%=mo;
    }
    pa.first=b;
    pa.second=w;
    //cout << p<<" "<<b<<" "<<w << endl;
    return pa;
}

int main()
{
ll n;
cin >> n;

rep(i, n-1)
{
    ll a,b;
    cin >> a>>b;
    G[a-1].push_back(b-1);
    G[b-1].push_back(a-1);
}
pair<ll,ll> ans;
ans=dfs(0);

cout << (ans.first+ans.second)%mo << endl;
return 0;
}
