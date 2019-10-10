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
struct point {
    ll x,y,val;
    point() {}
    point(ll x, ll y, ll val) : x(x), y(y), val(val) {};
};
bool cmp(const point &a, const point &b)
{
  return a.val > b.val;
}
int main()
{
ll n , h , w ;
cin >> n >> h >> w ;
vector<point> v;
rep(i,n){
  ll r , c , a ;
  cin >> r >> c >> a ;
  v.emplace_back(r-1,c-1,a);
}
sort(v.begin(),v.end(),cmp);
vector<bool> ch(h+w); 
UnionFind arr(h+w);
rep(i,n){
  if(arr.findSet(v[i].x, v[i].y+h)){
    if(!ch[arr.root(v[i].x)]){
      ans+=v[i].val;
      ch[arr.root(v[i].x)]=1;
    }
  }
  else{
    bool t=ch[arr.root(v[i].x)]|ch[arr.root(v[i].y+h)];
    bool tt=ch[arr.root(v[i].x)]&ch[arr.root(v[i].y+h)];
    if(tt)continue;
    ans+=v[i].val;
    arr.unionSet(v[i].x, v[i].y+h);
    ch[arr.root(v[i].x)]=t;
  }
}
cout << ans << endl;
return 0;
}