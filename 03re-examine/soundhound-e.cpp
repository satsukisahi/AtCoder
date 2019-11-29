#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
ll ans = 0;
const ll INF = 1LL << 60; //MAX 9223372036854775807

struct edge
{
  ll to;
  ll cost;
  edge() {}
  edge(ll to, ll cost) : to(to), cost(cost){};
};
int main()
{
ll n, m;
cin >> n >> m;
vector<vector<edge>> g(n);
rep(i, m)
{
  ll a, b, c;
  cin >> a >> b >> c;
  g[a - 1].emplace_back(b - 1, c);
  g[b - 1].emplace_back(a - 1, c); //無向辺
}
vector<vector<ll>> v(n, vector<ll>(2,INF) );
v[0][0]=0;
queue<pair<ll,bool>> q;
q.push({0,0});
while(!q.empty()){
  auto p=q.front();
  q.pop();
  for(auto r:g[p.first]){
    if(v[r.to][!p.second]==INF){
      v[r.to][!p.second]=r.cost-v[p.first][p.second];
      q.push({r.to,!p.second});
    }
    else if(v[r.to][!p.second]!=r.cost-v[p.first][p.second]){
      cout << 0 << endl;
      return 0;
    }
  }
}
ll mi1=INF,mi2=INF,a=0;
rep(i,n){
  if(v[i][0]!=INF&&v[i][1]!=INF){
    a=1;
    if(abs(v[i][0]-v[i][1])%2){
      cout << 0 << endl;
      return 0;
    }
    if(abs(v[i][0]-v[i][1])/2+min(v[i][0],v[i][1])<=0){
      cout << 0 << endl;
      return 0;
    }
  }
  mi1=min(mi1,v[i][0]);
  mi2=min(mi2,v[i][1]);
}
ans=max(0LL,mi1+mi2-1);
if(a)ans=1;
cout << ans << endl;
return 0;
}