#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)

struct UnionFind
{
    vector<ll> data;
    UnionFind(ll size) : data(size, -1) {}
    bool unionSet(ll x, ll y)
    {
        x = root(x);
        y = root(y);
        if (x != y)
        {
            if (data[y] < data[x])
                swap(x, y);
            data[x] += data[y];
            data[y] = x;
        }
        return x != y;
    }
    bool findSet(ll x, ll y)
    {
        return root(x) == root(y);
    }
    ll root(ll x)
    {
        return data[x] < 0 ? x : data[x] = root(data[x]);
    }
    ll size(ll x)
    {
        return -data[root(x)];
    }
};
int main()
{
ll n,m;
cin >> n>>m;
if(m%2){
    cout << -1 << endl;
    return 0;
}
UnionFind arr(n);
set<ll> G[n];
vector<vector<ll>> g(n);
bool see[n]={};
rep(i, m)
{
    ll a,b;
    cin >> a>>b;
    G[a-1].insert(b-1);
    if(!arr.findSet(a-1,b-1)){
        G[b-1].insert(a-1);
        arr.unionSet(a-1,b-1);
        g[a-1].push_back(b-1);
        g[b-1].push_back(a-1); 
    }
    else cout << a << " " << b << endl;
}
vector<ll> ar;
ar.push_back(0);
see[0]=1;
ll par[n]={};
rep(i,n-1){
    rep(j,g[ar[i]].size()){
        if(!see[g[ar[i]][j]]){
            ar.push_back(g[ar[i]][j]);
            see[g[ar[i]][j]]=1;
            par[g[ar[i]][j]]=ar[i];
        }
    }
}
rep(i,n-1){
    if(G[ar[n-i-1]].size()%2==0){
        cout << ar[n-i-1]+1 << " " << par[ar[n-i-1]]+1 << endl;
        G[par[ar[n-i-1]]].erase(ar[n-i-1]);
    }
    else{
        cout << par[ar[n-i-1]]+1 << " " << ar[n-i-1]+1 << endl;
    }
}


return 0;
}
