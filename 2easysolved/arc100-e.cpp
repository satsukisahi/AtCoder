#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)

int main()
{
ll n ;
cin >> n ;
vector<pair<ll,ll>> v;
vector<ll> vv;
auto f = [&](pair<ll,ll> a,pair<ll,ll> b){
  if(vv[a.first]<vv[b.first])swap(a.first,b.first);
  if(vv[a.first]<vv[b.second])swap(a.first,b.second);
  if(vv[a.second]<vv[b.first])swap(a.second,b.first);
  if(vv[a.second]<vv[b.second])swap(a.second,b.second);
  if(vv[b.first]<vv[b.second])swap(b.first,b.second);
  if(a.first==a.second)swap(a.second,b.first);
  if(a.first==a.second)swap(a.second,b.second);
  return a;
};
rep(i,1LL<<n){
  ll a;
  cin >> a;
  vv.push_back(a);
  v.emplace_back(i,0);
}
rep(i,1LL<<n)rep(j,n){
  if(!(1LL&(i>>j)))v[i|(1LL<<j)]=f(v[i|(1LL<<j)],v[i]);
}
ll mx=0;
rep(i,(1LL<<n) -1){
  mx=max(mx,vv[v[i+1].first]+vv[v[i+1].second]);
  cout << mx << endl;
}
return 0;
}