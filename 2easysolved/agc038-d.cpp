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
ll n , m , q ;
cin >> n >> m >> q ;
vector<vector<ll>> v;
set<ll> s;
set<ll> sss;
UnionFind arr(n);
set<pair<ll,ll>> ss;
rep(i,q){
  ll a , b , c ;
  cin >> a >> b >> c ;
  s.insert(a);
  s.insert(b);
  if(c==0)arr.unionSet(a, b);
  else {
    ss.insert({a,b});
    sss.insert(a);
    sss.insert(b);
    vector<ll> aaa={a,b};
    v.emplace_back(aaa);
  }
}
rep(i,v.size()){
  if(arr.findSet(v[i][0], v[i][1])){
    cout << "No" << endl;
    return 0;
  }
}
ll ko=0;
set<ll> ssss;
rep(i,n){
  ssss.insert(arr.root(i));
}

ll und=n-s.size();
if(ss.size()==1&&und==0){
  cout << "No" << endl;
  return 0;
}
if(ss.size()>=1&&m==n-1){
  cout << "No" << endl;
  return 0;
}
/* if(m>(und+sss.size())*(und+sss.size()-1)/2 -(und+sss.size())+n){
  cout << "No" << endl;
  return 0;
} */
if(m-(n-ssss.size())>(ssss.size()-1)*ssss.size()/2){
  cout << "No" << endl;
  return 0;
}
if(und+sss.size()==0 && m!=n-1){
  cout << "No" << endl;
  return 0;
}
cout << "Yes" << endl;
return 0;
}