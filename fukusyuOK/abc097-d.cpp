#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)
const ll mo=1000000007;
ll ans=0;
ll dp[0][0];
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
int main()
{
ll n,m;
cin >> n>>m;
ll table[n]={};
rep(i,n) {
    cin >> table[i];
}
UnionFind arr(n);
rep(i,m){
    ll a,b;
    cin >> a>>b;
    arr.unionSet(a-1,b-1);
}
rep(i,n){
    if(arr.findSet(table[i]-1,i))ans++;
}
cout << ans << endl;
return 0;
}