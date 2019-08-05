#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)

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

struct point {
    ll x,y;
    point() {}
    point(ll x, ll y) : x(x), y(y) {};
};
bool cmp(const point &a, const point &b){
  if(a.x == b.x) return a.y < b.y;
  else return a.x < b.x;
}

int main()
{
vector<ll> x={5,1,200,6000};
vector<ll> y={20,15,15,-500};
Compress< ll > compx(x);//初期化と追加(.add(vector)でもできる)
compx.build();//構築
vector<ll> convertx=compx.get(x);//座標圧縮したものを返す
Compress< ll > compy(y);
compy.build();
vector<ll> converty=compy.get(y);

vector<point> p;
rep(i,x.size()){
  p.emplace_back(convertx[i],converty[i]);
}
sort(p.begin(),p.end(),cmp);
rep(i,p.size()){
  cout << compx[p[i].x] << " " << p[i].x << endl;//[k]圧縮後kの元の値
}
rep(i,p.size()){
  cout << compy[p[i].y] << " " << p[i].y << endl;
}
return 0;
}
