#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)

//https://atcoder.jp/contests/abc160/tasks/abc160_f
const ll mo = 1000000007;
auto mod = [](ll modx) {modx%=mo;modx+=mo;modx%=mo;return modx; };
auto modmul = [](auto... modx)
{
  ll res = 1;
  for (auto modx_ : {modx...})
  {
    res *= modx_;
    res %= mo;
    res += mo;
    res %= mo;
  }
  return res;
};
ll mypow(ll a, ll b)
{
  ll res = 1;
  a %= mo;
  while (b)
  {
    if (b & 1)
      res = res * a % mo;
    a = a * a % mo;
    b >>= 1;
  }
  return res;
}
vector<ll> fac;
vector<ll> factorial(ll n)
{
  vector<ll> fc;
  fc.push_back(1);
  for (ll i = 1; i < n + 10; i++)
  {
    fc.push_back((fc[i - 1] * i) % mo);
  }
  return fc;
}

void dfs(ll x, vector<vector<ll>> &g, vector<bool> &see, vector<ll> &par, vector<ll> &siz, vector<ll> &childdp)
{
  see[x] = 1;
  ll num = 1, dp = 1;
  for (auto p : g[x])
  {
    if (see[p])continue;
    par[p] = x;
    dfs(p, g, see, par, siz, childdp);
    num += siz[p];
    dp = modmul(dp, childdp[p], mypow(fac[siz[p]], mo - 2));
  }
  siz[x] = num;
  childdp[x] = mod(dp * fac[num - 1]);
}

int main()
{
ll n;
cin >> n;
fac = factorial(n);
vector<ll> ans(n, 0);
vector<vector<ll>> g(n);
rep(i, n - 1)
{
  ll a, b;
  cin >> a >> b;
  g[a - 1].push_back(b - 1);
  g[b - 1].push_back(a - 1);
}

//木dp root=0
vector<bool> see(n, 0);
vector<ll> par(n, -1);
vector<ll> siz(n, 0);
vector<ll> childdp(n, 0);
dfs(0, g, see, par, siz, childdp);
ans[0] = childdp[0];

//bfs順にrerooting
//dfs時のsizなどは書き換わる（書き換えたものは今後子として参照されないため無問題）
queue<ll> q;
for(auto i:g[0])q.push(i);
while (!q.empty())
{
  auto p = q.front();
  q.pop();
  ll num = 1, dp = 1;
  for (auto r : g[p])
  {
    if(r==par[p]){
      //親rが根の時の結果からpが含まれる部分木の寄与分を除き、今の根付き木のr部分木の結果を求める
      num+=siz[r]-siz[p];
      dp = modmul(dp,childdp[r], mypow(fac[siz[r]-1], mo - 2),fac[siz[p]],mypow(childdp[p],mo-2),mypow(siz[r]-siz[p],mo-2));
    }
    else{
      //木dpの結果を利用
      num += siz[r];
      dp = modmul(dp, childdp[r], mypow(fac[siz[r]], mo - 2));
      q.push(r);
    }
  }
  siz[p] = num;
  childdp[p] = mod(dp * fac[num - 1]);
  ans[p]=childdp[p];
}
for(auto r:ans)cout << r << endl;

return 0;
}