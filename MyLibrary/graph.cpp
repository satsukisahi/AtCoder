#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
struct edge
{
  ll to;
  ll cost;
  edge() {}
  edge(ll to, ll cost) : to(to), cost(cost){};
};

int main()
{
  //隣接リスト
  //重み付き
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
    //辺列挙
    for (ll i = 0; i < n; ++i)
    {
      for (ll j = 0; j < (ll)g[i].size(); ++j)
      {
        cout << "from" << i << "to" << g[i][j].to << "cost" << g[i][j].cost << endl;
      }
    }
  }
  //重みなし
  {
    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> g(n);
    //多重辺がないならsetでもよい（辺を消去したいときなど）この場合はinsert
    //set<ll> g[n];
    rep(i, m)
    {
      ll a, b;
      cin >> a >> b;
      g[a - 1].push_back(b - 1);
      g[b - 1].push_back(a - 1); //無向辺
    }
  }
  return 0;
}
