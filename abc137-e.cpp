#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
ll ans = 0;
const ll INF = 1LL << 60; //MAX 9223372036854775807

template <typename T>
struct edge
{
  int src, to;
  T cost;

  edge(int to, T cost) : src(-1), to(to), cost(cost) {}

  edge(int src, int to, T cost) : src(src), to(to), cost(cost) {}

  edge &operator=(const int &x)
  {
    to = x;
    return *this;
  }

  operator int() const { return to; }
};

template <typename T>
using Edges = vector<edge<T>>;
template <typename T>
using WeightedGraph = vector<Edges<T>>;
using UnWeightedGraph = vector<vector<int>>;
template <typename T>
using Matrix = vector<vector<T>>;

template <typename T>
vector<T> bellman_ford(Edges<T> &edges, int V, int s)
{
  const auto INF = numeric_limits<T>::max();
  vector<T> dist(V, INF);
  dist[s] = 0;
  for (int i = 0; i < V - 1; i++)
  {
    for (auto &e : edges)
    {
      if (dist[e.src] == INF)
        continue;
      dist[e.to] = min(dist[e.to], dist[e.src] + e.cost);
    }
  }
  for (auto &e : edges)
  {
    if (dist[e.src] == INF)
      continue;
    if (dist[e.src] + e.cost < dist[e.to])
      return vector<T>();
  }
  return dist;
};

int main()
{
  int V, E, p;
  scanf("%d %d %d", &V, &E, &p);
  Edges<int> es;
  Edges<int> ess;
  for (int i = 0; i < E; i++)
  {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    //if(a==b)continue;
    es.emplace_back(a-1, b-1, c);
    ess.emplace_back(b-1, a-1, c);
  }
  auto flont = bellman_ford(es, V, 0);
  auto back = bellman_ford(ess, V, V-1);
  set<ll> ng;
  rep(i,flont.size()){
    if(flont[i]==2147483647)ng.insert(i);
    if(back[i]==2147483647)ng.insert(i);
  }
  Edges<int> si;
  rep(i,es.size()){
    auto ee=es[i];
    if(ng.find(ee.src)==ng.end()&&ng.find(ee.to)==ng.end()){
      si.emplace_back(ee.src, ee.to, -ee.cost+p);
    }
  }
  auto k = bellman_ford(si, V, 0);
  if(k.empty()) {cout << -1 << endl;return 0;}
  if(k[V-1]>0)cout << 0 << endl;
  else cout << k[V-1]*-1 << endl;
  return 0;
}
