#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
ll ans = 0;

struct UnionFind
{
  vector<ll> data,w;
  UnionFind(ll size) : data(size, -1),w(size,0) {}
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
      w[x]+=w[y];
      w[x]++;
    }
    else 
    { 
      w[x]++;
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

template< typename T >
struct Compress {
  vector< T > xs;

  Compress() = default;

  Compress(const vector< T > &vs) {
    add(vs);
  }

  Compress(const initializer_list< vector< T > > &vs) {
    for(auto &p : vs) add(p);
  }

  void add(const vector< T > &vs) {
    copy(begin(vs), end(vs), back_inserter(xs));
  }

  void add(const T &x) {
    xs.emplace_back(x);
  }

  void build() {
    sort(begin(xs), end(xs));
    xs.erase(unique(begin(xs), end(xs)), end(xs));
  }

  vector< ll > get(const vector< T > &vs) const {
    vector< ll > ret;
    transform(begin(vs), end(vs), back_inserter(ret), [&](const T &x) {
      return lower_bound(begin(xs), end(xs), x) - begin(xs);
    });
    return ret;
  }

  ll get(const T &x) const {
    return lower_bound(begin(xs), end(xs), x) - begin(xs);
  }

  const T &operator[](ll k) const {
    return xs[k];
  }
};


int main()
{
ll n ;
cin >> n ;
vector<ll> a(n);
vector<ll> b(n);
rep(i, n){
  cin >> a[i];
  cin >> b[i];
}
Compress< ll > comp(a);//初期化と追加(.add(vector)でもできる)
comp.add(b);
comp.build();//構築
vector<ll> cona=comp.get(a);//座標圧縮したものを返す
vector<ll> conb=comp.get(b);
UnionFind arr(comp.xs.size());
rep(i,n){
  arr.unionSet(cona[i], conb[i]);
}
set<ll> s;
rep(i,comp.xs.size()){
  if(s.find(arr.root(i))!=s.end())continue;
  else{
    s.insert(arr.root(i));
    ans+=min(arr.size(i),arr.w[arr.root(i)]);
  }
}

cout << ans << endl;
return 0;
}
