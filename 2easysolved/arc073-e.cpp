#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
ll ans = 0;

int main()
{
ll n ;
cin >> n ;
vector<pair<ll,ll>> v;
vector<ll> vy;
vector<ll> comp;
rep(i,n){
  ll x , y ;
  cin >> x >>y  ;
  comp.push_back(x);
  comp.push_back(y);
  if(x>y)swap(x,y);
  v.emplace_back(x,y);
  vy.push_back(y);
}
sort(v.begin(),v.end());
sort(vy.begin(),vy.end());
ans=(v[n-1].first-v[0].first)*(vy[n-1]-vy[0]);
sort(comp.begin(), comp.end());
comp.erase(unique(comp.begin(), comp.end()), comp.end());
vector<vector<ll>> q(comp.size()+1);
rep(i,v.size()){
  ll compnum=lower_bound(comp.begin(), comp.end(), v[i].first) - comp.begin();
  q[compnum].push_back(i+1);
  compnum=lower_bound(comp.begin(), comp.end(), v[i].second) - comp.begin();
  q[compnum].push_back(i+1);
}
set<ll> s;
ll en=-1;
vector<bool> buf(n+1);
rep(i,comp.size()){
  while(s.size()!=n && en!=comp.size()-1){
    en++;
    for(auto k:q[en]){
      if(s.find(k)!=s.end())buf[k]=1;
      else s.insert(k);
    }
  }
  if(s.size()==n)ans=min(ans,(vy[n-1]-v[0].first)*(comp[en]-comp[i]));
  for(auto k:q[i]){
    if(buf[k])buf[k]=0;
    else s.erase(k);
  }
}
cout << ans << endl;
return 0;
}