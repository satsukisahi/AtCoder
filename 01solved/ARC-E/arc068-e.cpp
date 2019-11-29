#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
template< typename T >
struct BinaryIndexedTree {
  vector< T > data;

  BinaryIndexedTree(ll sz) {
    data.assign(++sz, 0);
  }

  T sum(ll k) {
    T ret = 0;
    for(++k; k > 0; k -= k & -k) ret += data[k];
    return (ret);
  }

  void add(ll k, T x) {
    for(++k; k < data.size(); k += k & -k) data[k] += x;
  }
};
int main()
{
ll n , m ;
cin >> n >> m ;
vector<ll> ans(m);
vector<vector<ll>> q(m+2);
vector<vector<ll>> f(m+1);
BinaryIndexedTree< ll > b(m+1);
rep(i,n){
  ll l , r ;
  cin >> l >> r ;
  q[l].push_back(l);
  q[r+1].push_back(-l);
}
for (ll i = 1; i <= m; i++)
{
  for (ll j = i; j <= m; j+=i)
  {
    f[j].push_back(i);
  }
}
for (ll i = 1; i <= m; i++)
{
  for(auto t:q[i]){
    if(t>0)b.add(t,1);
    else b.add(-t,-1);
  }
  for(auto t:f[i]){
    ans[t-1]+=b.sum(i)-b.sum(i-t);
    //cout << b.sum(i) << " " << b.sum(i-t) << endl;
  }
}
for(auto an:ans)cout << an << endl;
return 0;
}