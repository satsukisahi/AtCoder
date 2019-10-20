#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
ll ans = 0;
struct UnionFind
{
  vector<ll> data;
  UnionFind(ll size) : data(size, -1) {}
  bool unionSet(ll x, ll y)
  {
    x = root(x);
    y = root(y);
    if (x != y)
    {
      if (data[y] < data[x])
        swap(x, y);
      data[x] += data[y];
      data[y] = x;
    }
    return x != y;
  }
  bool findSet(ll x, ll y)
  {
    return root(x) == root(y);
  }
  ll root(ll x)
  {
    return data[x] < 0 ? x : data[x] = root(data[x]);
  }
  ll size(ll x)
  {
    return -data[root(x)];
  }
};

int main()
{
  ll n = 6;
  ll x = 2, y = 3;

  UnionFind arr(n);   //0～n-1バラバラが生成
  arr.size(x);        //xが属す要素の個数
  arr.unionSet(x, y); //xが属す集合とyが属す集合をマージ
  arr.findSet(x, y);  //同じ集合か
  arr.root(x);        //根を返す

  return 0;
}
