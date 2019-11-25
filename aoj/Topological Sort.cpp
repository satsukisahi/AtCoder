#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
//http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_4_B&lang=jp
void dfs(ll x, vector<vector<ll>> &g, vector<bool> &see, vector<pair<ll, ll>> &ans, ll &cnt)
{
  see[x] = 1;
  for (auto p : g[x])
  {
    if (see[p])
      continue;
    dfs(p, g, see, ans, cnt);
  }
  ans[x].first = cnt;
  cnt++;
}
int main()
{
ll n, m;
cin >> n >> m;
vector<vector<ll>> g(n);
rep(i, m)
{
  ll a, b;
  cin >> a >> b;
  g[a].push_back(b);
}

ll cnt = 1;
vector<bool> see(n);
vector<pair<ll, ll>> ans(n);
rep(i, n) ans[i].second = i;
rep(i, n)
{
  if (!see[i])
    dfs(i, g, see, ans, cnt);
}
sort(ans.begin(),ans.end());
reverse(ans.begin(),ans.end());
rep(i,n)cout << ans[i].second << endl;
return 0;
}