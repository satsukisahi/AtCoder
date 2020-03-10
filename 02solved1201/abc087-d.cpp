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
ll n , m ;
cin >> n >> m ;
vector<vector<edge>> g(n);
rep(i, m)
{
  ll a, b, c;
  cin >> a >> b >> c;
  g[a - 1].emplace_back(b - 1, c);
  g[b - 1].emplace_back(a - 1, -c); 
}
vector<ll> dist(n,INF);
vector<ll> see(n);
queue<ll> q;
rep(i,n){
  if(see[i])continue;
  dist[i]=0;
  see[i]=1;
  q.push(i);
  while(!q.empty()){
    auto p=q.front();
    q.pop();
    for(auto r:g[p]){
      if(dist[r.to]==INF)dist[r.to]=dist[p]+r.cost;
      else if (dist[r.to] != dist[p] + r.cost)
      {
        cout << "No" << endl;
        return 0;
      }
      if(see[r.to]!=0)continue;
      see[r.to]=1;
      q.push(r.to);
    }
  }
}
cout << "Yes" << endl;
return 0;
}