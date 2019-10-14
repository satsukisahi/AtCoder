#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
void dfs(ll x,ll d,ll c, vector<vector<ll>> &g, vector<ll> &ans,vector<ll> &mx)
{
  if(mx[x]>=d)return;
  mx[x]=d;
  if(ans[x]==0)ans[x]=c;
  for (auto p : g[x])
  {
    dfs(p,d-1,c,g,ans,mx);
  }
  return;
}
int main()
{
ll n,m;
cin >> n >> m ;
vector<vector<ll>> g(n);
vector<ll> ans(n,0);
vector<ll> mx(n,-1);
rep(i, m)
{
    ll a,b;
    cin >> a>>b;
    g[a-1].push_back(b-1);
    g[b-1].push_back(a-1); //無向辺
}
ll q ;
cin >> q ;
vector<vector<ll>> que(q, vector<ll>(3,0) );
rep(i,q){
  cin >> que[q-i-1][0] >> que[q-i-1][1] >> que[q-i-1][2] ;
}
rep(i,q){
  dfs(que[i][0]-1,que[i][1],que[i][2],g,ans,mx);
}
for(auto an:ans)cout << an << endl;
return 0;
}