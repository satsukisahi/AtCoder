#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
const ll mo = 998244353;
const ll INF = 1LL << 60; //MAX 9223372036854775807
auto mod = [](ll modx) {modx%=mo;modx+=mo;modx%=mo;return modx; };
//演算の定義
auto query = [](ll x, ll y) { return max(x, y); };
//単位元
const ll unit =-INF;
struct SegTree
{
  private:
    ll n;
    vector<ll> node;

  public:
    SegTree(vector<ll> v)
    {
      node.resize((1LL << 64 - __builtin_clzll(v.size())) * 2 - 1, unit); //最小値なので残りはINFで埋める
      n = 1LL << 64 - __builtin_clzll(v.size());
      for (ll i = 0; i < v.size(); i++)
        node[i + n - 1] = v[i]; //最下段から構築
      for (ll i = n - 2; i >= 0; i--)
        node[i] = query(node[2 * i + 1], node[2 * i + 2]);
    }

    void update(ll x, ll val)
    {
      x += (n - 1);  // 最下段index
      node[x] = val; //valを加算などするときは+=
      while (x > 0)
      {
        x = (x - 1) / 2;
        node[x] = query(node[2 * x + 1], node[2 * x + 2]);
      }
    }

    // 要求区間 [a, b) 中の要素の最小値を答える k := 自分がいるノードのインデックス 対象区間は [l, r) にあたる
    ll getmin(ll a, ll b, ll k = 0, ll l = 0, ll r = -1)
    {
      // 最初に呼び出されたときの対象区間は [0, n)
      if (r < 0)
        r = n;
      // 要求区間と対象区間が交わらない -> 適当に返す
      if (r <= a || b <= l)
        return unit;
      // 要求区間が対象区間を完全に被覆 -> 対象区間を答えの計算に使う
      if (a <= l && r <= b)
        return node[k];
      // 要求区間が対象区間の一部を被覆 -> 子について探索を行う
      // 左側の子を vl ・ 右側の子を vr としている
      // 新しい対象区間は、現在の対象区間を半分に割ったもの
      ll vl = getmin(a, b, 2 * k + 1, l, (l + r) / 2);
      ll vr = getmin(a, b, 2 * k + 2, (l + r) / 2, r);
      return query(vl, vr);
    }
};
int main()
{
ll n ;
cin >> n ;
vector<pair<ll,ll>> v(n);
vector<ll> dp(n+1);
dp[n]=1;
rep(i,n){
  cin >> v[i].first >> v[i].second;
}
sort(v.begin(),v.end());
vector<ll> t(n,-INF);
t[n-1]=v[n-1].first +v[n-1].second;
SegTree s(t);
rep(i,n){
  dp[n-i-1]=dp[n-i];
  auto itr1 = lower_bound(v.begin(), v.end(), make_pair(v[n-i-1].first +v[n-1-i].second,0LL));
  ll u=itr1-v.begin();
  ll mx=max(v[n-i-1].first +v[n-1-i].second,s.getmin(0, u));
  s.update(n-i-1, mx);
  pair<ll,ll> p={mx ,0};
  auto itr = lower_bound(v.begin(), v.end(), p);
  dp[n-i-1]=mod(dp[n-i-1]+dp[itr-v.begin()]);
}
cout << dp[0] << endl;
return 0;
}