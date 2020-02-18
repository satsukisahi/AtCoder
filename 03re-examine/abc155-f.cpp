#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
vector<ll> ans;
struct edge
{
  ll to;
  ll cost;
  edge() {}
  edge(ll to, ll cost) : to(to), cost(cost){};
};
void dfs(ll x, vector<vector<edge>> &g,vector<ll> &kk, vector<bool> &see)
{
  //点xに対する処理
  see[x] = 1;
  for (auto p : g[x])
  {
    if (see[p.to])continue;
    dfs(p.to, g,kk, see);
    if(kk[p.to]==1){
      kk[p.to]=0;
      kk[x]=(kk[x]+1)%2;
      ans.push_back(p.cost);
    }
  }
}
int main()
{
ll n , m ;
cin >> n >> m ;
map<ll,ll> a;
vector<ll> v,k,kk;
rep(i, n){
  ll aa,b;
  cin >> aa >> b;
  a[aa]=b;
}
for (auto i = a.begin(); i != a.end(); ++i) {
  v.push_back(i->second);
  k.push_back(i->first);
}
kk.push_back(v[0]);
rep(i,n-1){
  if(v[i]!=v[i+1])kk.push_back(1);
  else kk.push_back(0);
}
kk.push_back(v[n-1]);

vector<pair<ll,ll>> l(m);
rep(i, m){
  ll r,rr;
  cin >> r >> rr;
  l[i].first=lower_bound(k.begin(), k.end(), r)-k.begin();
  l[i].second=upper_bound(k.begin(), k.end(), rr)-k.begin();
}
vector<vector<edge>> g(n+1);
rep(i, m)
{
  if(l[i].first==l[i].second)continue;
  g[l[i].first].emplace_back(l[i].second,i+1);
  g[l[i].second].emplace_back(l[i].first,i+1); 
}
vector<bool> see(n+1);
rep(i,n+1){
  if(see[i]==0)dfs(i,g,kk,see);
}
for(auto r:kk){
  if(r!=0){
    cout << -1 << endl;
    return 0;
  }
}
sort(ans.begin(),ans.end());
cout << ans.size() << endl;
for(auto r:ans)cout << r << " ";
cout <<  endl;
return 0;
}