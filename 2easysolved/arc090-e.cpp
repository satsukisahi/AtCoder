#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
ll ans = 0;
const ll mo = 1000000007;
const ll INF = 1LL << 60; //MAX 9223372036854775807

struct edge
{
  ll to;
  ll cost;
  edge() {}
  edge(ll to, ll cost) : to(to), cost(cost){};
};
vector<ll> dijkstra(ll s, vector<vector<edge>> &g, vector<ll> &num)
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
}

int main()
{
  ll n, m;
  cin >> n >> m;
  ll s, t;
  cin >> s >> t;
  s--;
  t--;
  vector<vector<edge>> g(n);
  rep(i, m)
  {
    ll a, b, c;
    cin >> a >> b >> c;
    g[a - 1].emplace_back(b - 1, c);
    g[b - 1].emplace_back(a - 1, c);
  }
  vector<ll> num1(n);
  vector<ll> dist1 = dijkstra(s, g, num1);
  vector<ll> num2(n);
  vector<ll> dist2 = dijkstra(t, g, num2);
  ans += num1[t] * num1[t];
  ans %= mo;
  rep(i, n)
  {
    if (dist1[i] == dist2[i] && dist1[i] * 2 == dist1[t])
    {
      ans -= ((num1[i] * num2[i]) % mo) * ((num1[i] * num2[i]) % mo);
      ans %= mo;
    }
    for (auto a : g[i])
    {
      if (dist1[i] * 2 < dist1[t] && dist1[a.to] * 2 > dist1[t] && dist1[i] + a.cost + dist2[a.to] == dist1[t])
      {
        ans -= ((num1[i] * num2[a.to]) % mo) * ((num1[i] * num2[a.to]) % mo);
        ans %= mo;
      }
    }
  }
  auto mod = [](ll modx) {modx%=mo;modx+=mo;modx%=mo;return modx; };
  cout << mod(ans) << endl;
  return 0;
}