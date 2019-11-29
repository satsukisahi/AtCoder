//全国統一プログラミング王予選
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
struct edge
{
  ll to,from;
  ll cost;
  bool ok=0;
  edge() {}
  edge(ll from , ll to, ll cost) : from(from),to(to), cost(cost){};
};
bool cmp(const edge &a, const edge &b){
  return a.cost < b.cost;
}
int main()
{
/* std::ifstream in("input");
std::cin.rdbuf(in.rdbuf()); */
ll n, m;
cin >> n >> m;
vector<ll> sum(n);
rep(i, n){
  cin >> sum[i];
}
vector<edge> g;
vector<vector<pair<ll,ll>>> gg(n);
rep(i, m)
{
  ll a, b, c;
  cin >> a >> b >> c;
  g.emplace_back(a-1,b - 1, c);
  gg[a-1].emplace_back(b-1,c);
  gg[b-1].emplace_back(a-1,c);
}
sort(g.begin(),g.end(),cmp);
UnionFind arr(n);
rep(i,m){
  if(arr.root(g[i].from)==arr.root(g[i].to)){
    if(sum[arr.root(g[i].from)]>=g[i].cost)g[i].ok=1;
  }
  else {
    ll sum1=sum[arr.root(g[i].from)];
    ll sum2=sum[arr.root(g[i].to)];
    arr.unionSet(g[i].from, g[i].to);
    sum[arr.root(g[i].from)]=sum1+sum2;
    if(sum[arr.root(g[i].from)]>=g[i].cost)g[i].ok=1;
  }
}
set<pair<ll,ll>> see;
rep(i,m){
  if(g[m-i-1].ok){
    if(see.find({min(g[m-i-1].to,g[m-i-1].from),max(g[m-i-1].to,g[m-i-1].from)})!=see.end())continue;
    queue<ll> q;
    ll co=g[m-i-1].cost;
    q.push(g[m-i-1].to);
    q.push(g[m-i-1].from);
    ans++;
    see.insert({min(g[m-i-1].to,g[m-i-1].from),max(g[m-i-1].to,g[m-i-1].from)});

    while(!q.empty()){
      ll p=q.front();
      q.pop();
      for(auto r:gg[p]){
        if(see.find({min(r.first,p),max(r.first,p)})!=see.end())continue;
        see.insert({min(r.first,p),max(r.first,p)});
        if(r.second<=co){
          ans++;
          q.push(r.first);
        }
      }
    }
  }
}
cout << m-ans << endl;
return 0;
}