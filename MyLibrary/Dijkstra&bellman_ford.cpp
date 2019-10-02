#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
const ll INF = 1LL << 60; //MAX 9223372036854775807
//http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A
struct edge
{
  ll to;
  ll cost;
  edge() {}
  edge(ll to, ll cost) : to(to), cost(cost){};
};

vector<ll> dijkstra(ll s, vector<vector<edge>> &g)
{
  //pair.first=距離,pair.second=点
  priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> q;
  vector<ll> dist(g.size(), INF);
  dist[s] = 0;
  q.push({0, s});

  while (!q.empty())
  {
    pair<ll, ll> p = q.top();
    q.pop();
    ll v = p.second;
    if (dist[v] < p.first)
      continue;
    rep(i, g[v].size())
    {
      edge e = g[v][i];
      if (dist[e.to] > dist[v] + e.cost)
      {
        dist[e.to] = dist[v] + e.cost;
        q.push({dist[e.to], e.to});
      }
    }
  }
  return dist;
}
vector<ll> bellman_ford(ll s, vector<vector<edge>> &g)
{
  //pair.first=距離,pair.second=点
  vector<ll> dist(g.size(), INF);
  dist[s] = 0;
  //頂点数-1回全ての辺を見る操作を繰り返す
  rep(i,g.size()-1){
    rep(j,g.size()){
      if(dist[j]==INF)continue;
      rep(k,g[j].size()){
        dist[g[j][k].to]=min(dist[g[j][k].to],dist[j]+g[j][k].cost);
      }
    }
  }
  //ここで更新があったら負のサイクルがある
  rep(j,g.size()){
    if(dist[j]==INF)continue;
    rep(k,g[j].size()){
      if(dist[g[j][k].to]>dist[j]+g[j][k].cost) return vector<ll>();
    }
  }
  return dist;
}

int main()
{
ll n, m, r;
cin >> n >> m >> r; //頂点数,辺数,始点

vector<vector<edge>> g(n);
rep(i, m)
{
  ll a, b, c;
  cin >> a >> b >> c;
  g[a].emplace_back(b, c);
}

vector<ll> ans = dijkstra(r, g);
for (int i = 0; i < ans.size(); ++i)
{
  if (ans[i] < INF / 2)
    cout << ans[i] << endl;
  else
    cout << "INF" << endl;
}
return 0;
}

//最短の移動経路が何通りかも求めたいとき
/* vector<ll> dijkstra(ll s, vector<vector<edge>> &g, vector<ll> &num)
{
  //pair.first=距離,pair.second=点
  priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> q;
  vector<ll> dist(g.size(), INF);
  dist[s] = 0;
  num[s] = 1;
  q.push({0, s});

  while (!q.empty())
  {
    pair<ll, ll> p = q.top();
    q.pop();
    ll v = p.second;
    if (dist[v] < p.first)
      continue;
    rep(i, g[v].size())
    {
      edge e = g[v][i];
      if (dist[e.to] > dist[v] + e.cost)
      {
        dist[e.to] = dist[v] + e.cost;
        q.push({dist[e.to], e.to});
        num[e.to] = num[v];
      }
      else if (dist[e.to] == dist[v] + e.cost)
      {
        num[e.to] += num[v];
        num[e.to] %= mo;
      }
    }
  }
  return dist;
} */
