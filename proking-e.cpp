//全国統一プログラミング王予選
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
ll n, m;
cin >> n >> m;
vector<ll> x(n);
rep(i, n){
  cin >> x[i];
}
vector<vector<edge>> g(n);
rep(i, m)
{
  ll a, b, c;
  cin >> a >> b >> c;
  g[a - 1].emplace_back(b - 1, c);
  g[b - 1].emplace_back(a - 1, c); //無向辺
}
cout << ans << endl;
return 0;
}