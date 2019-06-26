#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define repf(i, a, b) for(ll i = (a); i < (b) ; i++ )
const ll mo = 1000000007;
const ll INF = 1LL << 60; //MAX 9223372036854775807
ll ans = 0;
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
ll n;
cin >> n;
pair<ll, ll> px[n];
pair<ll, ll> py[n];
rep(i, n){
    ll x,y;
    cin >>x>>y;
    px[i].first=x;
    py[i].first=y;
    px[i].second=i;
    py[i].second=i;
}
sort(px,px+n);
sort(py,py+n);
pair<ll, pair<ll,ll>> p[n*2];
rep(i,n-1){
    p[i*2].first=px[i+1].first-px[i].first;
    p[i*2].second.first=(px[i+1].second);
    p[i*2].second.second=(px[i].second);

    p[i*2+1].first=py[i+1].first-py[i].first;
    p[i*2+1].second.first=(py[i+1].second);
    p[i*2+1].second.second=(py[i].second);
}
sort(p,p+2*n);

UnionFind arr(n);
ll cnt=0;
rep(i,2*n){
    if(!arr.findSet(p[i].second.first,p[i].second.second)){
        ans+=p[i].first;
        //cout << p[i].first << endl;
        cnt++;
        arr.unionSet(p[i].second.first,p[i].second.second);
    }
    if(cnt==n-1)break;
}

cout << ans << endl;
return 0;
}