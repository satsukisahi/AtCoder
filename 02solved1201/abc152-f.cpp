#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
ll ans = 0;
struct edge
{
  ll to;
  ll cost;
  edge() {}
  edge(ll to, ll cost) : to(to), cost(cost){};
};
int main()
{

ll n;
cin >> n;
vector<vector<edge>> g(n);
rep(i, n-1)
{
  ll a, b;
  cin >> a >> b ;
  g[a - 1].emplace_back(b - 1, i);
  g[b - 1].emplace_back(a - 1, i); //無向辺
}
ll m ;
cin >> m ;
vector<ll> v;
rep(i,m){
  ll a, b;
  cin >> a >> b;
  a--;b--;
  vector<pair<ll,ll>> par(n);
  vector<bool> see(n);
  queue<ll> q;
  par[a]={-1,-1};
  see[a]=1;
  q.push(a);
  while(!q.empty()){
    auto p=q.front();
    if(p==b){
      ll vv=0;
      while(par[p].first!=-1){
        vv+=(1LL<<par[p].second);
        p=par[p].first;
      }
      v.push_back(vv);
      break;
    }
    see[p]=1;
    q.pop();
    for(auto r:g[p]){
      if(see[r.to]!=0)continue;
      par[r.to]={p,r.cost};
      q.push(r.to);
    }
  }
}
rep(i,1LL<<m){
  ll k=__builtin_popcountll(i);
  ll a=0;
  rep(j,m){
    if(i>>j & 1LL){
      a|=v[j];
    }
  }
  if(k%2)ans-=1LL<<(n-1-__builtin_popcountll(a));
  else ans+=1LL<<(n-1-__builtin_popcountll(a));
}
cout << ans << endl;
return 0;
}