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
ll n , m ;
cin >> n >> m ;
vector<ll> a(n);
rep(i, n){
  cin >> a[i];
}
UnionFind arr(n);
rep(i,m){
  ll x , y ;
  cin >> x >> y ;
  arr.unionSet(x, y);
}
set<ll> syu;
multiset<ll> s[n];
rep(i,n)syu.insert(arr.root(i));
if((syu.size()-1)*2>n){
  cout << "Impossible" << endl;
  return 0;
}
if(syu.size()==1){
  cout << 0 << endl;
  return 0;
}
rep(i,n){
  s[arr.root(i)].insert(a[i]);
}
vector<ll> v;
rep(i,n){
  bool ok=1;
  for(auto r:s[i]){
    if(ok){ans+=r;ok=0;}
    else v.push_back(r);
  }
}
sort(v.begin(),v.end());
rep(i,syu.size()-2){
  ans+=v[i];
}

cout << ans << endl;
return 0;
}