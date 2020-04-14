#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
ll ans = 0;
bool cmp(const pair<ll,ll> &a, const pair<ll,ll> &b){
  return a.second > b.second;
}
int main()
{
ll n ;
cin >> n ;
vector<pair<ll,ll>> v,vv;
rep(i,n){
  ll a , b ;
  cin >> a >> b ;
  if(a<b)v.emplace_back(a,b);
  else vv.emplace_back(a,b);
}
sort(v.begin(),v.end());
sort(vv.begin(),vv.end(),cmp);
ll now=0;
rep(i,v.size()){
  now+=v[i].first;
  ans=max(ans,now);
  now-=v[i].second;
}
rep(i,vv.size()){
  now+=vv[i].first;
  ans=max(ans,now);
  now-=vv[i].second;
}
cout << ans << endl;
return 0;
}
