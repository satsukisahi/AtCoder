#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
const ll mo = 1000000007;
const ll INF = 1LL << 59; //MAX 9223372036854775807
ll ans = 0;

int main()
{
ll n,m,t;
cin >> n>>m>>t;
ll a[n] = {};
rep(i, n){
    cin >> a[i];
}
vector<pair<ll,ll> > G[n];
vector<pair<ll,ll> > F[n];
rep(i,m){
    ll a1,a2,a3;
    cin >> a1>>a2>>a3;
    G[a1-1].push_back(pair<ll,ll>(a2-1, a3));
    F[a2-1].push_back(pair<ll,ll>(a1-1, a3));
}

vector<ll> g(n, INF); 
vector<ll> f(n, INF); 
priority_queue< pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>> > q;
priority_queue< pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>> > qq;

g[0]=0;f[0]=0;
q.push({0,0});
while (!q.empty()){
    pair<ll,ll> p=q.top();q.pop();
    ll v=p.second;
    if(g[v]<p.first)continue;
    rep(i,G[v].size()){
        pair<ll,ll> e=G[v][i];
        if(g[e.first]>g[v]+e.second){
            g[e.first]=g[v]+e.second;
            q.push({g[e.first],e.first});
        }
    }
}
qq.push({0,0});
while (!qq.empty()){
    pair<ll,ll> p=qq.top();qq.pop();
    ll v=p.second;
    if(f[v]<p.first)continue;
    rep(i,F[v].size()){
        pair<ll,ll> e=F[v][i];
        if(f[e.first]>f[v]+e.second){
            f[e.first]=f[v]+e.second;
            qq.push({f[e.first],e.first});
        }
    }
}
rep(i,n){
    if(g[i]==INF||f[i]==INF)continue;
    ans=max(ans,(t-g[i]-f[i])*a[i]);
}

/* for (int i = 0; i < n; ++i) {
    cout << g[i] << " ";
}cout  << endl;
for (int i = 0; i < n; ++i) {
    cout << f[i] << " ";
}cout  << endl; */

cout << ans << endl;
return 0;
}
