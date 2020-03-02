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
int main()
{
ll n , m , k ;
cin >> n >> m >> k ;
set<ll> s[n];
UnionFind arr(n);
vector<ll> cnt(n);
vector<ll> br(n);

rep(i,m){
  ll a , b ;
  cin >> a >> b ;
  arr.unionSet(a-1,b-1);
  cnt[a-1]++;
  cnt[b-1]++;
}
rep(i,k){
  ll a , b ;
  cin >> a >> b ;
  if(arr.findSet(a-1, b-1)){
    br[a-1]++;
    br[b-1]++;
  }
}
rep(i,n){
  cout << arr.size(i)-cnt[i]-br[i]-1 <<" ";
}
cout << endl;
return 0;
}