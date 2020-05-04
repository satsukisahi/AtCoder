#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
const ll INF = 1LL << 60; //MAX 9223372036854775807

struct edge{
  ll to;
  ll cost,time;
  edge() {}
  edge(ll to, ll cost,ll time) : to(to), cost(cost),time(time){};
};
auto cmp = [](edge a, edge b){
  return a.time > b.time;
};

vector<ll> dijkstra(ll s, vector<vector<edge>> &g,ll ss,ll mx,vector<ll> &c,vector<ll> &d)
{
  priority_queue<edge, vector<edge>, decltype(cmp)> q(cmp);
  vector<vector<ll>> dist(g.size(), vector<ll>(mx+1,INF) );
  if(ss>mx)ss=mx;
  dist[s][ss] = 0;
  q.push({s, ss ,0});

  while (!q.empty())
  {
    auto p = q.top();
    q.pop();

    rep(i, g[p.to].size())
    {
      edge e = g[p.to][i];
      if(e.cost>p.cost)continue;
      if(dist[e.to][p.cost-e.cost]<=p.time+e.time)continue;

      dist[e.to][p.cost-e.cost] = e.time+p.time;
      edge r={e.to,p.cost-e.cost,e.time+p.time};
      q.push(r);
    }


    edge r={p.to,(p.cost+c[p.to]>=mx?mx:p.cost+c[p.to]),p.time+d[p.to]};
    if(dist[p.to][r.cost]>r.time){
      dist[p.to][r.cost]=r.time;
      q.push(r);
    }
  }
  vector<ll> dis(g.size(),0);
  rep(i,g.size())dis[i]=*min_element(dist[i].begin(),dist[i].end());
  return dis;
}

int main()
{
ll n , m , ss ,mx=0;
cin >> n >> m >> ss ;
vector<vector<edge>> g(n);
rep(i, m)
{
  ll a, b, c,d;
  cin >> a >> b >> c >>d;
  mx=max(mx,c);
  g[a-1].emplace_back(b-1, c,d);
  g[b-1].emplace_back(a-1, c,d);
}
vector<ll> c(n,0);
vector<ll> d(n,0);
rep(i,n){
  cin >> c[i] >> d[i] ;
}
mx*=n;
vector<ll> ans = dijkstra(0, g,ss,mx,c,d);
rep(i,n)if(i!=0)cout << ans[i] << endl;
return 0;
}