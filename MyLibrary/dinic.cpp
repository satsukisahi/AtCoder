#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
const ll INF = 1LL << 60; //MAX 9223372036854775807
//https://atcoder.jp/contests/arc074/tasks/arc074_d
struct Dinic
{
    struct Edge
    {
      ll from, to;
      ll cap, rev;
      ll To(ll i) const { return from == i ? to : from; }
      ll &Cap(ll i) { return from == i ? cap : rev; }
      ll &Rev(ll i) { return from == i ? rev : cap; }
    };

    ll n;
    vector<Edge> edges;
    vector<vector<ll>> g;
    ll inf;
    Dinic(ll n, ll inf = 1e18) : n(n), g(n), inf(inf) {}
    ll addEdge(ll a, ll b, ll cap, bool undirected = false)
    {
      edges.emplace_back((Edge){a, b, cap, undirected ? cap : 0});
      g[a].emplace_back(edges.size() - 1);
      g[b].emplace_back(edges.size() - 1);
      return edges.size() - 1;
    }
    vector<ll> level;
    vector<size_t> itr;
    ll build(ll s, ll t)
    {
      level.resize(n);
      itr.resize(n);
      ll flow = 0, newflow;
      while (bfs(s), level[t] >= 0)
      {
        itr.assign(n, 0);
        while ((newflow = dfs(s, t, inf)) > 0)
        {
          flow += newflow;
          if (flow >= inf)
            return inf;
        }
      }
      return flow;
    }
    vector<ll> isCut;
    void restoreMinCut(ll s)
    {
      isCut = vector<ll>(edges.size());
      // bfs
      vector<ll> used(n);
      queue<ll> q;
      q.emplace(s);
      used[s] = 1;
      while (q.size())
      {
        ll i = q.front();
        q.pop();
        for (ll idx : g[i])
        {
          Edge &edge = edges[idx];
          if (!used[edge.To(i)] && edge.Cap(i) > 0)
          {
            q.emplace(edge.To(i));
            used[edge.To(i)] = 1;
          }
        }
      }
      for (size_t i = 0; i < edges.size(); i++)
      {
        if (used[edges[i].from] != used[edges[i].to])
          isCut[i] = 1;
      }
    }

  private:
    void bfs(ll s)
    {
      fill(begin(level), end(level), -1);
      queue<ll> q;
      q.emplace(s);
      level[s] = 0;
      while (q.size())
      {
        ll i = q.front();
        q.pop();
        for (ll idx : g[i])
        {
          Edge edge = edges[idx];
          if (level[edge.To(i)] < 0 && edge.Cap(i) > 0)
          {
            level[edge.To(i)] = level[i] + 1;
            q.emplace(edge.To(i));
          }
        }
      }
    }

    ll dfs(ll v, ll t, ll flow)
    {
      if (v == t)
        return flow;
      for (size_t &i = itr[v]; i < g[v].size(); ++i)
      {
        Edge &edge = edges[g[v][i]];
        if (edge.Cap(v) > 0 && level[edge.To(v)] > level[v])
        {
          ll newflow = dfs(edge.To(v), t, min(flow, edge.Cap(v)));
          if (newflow == 0)
            continue;
          edge.Cap(v) -= newflow;
          edge.Rev(v) += newflow;
          return newflow;
        }
      }
      return 0;
    }
};


int main()
{
  //宣言 Dinic g(V);
  //追加 g.addEdge(from,to,cap)
  //結果 g.build(to,from);
  ll h , w ;
  cin >> h >> w ;
  Dinic v(h+w) ;
  ll s,t;
  rep(i,h)rep(j,w){
    char c;
    cin >> c;
    if(c=='o'){v.addEdge(j,i+w,1);v.addEdge(i+w,j,1);}
    else if(c=='S'){v.addEdge(j,i+w,INF);v.addEdge(i+w,j,INF);s=j;}
    else if(c=='T'){v.addEdge(j,i+w,INF);v.addEdge(i+w,j,INF);t=j;}
  }
  ll ans=v.build(s,t);
  if(ans>1e+15)ans=-1;
  cout << ans << endl;
  return 0;
}