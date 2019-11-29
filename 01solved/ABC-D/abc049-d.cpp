#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
const ll mo = 1000000007;
const ll INF = 1LL << 60; //MAX 9223372036854775807
ll ans = 0;

struct UnionFind {
  vector<ll> data;
  UnionFind(ll size) : data(size, -1) { }
  bool unionSet(ll x, ll y) {
    x = root(x); y = root(y);
    if (x != y) {
      if (data[y] < data[x]) swap(x, y);
      data[x] += data[y]; data[y] = x;
    }
    return x != y;
  }
  bool findSet(ll x, ll y) {
    return root(x) == root(y);
  }
  ll root(ll x) {
    return data[x] < 0 ? x : data[x] = root(data[x]);
  }
  ll size(ll x) {
    return -data[root(x)];
  }
};

//UnionFind arr(n);で０～n-1バラバラが生成
//arr.findSet(x,y)同じ集合か
//arr.size(x)xが属す要素の個数
//arr.unionSet(x,y)xが属す集合とyが属す集合をマージ
//arr.root(x)
int main()
{
ll n,k,l;
cin >> n>>k>>l;
UnionFind road(n);
rep(i, k){
    ll p,q;
    cin >> p>>q;
    road.unionSet(p-1,q-1);
}
UnionFind rail(n);
rep(i, l){
    ll p,q;
    cin >> p>>q;
    rail.unionSet(p-1,q-1);
}
map<pair<ll,ll>,ll> m{};
rep(i,n){
    m[{road.root(i),rail.root(i)}]+=1;
}
rep(i,n){
    cout << m[{road.root(i),rail.root(i)}]<<" ";
}
cout <<  endl;
return 0;
}
