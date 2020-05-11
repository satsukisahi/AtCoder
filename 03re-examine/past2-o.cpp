#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
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
struct edge
{
  ll to;
  ll cost;
  ll num;
  ll from;
  ll l,r;
  edge() {}
  edge(ll to, ll cost,ll num) : to(to), cost(cost),num(num){};
  edge(ll to,ll from, ll cost,ll num) : to(to),from(from), cost(cost),num(num){};
};
bool operator< (const edge &a1, const edge &a2){
    return a1.num < a2.num;
};
bool cmp(const edge &a, const edge &b){
  return a.cost < b.cost; //>なら降順 
}

int main()
{
ll n, m;
cin >> n >> m;
vector<edge> v,vv,vvv;
set<edge> bi[n-1];
rep(i, m)
{
  ll a, b, c;
  cin >> a >> b >> c;
  v.emplace_back(a - 1,b-1, c,i);
}
sort(v.begin(),v.end(),cmp);
UnionFind arr(n);
ll micost=0;
for(auto r:v){
  if(!arr.findSet(r.to, r.from)){
    micost+=r.cost;
    arr.unionSet(r.to, r.from);
    vvv.push_back(r);
  }
  else vv.push_back(r);
}
vector<ll> ans(m,micost);
rep(i,vv.size()){
  vv[i].l=0;
  vv[i].r=n-2;
  bi[(n-2)/2].insert(vv[i]);
}
ll cnt=vv.size();
while(cnt>0){
  UnionFind ar(n);
  rep(i,n-1){
    ar.unionSet(vvv[i].to, vvv[i].from);
    for(auto r:bi[i]){
      if(ar.findSet(r.to, r.from)){
        r.r=i;
        if(r.r-r.l==0){
          ans[r.num]=r.cost+micost-vvv[i].cost;
          cnt--;
          continue;
        }
        bi[(r.r+r.l)/2].insert(r);
      }
      else{
        r.l=i;
        if(r.r-r.l==1){
          ans[r.num]=r.cost+micost-vvv[i+1].cost;
          cnt--;
          continue;
        }
        bi[(r.r+r.l)/2].insert(r);
      }
    }
    bi[i].clear();
  }
}
for(auto an:ans)cout << an << endl;
return 0;
}